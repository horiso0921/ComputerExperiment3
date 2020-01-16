parser: y.tab.c lex.yy.c data-structures.h symbol-stack.h display.h add-node.h create-code.h
	cc lex.yy.c y.tab.c -ll -o parser -std=c99

y.tab.c: parser.y
	yacc -v parser.y

lex.yy.c: scanner.l
	lex scanner.l


clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser