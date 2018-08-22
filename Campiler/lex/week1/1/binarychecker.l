%{
%}
number[0-1]				
%%
[{number}]+ {printf("is Binary");};
.* {printf("is not Binary");};
%%
int main(){
	yylex();
}

