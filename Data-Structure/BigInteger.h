#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace
{
    char toChar(char d) {
        return d | 0x30;
    }
}

constexpr unsigned Base = 100;

class BigNumber
{
private:
    string m_num;

public:
    BigNumber(int num = 0);
    BigNumber(const BigNumber & other);
    BigNumber(BigNumber && other);
    BigNumber &operator+=(const BigNumber & num2);
    void swap(BigNumber &num);

    BigNumber &operator=(BigNumber num);

    friend BigNumber operator*(const BigNumber & num1, const BigNumber & num2);
    friend BigNumber operator+(BigNumber num1, const BigNumber & num2);
    friend ostream & operator<<(ostream & outstream, const BigNumber & num);

private:
    void add(const BigNumber &num, int exp);
};

BigNumber::BigNumber(int num)
{
    for (; num; num /= Base) {
        m_num.push_back(num % Base);
    }
    if (m_num.empty()) {
        m_num.push_back(0);
    }
}

BigNumber::BigNumber(const BigNumber & other)
    : m_num(other.m_num)
{ }

BigNumber::BigNumber(BigNumber && other)
    : m_num(std::move(other.m_num))
{ }

BigNumber operator*(const BigNumber & num1, const BigNumber & num2)
{
    BigNumber precomp[Base];
    for (int i = 1; i < Base; ++i) {
        precomp[i] = precomp[i - 1] + num1;
    }

    BigNumber result;
    int exp = 0;
    for_each(num2.m_num.begin(), num2.m_num.end(), [&result, &precomp, &exp](char c) {
        result.add(precomp[c], exp++);
    });
    return result;
}

void BigNumber::add(const BigNumber & num, int exp)
{
    if (exp > m_num.size()) {
        m_num.append(exp - m_num.size(), 0).append(num.m_num.begin(), num.m_num.end());
    } else {
        auto b1 = m_num.begin() + exp, e1 = m_num.end();
        auto b2 = num.m_num.begin(), e2 = num.m_num.end();

        int r = 0;
        for (; b1 != e1 && b2 != e2; ++b1, ++b2, r/= Base) {
            r += *b1 + *b2;
            *b1 = r % Base;
        }

        for (; r && b1 != e1; ++b1, r /= Base) {
            r += *b1;
            *b1 = r % Base;
        }

        for (; r && b2 != e2; ++b2, r /= Base) {
            r += *b2;
            m_num.push_back(r % Base);
        }

        if (b2 != e2) {
            m_num.append(b2, e2);
        }

        if (r) {
            m_num.push_back(r);
        }
    }
}

BigNumber &BigNumber::operator+=(const BigNumber & num2)
{
    add(num2, 0);
    return *this;
}

BigNumber operator+(BigNumber num1, const BigNumber & num2)
{
    num1.add(num2, 0);
    return num1;
}

ostream & operator<<(ostream & outstream, const BigNumber & num)
{
    string x(num.m_num.size() * 2, 0);
    for (int i = 0; i < num.m_num.size(); ++i) {
        auto d = num.m_num[i];
        x[2 * i] = toChar(d % 10);
        x[2 * i + 1] = toChar(d / 10);
    }
    if (x.back() == '0') {
        x.erase(x.size() - 1);
    }
    reverse(x.begin(), x.end());
    return outstream << x;
}

BigNumber & BigNumber::operator=(BigNumber num) {
    m_num = std::move(num.m_num);
    return *this;
}

void BigNumber::swap(BigNumber & num)
{
    m_num.swap(num.m_num);
}
