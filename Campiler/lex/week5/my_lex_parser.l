%{
#include<iostream>
#include<stdio.h>
#include<queue>
#include<unordered_map>
#include<string>
#include <fstream>
using namespace std;
queue<string> qu;
string tokens="\0";
int count=0;
unordered_map<string, int> tokenCount;
void reset();
bool E();
bool T();
bool X();
bool Y();
bool K();
bool S();
%}
KEYWORDS int|double|auto|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while
PREPROCESSORS define|include|undef|ifdef|ifndef|if|else|endif|error|pragma
SEPERATOR [{};,()]
ARITHMETIC_OPERATOR [+-/*%^=]
IDENTIFIER ([a-zA-Z_][0-9]*)+|[a-zA-Z_]*
INT [0-9]+
STRING_LITRAL \".*\"
CHAR \'.\'
RELATIONAL_OPERATOR [\<=\>=\<==\>]
BITWISE_OPERATOR [\&\|\^~]|"<<"|">>"
FLOAT {INT}+\.{INT}+
ASSIGNMENT_OPERATOR "+="|"-="|"=="|"*="|"/="|"<<="|">>=" 
INCREMENT_OPERATOR "++"
DECREMENT_OPERATOR "--"
CONDITIONAL_OPERATOR "?"
SPECIAL_OPERATOR "sizeof("

%%								    
{IDENTIFIER} {qu.push("I"); if(tokenCount.find(yytext)==tokenCount.end()){ tokenCount[yytext]=++count; tokens=tokens+"id"+ to_string(tokenCount[yytext]);}else tokens=tokens+"id" + to_string(tokenCount[yytext]);}    			//identifier
\n|\t {if(S()){ cout<< tokens<<"  VALID STATEMENT"<<endl;}else cout<<"INVALID STATEMENT\n"; reset();}								//remove newline
{ARITHMETIC_OPERATOR} {qu.push(yytext); tokens += yytext;}
{INT} {qu.push("I");tokens += "IntConst";} 
[ ]* ;										//remove tab
[()] {qu.push(yytext);}
.
%%
int yywrap()								
{
return 1;
}

void reset(){
	tokens="\0";
	count = 0;
	tokenCount.clear();
}
bool K(){

	if(qu.front()=="("){
		qu.pop();
		if(E()){
			if(qu.front()==")"){
				qu.pop();
				return true;
			}else
				return false;
		}else
			return false;

	}else{
		if(qu.front()=="I"){
			qu.pop();
			return true;
		}else
			return false;
	}

}
bool F(){

	if(K()){
		if(qu.front()=="^"){
			qu.pop();
			if(F()){
				return true;
			}else
				return false;
		}else 
			return true; 
	}else
		return false;
}

bool Y(){

	if(qu.front()=="*"| qu.front()=="/"){
		qu.pop();
		if(F()){
			if(Y()){
				return true;
			}else
				return false;
		}else
			return false;

	}else
		return true;
}

bool X(){
	
	if(qu.front()=="+"| qu.front()=="-"){
		qu.pop();
		if(T()){
			if(X()){
				return true;
			}else
				return false;
		}else
			return false;
	}else
		return true;
	
}

bool T(){

	if(F())
		if(Y())
			return true;
		else
			return false;
	else
		return false;

}

bool E(){

	if(T())
		if(X())
			return true;
		else
			return false;
	else
		return false;
		
}

bool invalid(){
	while(!qu.empty())
		qu.pop();
	return false;
}

bool S(){
	
	if(qu.front()=="I"){
		qu.pop();
		if(qu.front()=="="){
			qu.pop();
			if(E()){
				if(qu.empty()){
					return true;
				}else
					return invalid();
			}else
				return invalid();
		}else
			return invalid();
	}else
		return invalid();

}
int main(int argc, char* argv[]){

if(argc!=2){
	cout<<"INPUT FILE NOT PROVIDED\n";
	return 0;
}
	
FILE* file;
if(!(file = fopen(argv[1], "r"))){
	cout<< "FILE NOT FOUND\n";
	return 0;
}

yyset_in(file);
yylex();
return 0;
}
