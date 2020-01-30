#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "data-structures.h"
#include "symbol-stack.h"
#include "display.h"
#include "add-node.h"
#include "create-code.h"
extern int yylineno;
extern char *yytext;
extern int yylex();

FILE *fp;
LLVMcode *tmp;
int Proc_Term = 0;
int Last_Register = 1;
Cmptype icmptype;
int arity_decl = 0;
int i;
int if_flg;
int Func_Term = 0;


#line 33 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
        int num;
        char ident[MAXLENGTH+1];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 61 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    2,    0,    3,    4,    4,    7,    7,    8,    5,    5,
   10,   10,   11,   11,   12,   16,   17,   12,   14,   13,
   19,   20,   13,   18,   21,   15,   22,   22,    6,   25,
    6,   27,    6,    6,    6,    6,    6,    6,    6,   34,
   23,    1,    1,   36,   38,   39,   41,   24,   40,   42,
   40,   43,   44,   45,   26,   46,   47,   48,   49,   50,
   28,   29,   29,   51,   31,   32,   33,   30,   37,   37,
   37,   37,   37,   37,   35,   35,   54,   35,   35,   35,
   53,   53,   53,   55,   55,   55,   55,   56,   57,   52,
   52,    9,    9,   58,   58,   59,   60,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    1,    4,    0,    0,    9,    1,    4,
    0,    0,    9,    1,    0,    3,    3,    1,    1,    0,
    2,    0,    2,    1,    1,    1,    1,    1,    1,    0,
    4,    1,    2,    3,    0,    0,    0,    8,    0,    0,
    3,    0,    0,    0,    7,    0,    0,    0,    0,    0,
   13,    1,    4,    1,    3,    4,    4,    0,    3,    3,
    3,    3,    3,    3,    1,    2,    0,    3,    3,    3,
    1,    3,    3,    1,    1,    3,    1,    4,    1,    1,
    3,    1,    3,    1,    1,    1,    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,   92,   94,   95,    2,    0,    0,    0,    0,
   12,   13,   14,    0,    0,    0,   24,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    3,   29,    0,    0,
   34,   35,   36,   37,   38,   39,    0,    0,    0,    6,
    0,   93,   21,    0,   16,    0,   28,    0,   56,    0,
    0,    0,    0,    0,   31,   52,   33,   43,    0,   11,
    0,    0,   25,   20,    0,   15,   65,    0,    0,   42,
    0,    0,   77,    0,   85,    0,    0,    0,    0,   81,
   87,    0,    0,    0,    0,   45,    0,    0,    0,    0,
    0,    0,    0,   27,    0,   66,    0,    0,    0,    0,
    0,   67,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   53,   63,    0,   97,    0,   26,    0,
    0,    0,   86,    0,    0,   82,   83,    0,    0,    0,
    0,    0,    0,    0,   46,    0,    0,    0,    0,    0,
   88,    0,   54,    0,    0,   58,   47,    0,   23,   18,
    0,    0,   55,    0,   50,   48,    0,    0,   60,   51,
    0,   61,
};
static const short yydgoto[] = {                          2,
   87,    3,    7,   73,   19,   37,    9,   10,   12,   20,
   21,   22,   23,   30,   74,   75,  130,   28,   72,  128,
  102,   58,   38,   65,   39,   67,   40,   41,   42,   43,
   44,   45,   46,   63,   95,   47,   96,  123,  152,  166,
  162,  168,   97,  146,  158,   79,  150,  161,  167,  171,
   48,   99,   89,  108,   90,   91,   92,   13,   14,   15,
};
static const short yysindex[] = {                      -228,
    0,    0, -245, -246, -213, -204, -197, -190, -171,    0,
 -172, -158,    0,    0,    0,    0, -109, -102, -149, -144,
    0,    0,    0, -213, -142, -204,    0, -230,    0, -227,
 -149, -101, -123,  -89,    0,  -80,    0,    0,  -57,  -53,
    0,    0,    0,    0,    0,    0,  -60,  -56, -190,    0,
  -51,    0,    0, -213,    0, -213,    0, -252,    0,  -66,
  -62,  -62,  -47,  -62,    0,    0,    0,    0,  -62,    0,
  -52, -204,    0,    0, -204,    0,    0, -149,  -46,    0,
 -280, -163,    0,  -62,    0,    0,  -80, -263, -140,    0,
    0,  -31, -115,  -62,  120,    0,  -62, -115, -160,  -33,
 -158, -149, -158,    0,  -62,    0, -140, -163, -186, -163,
 -163,    0, -163, -163,  -62, -115,  -62,  -62,  -62,  -62,
  -62,  -62,  -13,    0,    0,  -62,    0,  -28,    0,  -27,
 -115, -140,    0, -140, -140,    0,    0, -150, -115, -115,
 -115, -115, -115, -115,    0,    2, -115,  -26,  -23,   -8,
    0, -149,    0, -213, -213,    0,    0, -149,    0,    0,
  -62,    7,    0, -115,    0,    0,   15, -149,    0,    0,
 -149,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -187,    0,    0, -239,    0,    0,
  -65,   -9,    0,    0,    0,    0,    0,    0, -244,    0,
    0,    0,    0, -248,    0,    0,    0,    0,    0,    0,
 -234,    0,    0,    0,   99,  -17,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -105, -175,    0,
    0,    0,    0, -162,    0, -162,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -234,    0,    0,
    0,    0,    0,    0,    0, -112,  -78,    0,  -44,    0,
    0,    0,   -6,    0,    0,    0,    0, -134,    0,    0,
    1, -220,    3,    0,    0,    0,  -10,    0,    0,    0,
    0,    0,    0,    0,    0,  -71,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   17,   24,    0,   58,   92,    0,    0,    0, -223, -189,
 -177, -165, -147, -143,    0,    0, -100,    0,    0,    0,
    0,  104,    0, -162, -162,    0,    0,  104,    0,    0,
    0, -257,    0,   30,    0,    0,    0,  104,    0,    0,
  104,    0,
};
static const short yygindex[] = {                         0,
  -19,    0,    0,  284,    0,  -30,    0,  266,  179,    0,
  242,    0,    0,    0,  -54,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -55,    0,  197,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  180,   32,    0,   64,    0,    0,  270,    0,    0,
};
#define YYTABLESIZE 402
static const short yytable[] = {                         36,
   57,   76,   49,  106,   62,   88,   93,   77,    5,  110,
  111,   36,    5,   98,    5,    5,    5,    9,    5,   30,
  112,    9,    5,    5,    9,   68,   32,    9,  109,   30,
   49,    9,    9,   49,   69,   78,   32,    1,  116,    5,
   81,    5,    5,   30,   69,    5,   68,  104,    4,  131,
   32,    9,   53,   68,    9,   55,    6,   54,   36,   98,
   56,  139,  140,  141,  142,  143,  144,   68,   70,    4,
  147,  129,   17,    4,   18,    4,    4,    4,   70,    4,
   72,   10,   36,    4,    4,   10,  110,  111,   10,   11,
   72,   10,   71,   16,    4,   10,   10,  133,    4,  159,
  160,    4,   71,    4,    4,  164,    4,   31,    4,    4,
   74,   32,   25,  107,   73,   10,   24,   33,   10,   84,
   74,  157,   34,  125,   73,    4,  126,  163,   26,   85,
   86,    4,   36,  151,  113,  114,  126,  170,   36,  132,
  172,  134,  135,   49,   35,   42,   42,   42,   36,   90,
   51,   36,   90,   62,   62,   42,   42,  110,  111,   60,
   42,   42,   42,   42,   42,   42,   42,   42,   42,   42,
   89,   42,   42,   42,   42,   42,  136,  137,   42,   84,
   84,   84,   62,   91,   27,   62,   91,   41,   41,   84,
   84,   29,   59,   61,   84,   84,   84,   84,   84,   84,
   84,   84,   84,   84,   62,   84,   64,   84,   84,   84,
   82,   83,   84,   75,   75,   75,   41,   66,   96,   41,
   84,   96,   96,   75,   75,   68,   69,   80,   75,   75,
   85,   86,   75,   75,   75,   75,   75,   75,   71,   75,
  100,   75,   75,   75,   94,  105,   75,   76,   76,   76,
  101,  115,  127,  103,  145,  148,  149,   76,   76,  153,
  156,  154,   76,   76,  155,  165,   76,   76,   76,   76,
   76,   76,  169,   76,   40,   76,   76,   76,    8,   44,
   76,   78,   78,   78,   22,   57,   17,   59,    8,   50,
   70,   78,   78,  124,  138,   52,   78,   78,    0,    0,
   78,   78,   78,   78,   78,   78,    0,   78,    0,   78,
   78,   78,    0,    0,   78,   79,   79,   79,    0,    0,
    0,    0,    0,    0,    0,   79,   79,    0,    0,    0,
   79,   79,    0,    0,   79,   79,   79,   79,   79,   79,
    0,   79,    0,   79,   79,   79,    0,    0,   79,   80,
   80,   80,    0,    0,    0,    0,    0,   64,   64,   80,
   80,    0,   68,   68,   80,   80,    0,   30,   80,   80,
   80,   80,   80,   80,   32,   80,    0,   80,   80,   80,
    0,   64,   80,   42,    0,    0,   64,    0,    0,   64,
   42,   68,  110,  111,   68,    0,  117,  118,  119,  120,
  121,  122,
};
static const short yycheck[] = {                         19,
   31,   56,  260,  284,  285,   61,   62,  260,  257,  273,
  274,   31,  261,   69,  263,  264,  265,  257,  267,  264,
  284,  261,  271,  272,  264,  260,  271,  267,   84,  264,
  288,  271,  272,  291,  258,  288,  271,  266,   94,  288,
   60,  288,  291,  264,  268,  294,  291,   78,  294,  105,
  271,  291,  283,  288,  294,  283,  270,  288,   78,  115,
  288,  117,  118,  119,  120,  121,  122,  288,  258,  257,
  126,  102,  263,  261,  265,  263,  264,  265,  268,  267,
  258,  257,  102,  271,  272,  261,  273,  274,  264,  294,
  268,  267,  258,  291,  257,  271,  272,  284,  261,  154,
  155,  264,  268,  291,  267,  161,  294,  257,  271,  272,
  258,  261,  285,   82,  258,  291,  288,  267,  294,  283,
  268,  152,  272,  284,  268,  288,  287,  158,  287,  293,
  294,  294,  152,  284,  275,  276,  287,  168,  158,  108,
  171,  110,  111,  288,  294,  258,  259,  260,  168,  284,
  293,  171,  287,  259,  260,  268,  269,  273,  274,  283,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  287,  288,  113,  114,  291,  258,
  259,  260,  288,  284,  294,  291,  287,  259,  260,  268,
  269,  294,  294,  283,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  285,  284,  264,  286,  287,  288,
  273,  274,  291,  258,  259,  260,  288,  271,  284,  291,
  283,  287,  288,  268,  269,  286,  283,  294,  273,  274,
  293,  294,  277,  278,  279,  280,  281,  282,  290,  284,
  293,  286,  287,  288,  292,  292,  291,  258,  259,  260,
   72,  283,  286,   75,  268,  284,  284,  268,  269,  258,
  269,  288,  273,  274,  288,  259,  277,  278,  279,  280,
  281,  282,  258,  284,  292,  286,  287,  288,  288,  286,
  291,  258,  259,  260,  284,  269,  284,  258,    5,   24,
   49,  268,  269,   97,  115,   26,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,  286,
  287,  288,   -1,   -1,  291,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,   -1,  286,  287,  288,   -1,   -1,  291,  258,
  259,  260,   -1,   -1,   -1,   -1,   -1,  259,  260,  268,
  269,   -1,  259,  260,  273,  274,   -1,  264,  277,  278,
  279,  280,  281,  282,  271,  284,   -1,  286,  287,  288,
   -1,  283,  291,  285,   -1,   -1,  288,   -1,   -1,  291,
  292,  288,  273,  274,  291,   -1,  277,  278,  279,  280,
  281,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
static const char *yyrule[] = {
"$accept : program",
"$$1 :",
"program : PROGRAM $$1 IDENT SEMICOLON outblock PERIOD",
"outblock : var_decl_part subprog_decl_part statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part :",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"subprog_decl : func_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"$$2 :",
"$$3 :",
"proc_decl : PROCEDURE proc_name LPAREN $$2 id_list $$3 RPAREN SEMICOLON inblock",
"proc_name : IDENT",
"func_decl : FUNCTION func_name SEMICOLON inblock",
"$$4 :",
"$$5 :",
"func_decl : FUNCTION func_name LPAREN $$4 id_list $$5 RPAREN SEMICOLON inblock",
"func_name : IDENT",
"$$6 :",
"inblock : var_decl_part $$6 statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"$$7 :",
"statement : $$7 if_statement",
"$$8 :",
"statement : $$8 while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$9 :",
"assignment_statement : variable $$9 ASSIGN expression",
"variable : IDENT",
"variable : indexed_variable RBRACKET",
"indexed_variable : variable LBRACKET expression",
"$$10 :",
"$$11 :",
"$$12 :",
"if_statement : IF condition $$10 THEN $$11 statement $$12 else_statement",
"else_statement :",
"$$13 :",
"else_statement : ELSE $$13 statement",
"$$14 :",
"$$15 :",
"$$16 :",
"while_statement : WHILE $$14 condition $$15 DO $$16 statement",
"$$17 :",
"$$18 :",
"$$19 :",
"$$20 :",
"$$21 :",
"for_statement : FOR IDENT $$17 ASSIGN expression $$18 TO $$19 expression $$20 DO $$21 statement",
"proc_call_statement : proc_call_name",
"proc_call_statement : proc_call_name LPAREN arg_list RPAREN",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN variable RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"$$22 :",
"expression : MINUS $$22 term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : variable",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"factor : func_call",
"func_call : func_call_name LPAREN arg_list RPAREN",
"func_call_name : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : var_id",
"id_list : id_list COMMA var_id",
"var_id : id_var",
"var_id : id_array",
"id_var : IDENT",
"id_array : IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 707 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 483 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 57 "parser.y"
	{init_fstack();}
break;
case 2:
#line 58 "parser.y"
	{
                Factor retval;
                retval.type = CONSTANT;
                retval.cal = 0;
                factorpush(retval);
                create_llvmcode(Ret);
                char fname[256];
                strcpy(fname, "result.ll");
                fp = fopen(fname, "wb");
                fprintf(fp,"@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");
                fprintf(fp, "@.str.1 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n");
                fprintf(fp, "declare i32 @__isoc99_scanf(i8*, ...)\n");
                fprintf(fp, "declare i32 @printf(i8*, ...)\n");
                if(global_decl != NULL ) {displayLlvmcodes(global_decl->codes);
                fprintf(fp,"\n");}
                displayLlvmfundecl(declhd);
                __del__();
                fclose(fp);
        }
break;
case 9:
#line 99 "parser.y"
	{
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , "main");
                tmp->codes = NULL;
                declhd = decltl = tmp;
                codehd = codetl = NULL;
                Factor ftmp;
                ftmp.type = LOCAL_VAR;
                ftmp.cal = Last_Register;
                ftmp.off = 0;
                ftmp.fin = 0;
                factorpush(ftmp);
                Last_Register++;
                create_llvmcode(Alloca);
                factorpush(ftmp);
                Factor f1tmp;
                f1tmp.type = CONSTANT;
                f1tmp.cal = 0;
                factorpush(f1tmp);
                create_llvmcode(Store);
        }
break;
case 10:
#line 122 "parser.y"
	{
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , "main");
                tmp->codes = NULL;
                decltl->next = tmp;
                decltl = tmp;
                codehd = codetl = NULL;
                Factor ftmp;
                ftmp.type = LOCAL_VAR;
                ftmp.cal = Last_Register;
                ftmp.off = 0;
                ftmp.fin = 0;
                factorpush(ftmp);
                Last_Register++;
                create_llvmcode(Alloca);
                factorpush(ftmp);
                Factor f1tmp;
                f1tmp.type = CONSTANT;
                f1tmp.cal = 0;
                factorpush(f1tmp);
                create_llvmcode(Store);
        }
break;
case 13:
#line 154 "parser.y"
	{
                delete(); 
                Proc_Term--;
                Factor retval;
                strcpy(retval.val,"void");
                factorpush(retval);
                create_llvmcode(Ret);
        }
break;
case 14:
#line 163 "parser.y"
	{
                Factor tmp, arg1;
                tmp = lookup(decltl->fname);
                arg1.type = LOCAL_VAR;
                arg1.cal = tmp.ret;
                arg1.off = 0;
                arg1.fin = 0;
                factorpush(arg1);
                create_llvmcode(Load);
                create_llvmcode(Ret);                
                delete(); 
                Proc_Term--;
                Func_Term--;
        }
break;
case 16:
#line 181 "parser.y"
	{arity_decl=1;}
break;
case 17:
#line 181 "parser.y"
	{arity_decl=0;}
break;
case 19:
#line 186 "parser.y"
	{ 
                insert(yystack.l_mark[0].ident, 2);
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , yystack.l_mark[0].ident);
                tmp->codes = NULL;
                tmp->arity = 0;
                tmp->rettype = vo;
                if (declhd == NULL) declhd = tmp;
                if (decltl != NULL) decltl->next = tmp;
                decltl = tmp; 
                codetl = NULL;
                Proc_Term++;
        }
break;
case 21:
#line 204 "parser.y"
	{arity_decl=1;}
break;
case 22:
#line 204 "parser.y"
	{arity_decl=0;}
break;
case 24:
#line 208 "parser.y"
	{
                insert(yystack.l_mark[0].ident, 2);
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , yystack.l_mark[0].ident);
                tmp->codes = NULL;
                tmp->arity = 0;
                tmp->rettype = I32;
                if (declhd == NULL) declhd = tmp;
                if (decltl != NULL) decltl->next = tmp;
                decltl = tmp; 
                codetl = NULL;
                Proc_Term++;
                Func_Term++;
                Factor f_tmp;
                f_tmp.type = LOCAL_VAR;
                f_tmp.cal = Last_Register++;
                f_tmp.fin = 0;
                f_tmp.off = 0;
                factorpush(f_tmp);
                create_llvmcode(Alloca);
        }
break;
case 25:
#line 232 "parser.y"
	{Arity_Alloca();}
break;
case 30:
#line 244 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 31:
#line 250 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->end = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 32:
#line 257 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
                
        }
break;
case 33:
#line 269 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 34:
#line 278 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 35:
#line 285 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; 
                Factor arg;
                for (i = 0; i < 11;i++){
                        arg = factorpop();
                        if(arg.type == PROC_NAME){
                                break;
                        }
                        (tmp->args).call.args[i] = arg;
                }
                (tmp->args).call.arity = i;
                (tmp->args).call.proc = arg;
                (tmp->args).call.rettype = vo;
                add_llvmnode(tmp);
        }
break;
case 40:
#line 310 "parser.y"
	{
                Factor f_tmp;
                f_tmp = factorpop();
                if(f_tmp.type == PROC_NAME){
                        f_tmp.type = LOCAL_VAR;
                        f_tmp.cal = f_tmp.ret;
                }
                factorpush(f_tmp);
        }
break;
case 41:
#line 320 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 42:
#line 327 "parser.y"
	{
                Factor f_tmp;
                f_tmp = lookup(yystack.l_mark[0].ident);
                factorpush(f_tmp);
                yyval.num = f_tmp.off;
        }
break;
case 43:
#line 334 "parser.y"
	{
                create_llvmcode(GetElem);
        }
break;
case 44:
#line 342 "parser.y"
	{
                Factor f_tmp;
                f_tmp.type = CONSTANT;
                f_tmp.cal = yystack.l_mark[-2].num;
                factorpush(f_tmp);
                create_llvmcode(Sub);
                create_llvmcode(Sext);
        }
break;
case 45:
#line 355 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 46:
#line 359 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 47:
#line 364 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 48:
#line 368 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 50:
#line 380 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 52:
#line 393 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 53:
#line 398 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 54:
#line 401 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 55:
#line 405 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; 
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 56:
#line 417 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 57:
#line 421 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 58:
#line 425 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
                br_tmp->cond = Last_Register;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
                create_llvmcode(Label);
                Last_Register++;
                factorpush(lookup(yystack.l_mark[-5].ident));
                create_llvmcode(Load);
        }
break;
case 59:
#line 441 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 60:
#line 446 "parser.y"
	{
                create_llvmcode(BrCond);
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 61:
#line 452 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
                factorpush(lookup(yystack.l_mark[-11].ident));
                factorpush(lookup(yystack.l_mark[-11].ident));
                create_llvmcode(Load);
                Factor arg2; 
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
                create_llvmcode(Store);
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; 
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 64:
#line 484 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 66:
#line 494 "parser.y"
	{
                Factor proc, arg1, retval; 
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; 
                arg1 = factorpop();/*スタックから第2引数をポップ*/
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register;
                Last_Register ++;
                strcpy(proc.val, "read");
                (tmp->args).call.proc = proc;
                (tmp->args).call.args[0] = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).call.retval = retval; /* 命令の第 2 引数を指定 */
                (tmp->args).call.rettype = I32;
                add_llvmnode(tmp);
        }
break;
case 67:
#line 514 "parser.y"
	{
                Factor proc, arg1, retval; 
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; 
                arg1 = factorpop();/*スタックから第2引数をポップ*/
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register;
                Last_Register ++;
                strcpy(proc.val, "write");
                (tmp->args).call.proc = proc;
                (tmp->args).call.args[0] = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).call.retval = retval; /* 命令の第 2 引数を指定 */
                (tmp->args).call.rettype = I32;
                add_llvmnode(tmp);
        }
break;
case 69:
#line 538 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 70:
#line 543 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 71:
#line 548 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 72:
#line 553 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 73:
#line 558 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 74:
#line 563 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 77:
#line 573 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 78:
#line 580 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 79:
#line 584 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 80:
#line 588 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 82:
#line 596 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 83:
#line 601 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 84:
#line 608 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 85:
#line 612 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 87:
#line 621 "parser.y"
	{       
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; 
                Factor arg;
                for (i = 0; i < 11;i++){
                        arg = factorpop();
                        if(arg.type == PROC_NAME){
                                break;
                        }
                        (tmp->args).call.args[i] = arg;
                }
                (tmp->args).call.arity = i;
                (tmp->args).call.proc = arg;
                (tmp->args).call.rettype = I32;
                Factor retval;
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register++;
                (tmp->args).call.retval = retval;
                add_llvmnode(tmp);
                factorpush(retval);
        }
break;
case 89:
#line 650 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 96:
#line 671 "parser.y"
	{ 
                if(arity_decl==1)decltl->arity++;
                factorpush(insert(yystack.l_mark[0].ident, 0)); 
                switch(Proc_Term){
                        case GLOBAL_VAR:
                                create_llvmcode(Global);
                                break;
                        case LOCAL_VAR:
                                create_llvmcode(Alloca);
                                break;
                }
        }
break;
case 97:
#line 687 "parser.y"
	{ 
                if(arity_decl==1)decltl->arity++;
                Factor f_tmp;
                f_tmp = insert(yystack.l_mark[-5].ident, 0);
                f_tmp.off = yystack.l_mark[-3].num;
                f_tmp.fin = yystack.l_mark[-1].num;
                Stack_tl->fin = yystack.l_mark[-1].num;
                Stack_tl->off = yystack.l_mark[-3].num;
                factorpush(f_tmp); 
                switch(Proc_Term){
                        case GLOBAL_VAR:
                                create_llvmcode(Global);
                                break;
                        case LOCAL_VAR:
                                create_llvmcode(Alloca);
                                break;
                }
        }
break;
#line 1319 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
