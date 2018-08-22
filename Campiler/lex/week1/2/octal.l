%{
%}
%%
[0-7]+ {printf("is Octal");};
.* {printf("is not Octal");};
%%
int main(){
	yylex();
}

