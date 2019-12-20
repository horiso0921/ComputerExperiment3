parser: y.tab.c lex.yy.c 
	cc lex.yy.c y.tab.c  -ll -o parser -std=c99
# cc (GCC) 4.8.5 20150623 (Red Hat 4.8.5-36)
# Copyright (C) 2015 Free Software Foundation, Inc.

y.tab.c: parser.y
	yacc -d parser.y
# yacc - 1.9 20130304

lex.yy.c: scanner.l
	lex scanner.l
# lex 2.5.37

clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser