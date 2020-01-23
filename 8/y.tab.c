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
   23,    1,    1,   37,   36,   39,   40,   42,   24,   41,
   43,   41,   44,   45,   46,   26,   47,   48,   49,   50,
   51,   52,   53,   54,   55,   56,   57,   58,   59,   28,
   29,   29,   60,   31,   32,   33,   30,   38,   38,   38,
   38,   38,   38,   35,   35,   63,   35,   35,   35,   62,
   62,   62,   64,   64,   64,   64,   65,   66,   61,   61,
    9,    9,   67,   67,   68,   69,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    1,    4,    0,    0,    9,    1,    4,
    0,    0,    9,    1,    0,    3,    3,    1,    1,    0,
    2,    0,    2,    1,    1,    1,    1,    1,    1,    0,
    4,    1,    1,    0,    5,    0,    0,    0,    8,    0,
    0,    3,    0,    0,    0,    7,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   21,
    1,    4,    1,    3,    4,    4,    0,    3,    3,    3,
    3,    3,    3,    1,    2,    0,    3,    3,    3,    1,
    3,    3,    1,    1,    3,    1,    4,    1,    1,    3,
    1,    3,    1,    1,    1,    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,  101,  103,  104,    2,    0,    0,    0,    0,
   12,   13,   14,    0,    0,    0,   24,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    3,   29,    0,    0,
   34,   35,   36,   37,   38,   39,   43,    0,    0,    6,
    0,  102,   21,    0,   16,    0,   28,    0,   57,    0,
    0,    0,    0,    0,   31,   53,   33,    0,   11,    0,
    0,   25,   20,    0,   15,   74,    0,    0,   42,    0,
    0,   86,    0,   94,    0,    0,    0,    0,   90,   96,
    0,    0,    0,    0,   46,    0,    0,    0,    0,    0,
    0,    0,   27,    0,   75,    0,    0,    0,    0,    0,
   76,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   54,   72,    0,  106,    0,   26,    0,
    0,    0,   95,    0,    0,   91,   92,    0,   45,    0,
    0,    0,    0,    0,    0,   47,    0,    0,    0,    0,
    0,   97,    0,   55,    0,    0,   59,   48,    0,   23,
   18,   60,    0,   56,   61,   51,   49,    0,    0,    0,
   52,    0,   63,   64,    0,   65,   66,   67,   68,   69,
   70,
};
static const short yydgoto[] = {                          2,
   86,    3,    7,   72,   19,   37,    9,   10,   12,   20,
   21,   22,   23,   30,   73,   74,  130,   28,   71,  128,
  101,   58,   38,   65,   39,   67,   40,   41,   42,   43,
   44,   45,   46,   63,   94,   47,  115,   95,  123,  153,
  167,  163,  169,   96,  147,  159,   78,  151,  162,  165,
  168,  172,  174,  175,  177,  178,  179,  180,  181,   48,
   98,   88,  107,   89,   90,   91,   13,   14,   15,
};
static const short yysindex[] = {                      -253,
    0,    0, -283, -265, -240, -263, -242, -246, -250,    0,
 -218, -203,    0,    0,    0,    0, -204, -187, -217, -173,
    0,    0,    0, -240, -165, -263,    0, -256,    0, -196,
 -217, -161, -137, -134,    0, -150,    0,    0, -113,  -89,
    0,    0,    0,    0,    0,    0,    0, -128, -246,    0,
  -87,    0,    0, -240,    0, -240,    0, -245,    0,  -93,
  -46,  -46,  -84,  -46,    0,    0,    0,  -46,    0,  -42,
 -263,    0,    0, -263,    0,    0, -217,  -57,    0, -104,
 -241,    0,  -46,    0,    0, -150, -148,  -52,    0,    0,
  -31,  -32,  -46,  116,    0,  -46,  -32,  -71,  -33, -203,
 -217, -203,    0,  -46,    0,  -52, -241, -100, -241, -241,
    0, -241, -241,  -46,  -29,  -32,  -46,  -46,  -46,  -46,
  -46,  -46,  -10,    0,    0,  -46,    0,  -28,    0,  -23,
  -32,  -52,    0,  -52,  -52,    0,    0,  -70,    0,  -32,
  -32,  -32,  -32,  -32,  -32,    0,    4,  -32,  -17,  -13,
    7,    0, -217,    0, -240, -240,    0,    0, -217,    0,
    0,    0,   10,    0,    0,    0,    0,  -46, -217,  -32,
    0,   23,    0,    0, -217,    0,    0,    0,    0,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -191,    0,    0, -178,    0,    0,
  -99,   -6,    0,    0,    0,    0,    0,    0, -186,    0,
    0,    0,    0, -243,    0,    0,    0,    0,    0,    0,
  -81,    0,    0,    0,   95,   -9,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -254, -153,    0,
    0,    0,    0, -140,    0, -140,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -81,    0,    0,    0,
    0,    0,    0,    0, -116,  -82,    0,  -48,    0,    0,
    0,   -2,    0,    0,    0,    0,  -69,    0,    0,    1,
 -255,    2,    0,    0,    0,  -14,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -252,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   18,   20,    0,   54,   88,    0,    0,    0,    0, -193,
 -162, -159, -146, -138, -121,    0,    0,  -65,    0,    0,
    0,    0,  100,    0, -140, -140,    0,    0,  100,    0,
    0,    0, -234,    0,    0,    0,    0,    0,  100,   32,
    0,    0,    0,    0,  100,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
  -19,    0,    0,  286,    0,  -30,    0,  268,   17,    0,
  246,    0,    0,    0,  -54,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -58,    0,    0,  200,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  189,  -12,    0,  137,    0,    0,  279,    0,    0,
};
#define YYTABLESIZE 398
static const short yytable[] = {                         36,
   57,   75,   87,   92,   71,   71,   41,   41,   30,   97,
    4,   36,    1,    5,   76,   32,   17,    5,   18,    5,
    5,    5,    5,    5,  108,   50,   53,    5,    5,    6,
   11,   54,   77,   71,  116,   41,   71,   24,   41,   31,
   80,   83,   77,   32,    5,  131,  103,    5,   16,   33,
    5,   84,   85,   50,   34,   97,   50,   36,  140,  141,
  142,  143,  144,  145,   78,    4,   25,  148,  106,    4,
  129,    4,    4,    4,   78,    4,   35,   30,    9,    4,
    4,   36,    9,   26,   32,    9,   55,  100,    9,   27,
  102,   56,    9,    9,  132,   79,  134,  135,   81,    4,
  160,  161,    4,   10,   77,   79,   29,   10,   81,  170,
   10,   80,    9,   10,   49,    9,    4,   10,   10,   83,
    4,   80,  158,    4,  109,  110,    4,   51,  164,   83,
    4,    4,   59,   36,   62,  111,   82,   10,  171,   36,
   10,   42,   42,   42,  176,   60,   82,    4,   61,   36,
   64,   42,   42,    4,   68,   36,   42,   42,   42,   42,
   42,   42,   42,   42,   42,   42,   98,   42,   42,   42,
   42,   42,  109,  110,   42,   93,   93,   93,   77,  105,
   62,   66,   30,  133,  105,   93,   93,  105,  105,   32,
   93,   93,   93,   93,   93,   93,   93,   93,   93,   93,
   79,   93,   70,   93,   93,   93,   77,   93,   93,   84,
   84,   84,  125,  152,   99,  126,  126,   99,  100,   84,
   84,  100,  112,  113,   84,   84,   81,   82,   84,   84,
   84,   84,   84,   84,  104,   84,   83,   84,   84,   84,
  109,  110,   84,   85,   85,   85,   84,   85,  136,  137,
   99,  114,  127,   85,   85,  149,  139,  146,   85,   85,
  150,  154,   85,   85,   85,   85,   85,   85,  166,   85,
  155,   85,   85,   85,  156,  157,   85,   87,   87,   87,
  173,    8,   40,   44,   22,   17,   58,   87,   87,   62,
    8,   50,   87,   87,   69,  124,   87,   87,   87,   87,
   87,   87,  138,   87,   52,   87,   87,   87,    0,    0,
   87,   88,   88,   88,    0,    0,    0,    0,    0,    0,
    0,   88,   88,    0,    0,    0,   88,   88,    0,    0,
   88,   88,   88,   88,   88,   88,    0,   88,    0,   88,
   88,   88,    0,    0,   88,   89,   89,   89,    0,    0,
    0,    0,    0,   73,   73,   89,   89,    0,   77,   77,
   89,   89,    0,   30,   89,   89,   89,   89,   89,   89,
   32,   89,    0,   89,   89,   89,    0,   73,   89,   42,
    0,    0,   73,    0,    0,   73,   42,   77,  109,  110,
   77,    0,  117,  118,  119,  120,  121,  122,
};
static const short yycheck[] = {                         19,
   31,   56,   61,   62,  259,  260,  259,  260,  264,   68,
  294,   31,  266,  257,  260,  271,  263,  261,  265,  263,
  264,  265,  288,  267,   83,  260,  283,  271,  272,  270,
  294,  288,  288,  288,   93,  288,  291,  288,  291,  257,
   60,  283,  288,  261,  288,  104,   77,  291,  291,  267,
  294,  293,  294,  288,  272,  114,  291,   77,  117,  118,
  119,  120,  121,  122,  258,  257,  285,  126,   81,  261,
  101,  263,  264,  265,  268,  267,  294,  264,  257,  271,
  272,  101,  261,  287,  271,  264,  283,   71,  267,  294,
   74,  288,  271,  272,  107,  258,  109,  110,  258,  291,
  155,  156,  294,  257,  291,  268,  294,  261,  268,  168,
  264,  258,  291,  267,  288,  294,  257,  271,  272,  258,
  261,  268,  153,  264,  273,  274,  267,  293,  159,  268,
  271,  272,  294,  153,  285,  284,  258,  291,  169,  159,
  294,  258,  259,  260,  175,  283,  268,  288,  283,  169,
  264,  268,  269,  294,  283,  175,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,  288,  273,  274,  291,  258,  259,  260,  260,  284,
  285,  271,  264,  284,  284,  268,  269,  287,  288,  271,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  294,  284,  290,  286,  287,  288,  288,  292,  291,  258,
  259,  260,  284,  284,  284,  287,  287,  287,  284,  268,
  269,  287,  275,  276,  273,  274,  273,  274,  277,  278,
  279,  280,  281,  282,  292,  284,  283,  286,  287,  288,
  273,  274,  291,  258,  259,  260,  293,  294,  112,  113,
  293,  283,  286,  268,  269,  284,  286,  268,  273,  274,
  284,  258,  277,  278,  279,  280,  281,  282,  259,  284,
  288,  286,  287,  288,  288,  269,  291,  258,  259,  260,
  258,  288,  292,  286,  284,  284,  269,  268,  269,  258,
    5,   24,  273,  274,   49,   96,  277,  278,  279,  280,
  281,  282,  114,  284,   26,  286,  287,  288,   -1,   -1,
  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,  286,
  287,  288,   -1,   -1,  291,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,  259,  260,  268,  269,   -1,  259,  260,
  273,  274,   -1,  264,  277,  278,  279,  280,  281,  282,
  271,  284,   -1,  286,  287,  288,   -1,  283,  291,  285,
   -1,   -1,  288,   -1,   -1,  291,  292,  288,  273,  274,
  291,   -1,  277,  278,  279,  280,  281,  282,
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
"variable : indexed_variable",
"$$10 :",
"indexed_variable : variable LBRACKET expression $$10 RBRACKET",
"$$11 :",
"$$12 :",
"$$13 :",
"if_statement : IF condition $$11 THEN $$12 statement $$13 else_statement",
"else_statement :",
"$$14 :",
"else_statement : ELSE $$14 statement",
"$$15 :",
"$$16 :",
"$$17 :",
"while_statement : WHILE $$15 condition $$16 DO $$17 statement",
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
"$$29 :",
"$$30 :",
"for_statement : FOR IDENT $$18 ASSIGN expression $$19 TO $$20 $$21 $$22 expression $$23 DO $$24 $$25 statement $$26 $$27 $$28 $$29 $$30",
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
"$$31 :",
"expression : MINUS $$31 term",
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
#line 726 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 497 "y.tab.c"

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
case 46:
#line 356 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 47:
#line 360 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 48:
#line 365 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 49:
#line 369 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 51:
#line 381 "parser.y"
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
case 53:
#line 394 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 54:
#line 399 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 55:
#line 403 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 56:
#line 407 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 57:
#line 419 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 58:
#line 423 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 59:
#line 427 "parser.y"
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
case 60:
#line 438 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 61:
#line 442 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 62:
#line 447 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 63:
#line 452 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 64:
#line 455 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 65:
#line 460 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 66:
#line 467 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 67:
#line 472 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 68:
#line 477 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 69:
#line 485 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 70:
#line 488 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 73:
#line 503 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 75:
#line 513 "parser.y"
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
case 76:
#line 533 "parser.y"
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
case 78:
#line 557 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 79:
#line 562 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 80:
#line 567 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 81:
#line 572 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 82:
#line 577 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 83:
#line 582 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 86:
#line 592 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 87:
#line 599 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 88:
#line 603 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 89:
#line 607 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 91:
#line 615 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 92:
#line 620 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 93:
#line 627 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 94:
#line 631 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 96:
#line 640 "parser.y"
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
                (tmp->args).call.rettype = I32;
                Factor retval;
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register++;
                (tmp->args).call.retval = retval;
                add_llvmnode(tmp);
                factorpush(retval);
        }
break;
case 98:
#line 669 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 105:
#line 690 "parser.y"
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
case 106:
#line 706 "parser.y"
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
#line 1375 "y.tab.c"
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
