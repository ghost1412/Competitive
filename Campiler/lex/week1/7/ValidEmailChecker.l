%{
%}
username [a-z0-9A-Z_]+([.][a-z0-9A-Z_]+)*
domain [a-z0-9A-Z]+([.][a-z0-9A-Z]+)+
%%
{username}[@]{domain} {printf("Valid Email id");};     //username+@domain+
.* {printf("Invalid Email id");};
%%
int main(){
	yylex();
}
