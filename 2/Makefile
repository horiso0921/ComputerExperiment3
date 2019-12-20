
ALL:
	yacc -d parser.y
	lex scanner.l
	cc y.tab.c lex.yy.c -ll -o parser

clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser