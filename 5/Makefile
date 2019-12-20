parser: y.tab.c lex.yy.c 
	cc y.tab.c lex.yy.c -ll -o parser -std=c99

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l


clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser