CC=gcc 
CFLAGS=-Wall

all: a.out

lex.yy.c: hexa.l
	lex hexa.l

a.out: lex.yy.c 
	gcc lex.yy.c -ll

clean : 
	rm lex.yy.c a.out
