#include<iostream>
#include<cctype>
#include<string>
#include<map>

using namespace std;

double expr(bool get);
double term(bool get);
double prim(bool get);
double error(const string &s);


enum Token_value{
    NAME,NUMBER,END,PLUS='+',MINUS='-',MUL='*',DIV='/',PRINT=';',ASSIGN='=',LP='(',RP=')'
};

Token_value get_token();
Token_value curr_tok=PRINT;

map<string,double> table;
double no_of_error=0;

double expr(bool get){
    double left=term(get);
    for(;;){
        switch(curr_tok){
            case PLUS:
                left+=term(true);
                return left;
                break;
            case MINUS:
                left-=term(true);
                return left;
                break;
            default:
                return left;
        }
    }
}

double term(bool get){
    double left=prim(get);
    for(;;){
        switch(curr_tok){
            case MUL:
                left*=prim(true);
                return left;
                break;
            case DIV:
                if(double d=prim(true)){
                    left/=d;
                    return left;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}

double error(const string &s){
    ++no_of_error;
    cerr<<"error "<<s<<'\n';
    return 1;
}

double number_value;
string string_value;
double prim(bool get){
    if(get)get_token();
    double v,e;
    switch(curr_tok){
        case NUMBER:
            v=number_value;
            get_token();
            return v;
        case NAME:
            v=table[string_value];
            if(get_token()==ASSIGN){
                v=expr(true);
            }
            return v;
        case MINUS:
            return -prim(true);
        case LP:
            e=expr(true);
            if(curr_tok!=RP)return error(")");
            get_token();
            return e;
        default: return error("primary expected");
    }
}

Token_value get_token(){
    char ch=0;
    cin>>ch;
    switch(ch){
        case '$':return curr_tok=END;
        case ';':case '*':case '/':case '+':
        case '-':case '(':case ')':case '=':
            return curr_tok=Token_value(ch);
        case '0':case '1':case '2':case '3':case '4':case '5':
        case '6':case '7':case '8':case '9':case '.':
            cin.putback(ch);
            cin>>number_value;
            return curr_tok=NUMBER;
        default:
            if(isalpha(ch)){
                string_value=ch;
                while(cin.get(ch)&&isalnum(ch))string_value.push_back(ch);
                cin.putback(ch);
                return curr_tok=NAME;
            }
            error("bad token");
            return curr_tok=PRINT;
    }
}

int main(){
    cout<<"to quit type $"<<endl;
    table["pi"]=3.14;
    table["e"]=2.7;
    while(cin){
        cout<<"start"<<endl;
        get_token();
        if(curr_tok==END)break;
        if(curr_tok==PRINT)continue;
        double left=expr(false);
        cout<<"Evaluation is = "<<left<<endl;
        cout<<"table value is = "<<table[string_value]<<endl;
    }
    cout<<"Number of errors "<<no_of_error<<endl;
    return no_of_error;
}
