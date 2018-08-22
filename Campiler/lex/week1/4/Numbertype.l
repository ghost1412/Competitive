%{
%}
number[0-9]
%%

[+]?{number}+ {printf("Positive Integer");};
[-]{number}+ {printf("Negetive Integer");};
[-+]?{number}+[eE][-+]?{number}+ {printf("Integer with Exponent");};
[-+]?{number}+\.{number}+ {printf("Real Number");};
[-+]?{number}+\.{number}+[eE][-+]?{number}+ { printf("Real with Exponent Form");};

.* { printf("Invalid Input");};

%%
int main(){
    yylex();
}


