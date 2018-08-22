%{
%}
%%
([0-7]|[a-f][A-F])+ {printf("is Hexa");};
.* {printf("is not Hexa");};
%%
int main(){
	yylex();
}

