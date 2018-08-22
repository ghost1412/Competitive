%{
#include<stdio.h>
%}

%%
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
%%

int main(){
	yyin = fopen("code.c", "r");
	yylex();
	return 0;
}
