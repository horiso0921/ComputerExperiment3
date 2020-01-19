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
    6,   27,    6,    6,    6,    6,    6,    6,    6,   23,
    1,    1,   36,   35,   38,   39,   24,   40,   41,   40,
   42,   43,   44,   26,   45,   46,   47,   48,   49,   50,
   51,   52,   53,   54,   55,   56,   57,   28,   29,   29,
   58,   31,   32,   33,   30,   37,   37,   37,   37,   37,
   37,   34,   34,   61,   34,   34,   34,   60,   60,   60,
   62,   62,   62,   62,   63,   64,   59,   59,    9,    9,
   65,   65,   66,   67,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    1,    4,    0,    0,    9,    1,    4,
    0,    0,    9,    1,    0,    3,    3,    1,    1,    0,
    2,    0,    2,    1,    1,    1,    1,    1,    1,    3,
    1,    1,    0,    5,    0,    0,    7,    0,    0,    3,
    0,    0,    0,    7,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   21,    1,    4,
    1,    3,    4,    4,    0,    3,    3,    3,    3,    3,
    3,    1,    2,    0,    3,    3,    3,    1,    3,    3,
    1,    1,    3,    1,    4,    1,    1,    3,    1,    3,
    1,    1,    1,    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,   99,  101,  102,    2,    0,    0,    0,    0,
   12,   13,   14,    0,    0,    0,   24,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    3,   29,    0,    0,
   34,   35,   36,   37,   38,   39,   42,    0,    0,    6,
    0,  100,   21,    0,   16,    0,   28,    0,   55,    0,
    0,    0,    0,    0,   31,   51,   33,    0,   11,    0,
    0,   25,   20,    0,   15,   72,    0,    0,   41,    0,
    0,   84,    0,   92,    0,    0,    0,    0,   88,   94,
    0,    0,    0,    0,   45,    0,    0,    0,    0,    0,
    0,    0,   27,    0,   73,    0,    0,    0,    0,    0,
   74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   52,   70,    0,  104,    0,   26,    0,    0,
    0,   93,    0,    0,   89,   90,    0,   44,    0,    0,
    0,    0,    0,    0,   46,    0,    0,    0,    0,    0,
   95,    0,   53,    0,    0,   57,    0,    0,   23,   18,
   58,   49,   47,   54,   59,    0,    0,   50,    0,    0,
   61,   62,    0,   63,   64,   65,   66,   67,   68,
};
static const short yydgoto[] = {                          2,
   86,    3,    7,   72,   19,   37,    9,   10,   12,   20,
   21,   22,   23,   30,   73,   74,  129,   28,   71,  127,
  101,   58,   38,   65,   39,   67,   40,   41,   42,   43,
   44,   45,   46,   94,   47,  115,   95,  122,  152,  163,
  166,   96,  146,  158,   78,  150,  161,  165,  167,  170,
  172,  173,  175,  176,  177,  178,  179,   48,   98,   88,
  107,   89,   90,   91,   13,   14,   15,
};
static const short yysindex[] = {                      -261,
    0,    0, -280, -266, -219, -157, -213, -121, -163,    0,
 -123, -107,    0,    0,    0,    0, -105,  -87, -217,  -79,
    0,    0,    0, -219,  -70, -157,    0, -249,    0, -216,
 -217,  -69,  -59,  -53,    0, -106,    0,    0,  -36,  -38,
    0,    0,    0,    0,    0,    0,    0,  -49, -121,    0,
  -61,    0,    0, -219,    0, -219,    0, -236,    0,  -51,
 -142, -142, -142, -142,    0,    0,    0, -142,    0,  -52,
 -157,    0,    0, -157,    0,    0, -217,  -45,    0, -198,
 -240,    0, -142,    0,    0,  -37, -180,  -80,    0,    0,
  -29,  -60,  -60,  122,    0, -142,  -60,  -99,  -33, -107,
 -217, -107,    0, -142,    0,  -80, -240, -139, -240, -240,
    0, -240, -240, -142,  -31, -142, -142, -142, -142, -142,
 -142,  -12,    0,    0, -142,    0,  -27,    0,  -26,  -60,
  -80,    0,  -80,  -80,    0,    0,  -97,    0,  -60,  -60,
  -60,  -60,  -60,  -60,    0,    1,  -60,  -25,  -24,   -7,
    0, -217,    0, -219, -219,    0,    8, -217,    0,    0,
    0,    0,    0,    0,    0, -217, -142,    0,  -60,   10,
    0,    0, -217,    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -234,    0,    0, -188,    0,    0,
 -127,  -13,    0,    0,    0,    0,    0,    0, -255,    0,
    0,    0,    0, -246,    0,    0,    0,    0,    0,    0,
 -150,    0,    0,    0,  101,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -256, -176,    0,
    0,    0,    0, -148,    0, -148,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -150,    0,    0,    0,
    0,    0,    0,    0, -110,  -76,    0,  -42,    0,    0,
    0,   -9, -162,    0,    0,    0,  -93,    0,    0,   -3,
 -196,   -2,    0,    0,    0,   -8,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   18,
   26,    0,   60,   94,    0,    0,    0,    0, -248, -212,
 -178, -169, -151, -138,    0,    0,  -65,    0,    0,    0,
    0,  106,    0, -148, -148,    0, -186,  106,    0,    0,
    0,    0,    0,    0,    0,  106,    0,    0,   30,    0,
    0,    0,  106,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -19,    0,    0,  284,    0,  -30,    0,  266,   37,    0,
  242,    0,    0,    0,  -54,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -55,    0,    0,  196,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  179,   46,
    0,  108,    0,    0,  270,    0,    0,
};
#define YYTABLESIZE 404
static const short yytable[] = {                         36,
   57,   75,   69,   69,    1,   87,   92,   93,   30,   76,
    5,   36,   97,    4,    5,   32,    5,    5,    5,   76,
    5,    5,    4,   76,    5,    5,    4,  108,    4,    4,
    4,   69,    4,   53,   69,   75,    4,    4,   54,   31,
   80,    5,   83,   32,    5,   77,  103,    5,  130,   33,
    6,   77,   84,   85,   34,   77,    4,   36,   97,    4,
  139,  140,  141,  142,  143,  144,   55,   30,    9,  147,
  128,   56,    9,   48,   32,    9,   35,   16,    9,   79,
   10,   36,    9,    9,   10,  105,   62,   10,   78,   79,
   10,   75,  109,  110,   10,   10,   40,   40,   78,  159,
  160,   48,    9,  111,   48,    9,   81,  100,    4,   75,
  102,  169,    4,   30,   10,    4,   81,   10,    4,   80,
   32,  157,    4,    4,   24,   40,  106,  164,   40,   80,
   81,   82,   36,  109,  110,  168,   11,   75,   36,    4,
   83,   17,  174,   18,  132,    4,   36,   41,   41,   41,
   84,   85,  131,   36,  133,  134,  103,   41,   41,  103,
  103,   25,   41,   41,   41,   41,   41,   41,   41,   41,
   41,   41,   96,   41,   41,   41,   41,   41,   62,   26,
   41,   91,   91,   91,  124,   63,  151,  125,   27,  125,
   97,   91,   91,   97,  112,  113,   91,   91,   91,   91,
   91,   91,   91,   91,   91,   91,   29,   91,   49,   91,
   91,   91,  109,  110,   91,   82,   82,   82,   98,  135,
  136,   98,   51,   60,   59,   82,   82,   64,   70,   61,
   82,   82,   66,   68,   82,   82,   82,   82,   82,   82,
   99,   82,   79,   82,   82,   82,  104,   62,   82,   83,
   83,   83,  126,  114,  138,  145,  148,  149,  153,   83,
   83,  156,  154,  155,   83,   83,  162,  171,   83,   83,
   83,   83,   83,   83,    8,   83,   43,   83,   83,   83,
   22,   17,   83,   85,   85,   85,   56,   60,    8,   50,
   69,  123,  137,   85,   85,   52,    0,    0,   85,   85,
    0,    0,   85,   85,   85,   85,   85,   85,    0,   85,
    0,   85,   85,   85,    0,    0,   85,   86,   86,   86,
    0,    0,    0,    0,    0,    0,    0,   86,   86,    0,
    0,    0,   86,   86,    0,    0,   86,   86,   86,   86,
   86,   86,    0,   86,    0,   86,   86,   86,    0,    0,
   86,   87,   87,   87,    0,    0,    0,    0,    0,   71,
   71,   87,   87,    0,   75,   75,   87,   87,    0,   30,
   87,   87,   87,   87,   87,   87,   32,   87,    0,   87,
   87,   87,    0,   71,   87,   41,    0,    0,   71,    0,
    0,   71,   41,   75,  109,  110,   75,    0,  116,  117,
  118,  119,  120,  121,
};
static const short yycheck[] = {                         19,
   31,   56,  259,  260,  266,   61,   62,   63,  264,  258,
  257,   31,   68,  294,  261,  271,  263,  264,  265,  268,
  267,  288,  257,  260,  271,  272,  261,   83,  263,  264,
  265,  288,  267,  283,  291,  291,  271,  272,  288,  257,
   60,  288,  283,  261,  291,  258,   77,  294,  104,  267,
  270,  288,  293,  294,  272,  268,  291,   77,  114,  294,
  116,  117,  118,  119,  120,  121,  283,  264,  257,  125,
  101,  288,  261,  260,  271,  264,  294,  291,  267,  258,
  257,  101,  271,  272,  261,  284,  285,  264,  258,  268,
  267,  288,  273,  274,  271,  272,  259,  260,  268,  154,
  155,  288,  291,  284,  291,  294,  258,   71,  257,  260,
   74,  167,  261,  264,  291,  264,  268,  294,  267,  258,
  271,  152,  271,  272,  288,  288,   81,  158,  291,  268,
  273,  274,  152,  273,  274,  166,  294,  288,  158,  288,
  283,  263,  173,  265,  284,  294,  166,  258,  259,  260,
  293,  294,  107,  173,  109,  110,  284,  268,  269,  287,
  288,  285,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,  286,  287,  288,  285,  287,
  291,  258,  259,  260,  284,  292,  284,  287,  294,  287,
  284,  268,  269,  287,  275,  276,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  294,  284,  288,  286,
  287,  288,  273,  274,  291,  258,  259,  260,  284,  112,
  113,  287,  293,  283,  294,  268,  269,  264,  290,  283,
  273,  274,  271,  283,  277,  278,  279,  280,  281,  282,
  293,  284,  294,  286,  287,  288,  292,  285,  291,  258,
  259,  260,  286,  283,  286,  268,  284,  284,  258,  268,
  269,  269,  288,  288,  273,  274,  259,  258,  277,  278,
  279,  280,  281,  282,  288,  284,  286,  286,  287,  288,
  284,  284,  291,  258,  259,  260,  269,  258,    5,   24,
   49,   96,  114,  268,  269,   26,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,  286,  287,  288,   -1,   -1,  291,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,  286,  287,  288,   -1,   -1,
  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,  259,
  260,  268,  269,   -1,  259,  260,  273,  274,   -1,  264,
  277,  278,  279,  280,  281,  282,  271,  284,   -1,  286,
  287,  288,   -1,  283,  291,  285,   -1,   -1,  288,   -1,
   -1,  291,  292,  288,  273,  274,  291,   -1,  277,  278,
  279,  280,  281,  282,
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
"assignment_statement : variable ASSIGN expression",
"variable : IDENT",
"variable : indexed_variable",
"$$9 :",
"indexed_variable : variable LBRACKET expression $$9 RBRACKET",
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
"$$29 :",
"expression : MINUS $$29 term",
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
#line 725 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 494 "y.tab.c"

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
                if_flg = 0;
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 31:
#line 251 "parser.y"
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
#line 260 "parser.y"
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
#line 272 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 34:
#line 281 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 35:
#line 288 "parser.y"
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
#line 313 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 41:
#line 320 "parser.y"
	{
                Factor f_tmp;
                f_tmp = lookup(yystack.l_mark[0].ident);
                factorpush(f_tmp);
                yyval.num = f_tmp.off;
        }
break;
case 42:
#line 327 "parser.y"
	{
                create_llvmcode(GetElem);
        }
break;
case 43:
#line 335 "parser.y"
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
#line 350 "parser.y"
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
case 46:
#line 361 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 47:
#line 366 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->uncoll;
                add_llvmnode(tmp);
        }
break;
case 48:
#line 377 "parser.y"
	{ if_flg = 1;}
break;
case 49:
#line 379 "parser.y"
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
case 51:
#line 393 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 52:
#line 398 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 53:
#line 402 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 54:
#line 406 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 55:
#line 418 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 56:
#line 422 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 57:
#line 426 "parser.y"
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
case 58:
#line 437 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 59:
#line 441 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 60:
#line 446 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 61:
#line 451 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 62:
#line 454 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 63:
#line 459 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 64:
#line 466 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 65:
#line 471 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 66:
#line 476 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 67:
#line 484 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 68:
#line 487 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 71:
#line 502 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 73:
#line 512 "parser.y"
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
case 74:
#line 532 "parser.y"
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
case 76:
#line 556 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 77:
#line 561 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 78:
#line 566 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 79:
#line 571 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 80:
#line 576 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 81:
#line 581 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 84:
#line 591 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 85:
#line 598 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 86:
#line 602 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 87:
#line 606 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 89:
#line 614 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 90:
#line 619 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 91:
#line 626 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 92:
#line 630 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 94:
#line 639 "parser.y"
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
case 96:
#line 668 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 103:
#line 689 "parser.y"
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
case 104:
#line 705 "parser.y"
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
#line 1369 "y.tab.c"
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
