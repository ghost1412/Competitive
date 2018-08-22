%{
%}
dot[\.]
ip_format ([0-1]?[0-9]?[0-9])|(([2][5][0-5])|[2][0-4][0-9])	
%%
{ip_format}{dot}{ip_format}{dot}{ip_format}{dot}{ip_format} {printf("O/P IPv4");};	
.* {printf("O/P Invalid");};
%%
int main(){
	yylex();
}
