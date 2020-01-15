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
    1,    0,    2,    3,    3,    6,    6,    7,    4,    4,
    9,    9,   10,   10,   11,   15,   16,   11,   13,   12,
   18,   19,   12,   17,   20,   14,   21,   21,    5,   24,
    5,   26,    5,    5,    5,    5,    5,    5,    5,   33,
   22,   36,   37,   23,   38,   39,   38,   40,   41,   42,
   25,   43,   44,   45,   46,   47,   48,   49,   50,   51,
   52,   53,   54,   55,   27,   28,   28,   56,   30,   58,
   31,   32,   29,   35,   35,   35,   35,   35,   35,   34,
   34,   60,   34,   34,   34,   59,   59,   59,   61,   61,
   61,   61,   63,   64,   62,   57,   57,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    1,    4,    0,    0,    9,    1,    4,
    0,    0,    9,    1,    0,    3,    3,    1,    1,    0,
    2,    0,    2,    1,    1,    1,    1,    1,    1,    0,
    4,    0,    0,    7,    0,    0,    3,    0,    0,    0,
    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,    1,    4,    1,    3,    0,
    5,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    0,    3,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    4,    1,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   98,    0,    2,    0,    0,    0,    0,   12,   13,   14,
    0,    0,   24,    0,   19,    0,    0,    0,    0,    0,
    0,    3,   29,    0,    0,   34,   35,   36,   37,   38,
   39,    0,    0,    6,   99,   21,    0,   16,    0,   28,
    0,   52,    0,    0,    0,    0,   31,   48,   33,    0,
   11,    0,   25,   20,    0,   15,   69,    0,    0,   70,
    0,   82,    0,   90,    0,    0,    0,   86,   89,   92,
    0,    0,    0,   42,    0,    0,    0,    0,    0,    0,
   27,    0,    0,    0,    0,    0,    0,    0,   72,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,   67,    0,    0,   26,    0,    0,   71,    0,   91,
    0,    0,   87,   88,    0,    0,    0,    0,    0,    0,
    0,   43,    0,    0,    0,    0,    0,   93,    0,   50,
    0,    0,   54,    0,    0,   23,   18,   55,   46,   44,
   51,   56,    0,    0,   47,    0,    0,   58,   59,    0,
   60,   61,   62,   63,   64,   65,
};
static const short yydgoto[] = {                          2,
    3,    7,   63,   16,   32,    9,   10,   12,   17,   18,
   19,   20,   26,   64,   65,  116,   24,   62,  114,   89,
   51,   33,   57,   34,   59,   35,   36,   37,   38,   39,
   40,   41,   55,   83,   84,  110,  139,  150,  153,   85,
  133,  145,   69,  137,  148,  152,  154,  157,  159,  160,
  162,  163,  164,  165,  166,   42,   87,   93,   77,   95,
   78,   79,   80,   81,
};
static const short yysindex[] = {                      -244,
    0,    0, -289, -276, -220, -237, -221,  -75, -202,    0,
    0, -197,    0, -179, -171, -236, -191,    0,    0,    0,
 -220, -160,    0, -147,    0,  -59, -236, -152, -145, -108,
    0,    0,    0,  -62,  -49,    0,    0,    0,    0,    0,
    0, -107,  -75,    0,    0,    0, -220,    0, -220,    0,
 -254,    0,  -84, -166,  -55, -166,    0,    0,    0, -166,
    0, -237,    0,    0, -237,    0,    0, -236,  -52,    0,
 -194,    0, -166,    0,    0, -117, -115,    0,    0,    0,
  -44, -166,   58,    0, -166, -247, -249, -197, -236, -197,
    0, -166,  -48, -115, -194,  -93, -194, -194,    0, -194,
 -194, -166, -247, -166, -166, -166, -166, -166, -166,  -24,
    0,    0, -166,  -39,    0,  -38, -247,    0, -115,    0,
 -115, -115,    0,    0, -199, -247, -247, -247, -247, -247,
 -247,    0,  -17, -247,  -31,  -29,  -20,    0, -236,    0,
 -220, -220,    0,   -9, -236,    0,    0,    0,    0,    0,
    0,    0, -236, -166,    0, -247,    2,    0,    0, -236,
    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -198,    0,    0, -189,    0,    0,
    0,  -25,    0,    0,    0, -261,    0,    0,    0,    0,
 -248,    0,    0,    0,    0,    0,  -94,    0,    0,    0,
 -212,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -156, -180,    0,    0,    0, -151,    0, -151,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -94,    0,    0,
    0,    0,    0,    0, -129,    0,  -95,    0,    0,    0,
    0,    0,    0,    0,    0,  -78,    0,  -15, -260,  -14,
    0,    0,    0,  -61,    0,    0,    0,    0,    0,    0,
    0,    0,  -88,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -5,    0,  -26,    0,
    8,   42,    0,    0,    0, -250, -149,  -63,  -57,  -54,
  -43,    0,    0,  -56,    0,    0,    0,    0, -227,    0,
 -151, -151,    0, -246, -227,    0,    0,    0,    0,    0,
    0,    0, -227,    0,    0,   13,    0,    0,    0, -227,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  267,    0,  -27,    0,  252,  173,    0,  231,
    0,    0,    0,  -47,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -53,  190,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  176,    0,   27,    0,
   68,    0,    0,    0,
};
#define YYTABLESIZE 340
static const short yytable[] = {                         50,
   76,   66,   30,   30,    4,   67,   86,   74,    5,   32,
   32,    5,    5,   45,    5,    5,    5,   74,    5,   96,
   27,    1,    5,    5,   28,   97,   98,   73,  103,   73,
   29,   73,   73,   68,  112,   30,   30,  113,  117,    5,
   91,   45,    5,   32,   45,    5,   68,   68,   86,    6,
  126,  127,  128,  129,  130,  131,   11,   31,    4,  134,
   73,  115,    4,   73,    4,    4,    4,    9,    4,   13,
   68,    9,    4,    4,    9,   68,   10,    9,   68,   40,
   10,    9,    9,   10,  138,   21,   10,  113,   73,   22,
   10,   10,    4,  146,  147,    4,   43,   94,   74,   75,
  156,    9,   66,   66,    9,    4,   71,   72,   75,    4,
   10,  144,    4,   10,   23,    4,   73,  151,   75,    4,
    4,  119,   25,  121,  122,  155,   74,   75,   95,   95,
   95,   66,  161,   45,   66,   46,    4,   53,   95,   95,
   47,   52,    4,   95,   95,   95,   95,   95,   95,   95,
   95,   95,   95,   94,   95,   97,   98,   95,   95,  100,
  101,   95,   80,   80,   80,   73,   99,  123,  124,   30,
   41,   41,   80,   80,   54,   60,   32,   80,   80,   97,
   98,   80,   80,   80,   80,   80,   80,   14,   80,   15,
  120,   80,   80,   73,   77,   80,   81,   81,   81,   41,
   76,   56,   41,   79,   77,   96,   81,   81,   96,   70,
   76,   81,   81,   79,   78,   81,   81,   81,   81,   81,
   81,   58,   81,   48,   78,   81,   81,   97,   49,   81,
   97,   83,   83,   83,   88,  118,   82,   90,  102,   92,
  140,   83,   83,  132,  135,  136,   83,   83,  143,  149,
   83,   83,   83,   83,   83,   83,  141,   83,  142,  158,
   83,   83,    8,   53,   83,   84,   84,   84,   22,   17,
   57,    8,   44,   61,  111,   84,   84,  125,    0,    0,
   84,   84,    0,    0,   84,   84,   84,   84,   84,   84,
    0,   84,    0,    0,   84,   84,    0,    0,   84,   85,
   85,   85,    0,    0,    0,    0,    0,    0,    0,   85,
   85,    0,    0,    0,   85,   85,    0,    0,   85,   85,
   85,   85,   85,   85,    0,   85,    0,    0,   85,   85,
   97,   98,   85,    0,  104,  105,  106,  107,  108,  109,
};
static const short yycheck[] = {                         27,
   54,   49,  264,  264,  294,  260,   60,  258,  257,  271,
  271,  288,  261,  260,  263,  264,  265,  268,  267,   73,
  257,  266,  271,  272,  261,  273,  274,  288,   82,  291,
  267,  259,  260,  288,  284,  272,  264,  287,   92,  288,
   68,  288,  291,  271,  291,  294,  259,  260,  102,  270,
  104,  105,  106,  107,  108,  109,  294,  294,  257,  113,
  288,   89,  261,  291,  263,  264,  265,  257,  267,  291,
  283,  261,  271,  272,  264,  288,  257,  267,  291,  292,
  261,  271,  272,  264,  284,  288,  267,  287,  283,  287,
  271,  272,  291,  141,  142,  294,  288,   71,  293,  294,
  154,  291,  259,  260,  294,  257,  273,  274,  258,  261,
  291,  139,  264,  294,  294,  267,  283,  145,  268,  271,
  272,   95,  294,   97,   98,  153,  293,  294,  258,  259,
  260,  288,  160,  294,  291,  283,  288,  283,  268,  269,
  288,  294,  294,  273,  274,  275,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  273,  274,  287,  288,  275,
  276,  291,  258,  259,  260,  260,  284,  100,  101,  264,
  259,  260,  268,  269,  283,  283,  271,  273,  274,  273,
  274,  277,  278,  279,  280,  281,  282,  263,  284,  265,
  284,  287,  288,  288,  258,  291,  258,  259,  260,  288,
  258,  264,  291,  258,  268,  284,  268,  269,  287,  294,
  268,  273,  274,  268,  258,  277,  278,  279,  280,  281,
  282,  271,  284,  283,  268,  287,  288,  284,  288,  291,
  287,  258,  259,  260,   62,  284,  292,   65,  283,  292,
  258,  268,  269,  268,  284,  284,  273,  274,  269,  259,
  277,  278,  279,  280,  281,  282,  288,  284,  288,  258,
  287,  288,  288,  269,  291,  258,  259,  260,  284,  284,
  258,    5,   21,   43,   85,  268,  269,  102,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,   -1,   -1,  287,  288,   -1,   -1,  291,  258,
  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,
  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,
  279,  280,  281,  282,   -1,  284,   -1,   -1,  287,  288,
  273,  274,  291,   -1,  277,  278,  279,  280,  281,  282,
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
"assignment_statement : IDENT $$9 ASSIGN expression",
"$$10 :",
"$$11 :",
"if_statement : IF condition $$10 THEN $$11 statement else_statement",
"else_statement :",
"$$12 :",
"else_statement : ELSE $$12 statement",
"$$13 :",
"$$14 :",
"$$15 :",
"while_statement : WHILE $$13 condition $$14 DO $$15 statement",
"$$16 :",
"$$17 :",
"$$18 :",
"$$19 :",
"$$20 :",
"$$21 :",
"$$22 :",
"$$23 :",
"$$24 :",
"$$25 :",
"$$26 :",
"$$27 :",
"$$28 :",
"for_statement : FOR IDENT $$16 ASSIGN expression $$17 TO $$18 $$19 $$20 expression $$21 DO $$22 $$23 statement $$24 $$25 $$26 $$27 $$28",
"proc_call_statement : proc_call_name",
"proc_call_statement : proc_call_name LPAREN arg_list RPAREN",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$29 :",
"read_statement : READ LPAREN IDENT $$29 RPAREN",
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
"$$30 :",
"expression : MINUS $$30 term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"factor : func_call",
"func_call : func_call_name LPAREN arg_list RPAREN",
"func_call_name : IDENT",
"var_name : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",

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
#line 689 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 470 "y.tab.c"

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
#line 56 "parser.y"
	{init_fstack();}
break;
case 2:
#line 57 "parser.y"
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
#line 98 "parser.y"
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
#line 119 "parser.y"
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
#line 149 "parser.y"
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
#line 158 "parser.y"
	{
                Factor tmp, arg1;
                tmp = lookup(decltl->fname);
                arg1.type = LOCAL_VAR;
                arg1.cal = tmp.ret;
                factorpush(arg1);
                create_llvmcode(Load);
                create_llvmcode(Ret);                
                delete(); 
                Proc_Term--;
                Func_Term--;
        }
break;
case 16:
#line 174 "parser.y"
	{arity_decl=1;}
break;
case 17:
#line 174 "parser.y"
	{arity_decl=0;}
break;
case 19:
#line 179 "parser.y"
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
#line 197 "parser.y"
	{arity_decl=1;}
break;
case 22:
#line 197 "parser.y"
	{arity_decl=0;}
break;
case 24:
#line 201 "parser.y"
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
                factorpush(f_tmp);
                create_llvmcode(Alloca);
        }
break;
case 25:
#line 223 "parser.y"
	{Arity_Alloca();}
break;
case 30:
#line 235 "parser.y"
	{
                if_flg = 0;
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 31:
#line 242 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                if (if_flg) br_decl->eluncoll = br_decl->uncoll;
                Last_Register ++;
                br_decl = br_decl->before;
                if_flg = 0;
        }
break;
case 32:
#line 251 "parser.y"
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
#line 263 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 34:
#line 272 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 35:
#line 279 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
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
#line 304 "parser.y"
	{
                Factor tmp;
                tmp = lookup(yystack.l_mark[0].ident);
                if (tmp.type == PROC_NAME) {
                        tmp.cal = decltl->arity+1;
                        tmp.type = LOCAL_VAR;
                }
                
                factorpush(tmp);
        }
break;
case 41:
#line 315 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 42:
#line 322 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrCond;
                tmp->next = NULL;
                (tmp->args).brcond.arg1 = factorpop();
                (tmp->args).brcond.arg2 = &br_decl->coll;
                (tmp->args).brcond.arg3 = &br_decl->eluncoll;
                br_decl->coll = Last_Register;
                add_llvmnode(tmp);
        }
break;
case 43:
#line 333 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 44:
#line 338 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->uncoll;
                add_llvmnode(tmp);
        }
break;
case 45:
#line 349 "parser.y"
	{ if_flg = 1;}
break;
case 46:
#line 351 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->uncoll;
                add_llvmnode(tmp);
                create_llvmcode(Label);
                br_decl->eluncoll = Last_Register;
                Last_Register ++;
        }
break;
case 48:
#line 365 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 49:
#line 370 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 50:
#line 374 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 51:
#line 378 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 52:
#line 390 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 53:
#line 394 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 54:
#line 398 "parser.y"
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
        }
break;
case 55:
#line 409 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 56:
#line 413 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 57:
#line 418 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 58:
#line 423 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 59:
#line 426 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 60:
#line 431 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 61:
#line 438 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 62:
#line 443 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 63:
#line 448 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 64:
#line 456 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 65:
#line 459 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 68:
#line 474 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 70:
#line 483 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 71:
#line 484 "parser.y"
	{
                Factor proc, arg1, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
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
case 72:
#line 504 "parser.y"
	{
                Factor proc, arg1, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
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
case 74:
#line 529 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 75:
#line 534 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 76:
#line 539 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 77:
#line 544 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 78:
#line 549 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 79:
#line 554 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 82:
#line 564 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 83:
#line 571 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 84:
#line 575 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 85:
#line 579 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 87:
#line 587 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 88:
#line 592 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 89:
#line 600 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 90:
#line 604 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 92:
#line 613 "parser.y"
	{       
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
                Factor arg;
                for (i = 0; i < 11;i++){
                        arg = factorpop();
                        printf("%d",arg.type);
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
case 94:
#line 643 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 95:
#line 648 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 98:
#line 660 "parser.y"
	{
                if(arity_decl==1)decltl->arity ++;
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
case 99:
#line 675 "parser.y"
	{ 
                if(arity_decl==1)decltl->arity ++;
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
#line 1331 "y.tab.c"
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
