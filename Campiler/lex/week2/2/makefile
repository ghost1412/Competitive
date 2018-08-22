CC=gcc 
CFLAGS=-Wall
all: a.out

lex.yy.c: 2.l
	lex 2.l

a.out: lex.yy.c 
	gcc lex.yy.c -ll

clean : 
	rm lex.yy.c a.out
