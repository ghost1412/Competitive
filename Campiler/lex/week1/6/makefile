CC=gcc 
CFLAGS=-Wall

all: a.out

lex.yy.c: pass.l
	lex pass.l

a.out: lex.yy.c 
	gcc lex.yy.c -ll

clean : 
	rm lex.yy.c a.out
