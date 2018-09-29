all: my_lex_parser
my_lex_parser: lex.yy.c
	g++ lex.yy.c -ll -o my_lex_parser
lex.yy.c: my_lex_parser.l
	lex my_lex_parser.l
clean : 
	rm lex.yy.c my_lex_parser
