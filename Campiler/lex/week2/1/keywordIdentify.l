%{
_Bool lenghtOfIdentifier(char*);
%}
preprocessors define|include|undef|ifdef|ifndef|if|else|endif|error|pragma
%%

int|double|auto|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while {printf("keyword");}

#{preprocessors} {printf("preprocessors");}

[a-zA-Z]([a-zA-Z]|[0-9])* {if(lenghtOfIdentifier(yytext)){printf("identifier");}else printf("invalid");}
.* {printf("invalid");}

%%

_Bool lenghtOfIdentifier(char* yytext){
	if(sizeof(yytext)<=255){
		return 1;
	}
}

int main(){

	yylex();
	return 0;
}
