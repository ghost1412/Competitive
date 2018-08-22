#include<iostream>
using namespace std;
#include <vector>
#include<bits/stdc++.h>
#include <string.h>
bool isSmaller(string str1, string str2){
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
       return true;
    if (n2 < n1)
       return false;

    for (int i=0; i<n1; i++)
       if (str1[i] < str2[i])
          return true;
       else if (str1[i] > str2[i])
          return false;

    return false;
}
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;
 
    // Initially take carry zero
    int carry = 0;
 
    // Traverse from end of both strings
    for (int i=n2-1; i>=0; i--)
    {
        // Do school mathematics, compute difference of
        // current digits and carry
        int sub = ((str1[i+diff]-'0') -
                   (str2[i]-'0') -
                   carry);
        if (sub < 0)
        {
            sub = sub+10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of str1[]
    for (int i=n1-n2-1; i>=0; i--)
    {
        if (str1[i]=='0' && carry)
        {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i]-'0') - carry);
        if (i>0 || sub>0) // remove preceding 0's
            str.push_back(sub+'0');
        carry = 0;
 
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
string multiply(string num1, string num2){
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
    vector<int> result(n1 + n2, 0);
    int i_n1 = 0;
    int i_n2 = 0;

    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j=n2-1; j>=0; j--)
        {

            int n2 = num2[j] - '0';

            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
	}
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
    if (i == -1)
       return "0";
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}
string longDivision(string number, int divisor){
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx)
    {
        ans += (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}
int mod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;

    return res;
}
unsigned long long sum(string k){
    int n=mod(k,9);
	if (n == 0) return 0;
	else return (n % 9 == 0) ? 9 : (n % 9);
}

string expo(string x,string n){
	string f="1";
	while(isSmaller(n,0)){
		if(mod(n,2)==1)
    		f=multiply(f,x);
            x=multiply(x,x);
            n=longDivision(n,2);
        }
    return f;
}
