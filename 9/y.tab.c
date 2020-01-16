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
    5,   26,    5,    5,    5,    5,    5,    5,    5,   22,
   33,   33,   35,   37,   36,   40,   38,   39,   42,   43,
   23,   44,   45,   44,   46,   47,   48,   25,   49,   50,
   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,
   61,   27,   28,   28,   62,   30,   31,   32,   29,   41,
   41,   41,   41,   41,   41,   34,   34,   65,   34,   34,
   34,   64,   64,   64,   66,   66,   66,   66,   67,   68,
   63,   63,    8,    8,   69,   69,   70,   71,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    1,    4,    0,    0,    9,    1,    4,
    0,    0,    9,    1,    0,    3,    3,    1,    1,    0,
    2,    0,    2,    1,    1,    1,    1,    1,    1,    3,
    1,    1,    1,    1,    1,    0,    5,    1,    0,    0,
    7,    0,    0,    3,    0,    0,    0,    7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,    1,    4,    1,    3,    4,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    0,    3,    3,
    3,    1,    3,    3,    1,    1,    3,    1,    4,    1,
    1,    3,    1,    3,    1,    1,    1,    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,  103,  105,  106,    2,    0,    0,    0,    0,
   12,   13,   14,    0,    0,    0,   24,    0,   19,    0,
    0,    0,    0,    0,    0,    3,   29,    0,    0,   34,
   35,   36,   37,   38,   39,    0,   41,   42,   43,   45,
    0,    0,    0,    6,    0,  104,   21,    0,   16,    0,
   28,    0,   59,    0,    0,    0,   31,   55,   33,    0,
    0,    0,   11,    0,    0,   25,   20,    0,   15,   76,
    0,    0,   44,    0,    0,   88,    0,   96,    0,    0,
    0,    0,   92,   98,    0,    0,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   27,    0,   77,    0,
    0,    0,    0,    0,   78,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   56,    0,   74,    0,  108,
    0,   26,    0,    0,    0,   97,    0,    0,   93,   94,
    0,    0,    0,    0,    0,    0,    0,   50,    0,   47,
    0,    0,    0,    0,   99,    0,   57,    0,    0,   61,
    0,    0,   23,   18,   62,   53,   51,   58,   63,    0,
    0,   54,    0,    0,   65,   66,    0,   67,   68,   69,
   70,   71,   72,
};
static const short yydgoto[] = {                          2,
    3,    7,   76,   19,   36,    9,   10,   12,   20,   21,
   22,   23,   30,   77,   78,  133,   28,   75,  131,  105,
   62,   37,   67,   38,   69,   39,   40,   41,   42,   43,
   44,   45,   90,   96,   47,   48,   49,   50,   51,  127,
   97,  125,  156,  167,  170,   98,  149,  162,   82,  154,
  165,  169,  171,  174,  176,  177,  179,  180,  181,  182,
  183,   52,  102,   92,  111,   93,   94,   95,   13,   14,
   15,
};
static const short yysindex[] = {                      -259,
    0,    0, -285, -266, -246, -252, -247, -260, -242,    0,
 -226, -215,    0,    0,    0,    0, -216, -196, -224, -183,
    0,    0,    0, -246, -182, -252,    0, -212,    0, -186,
 -224, -177, -154, -142,    0,    0,    0, -139, -121,    0,
    0,    0,    0,    0,    0, -135,    0,    0,    0,    0,
  -94,  -54, -260,    0,  -79,    0,    0, -246,    0, -246,
    0, -254,    0,  -70,  -56,  -56,    0,    0,    0,  -56,
  -56,  -56,    0,  -48, -252,    0,    0, -252,    0,    0,
 -224,  -45,    0,  -50, -244,    0,  -56,    0,    0,    0,
 -180, -185,    0,    0,  -32,  114,    0,  -56, -109, -109,
 -109,  -61,  -34, -215, -224, -215,    0,  -56,    0, -185,
 -244, -118, -244, -244,    0, -244, -244,  -56,  -56,  -56,
  -56,  -56,  -56,  -56,   -9,    0,  -24,    0,  -56,    0,
  -21,    0,  -18, -109, -185,    0, -185, -185,    0,    0,
  -59, -109, -109, -109, -109, -109, -109,    0,    9,    0,
 -109,  -20,  -17,    3,    0, -224,    0, -246, -246,    0,
   20, -224,    0,    0,    0,    0,    0,    0,    0, -224,
  -56,    0, -109,   23,    0,    0, -224,    0,    0,    0,
    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -184,    0,    0, -253,    0,    0,
  -89,   -3,    0,    0,    0,    0,    0,    0, -251,    0,
    0,    0,    0, -236,    0,    0,    0,    0,    0,    0,
 -129,    0,    0,    0, -164,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0, -199, -158,    0,    0,    0,    0, -149,    0, -149,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -129,    0,    0,    1,    0,    0,    0,    0, -106,  -72,
    0,  -38,    0,    0,    0,    0,    0,    0,  -99,    5,
  -27,    0,    0,    8, -241,   10,    0,    0,    0,   -4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   24,   30,    0,   64,   98,    0,    0,
    0, -138, -124, -120,  -75,  -74,  -68,    0,    0,    0,
  -26,    0,    0,    0,    0,  110,    0, -149, -149,    0,
 -234,  110,    0,    0,    0,    0,    0,    0,    0,  110,
    0,    0,   37,    0,    0,    0,  110,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  291,    0,  -30,    0,  273,   71,    0,  247,
    0,    0,    0,  -58,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -19,  -55,    0,    0,    0,    0,    0,    0,
  203,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  184,  -29,    0,  116,    0,    0,  279,    0,
    0,
};
#define YYTABLESIZE 401
static const short yytable[] = {                         46,
   61,   79,   17,    9,   18,   80,    1,    9,    4,   91,
    9,   46,   30,    9,   99,  100,  101,    9,    9,   32,
    5,    5,   30,    6,    5,   52,    5,    5,    5,   32,
    5,  112,   31,   81,    5,    5,   32,    9,   87,   79,
    9,   11,   33,   16,   84,   24,   79,   34,   88,   89,
  107,    5,  134,   52,    5,  110,   52,    5,   25,   73,
   73,   46,  101,  142,  143,  144,  145,  146,  147,   35,
   57,   26,    4,  151,  132,   58,    4,   27,    4,    4,
    4,  135,    4,  137,  138,   46,    4,    4,   73,  116,
  117,   73,  113,  114,   75,   75,   59,   29,   10,  163,
  164,   60,   10,  115,   53,   10,    4,    4,   10,    4,
   55,    4,   10,   10,    4,  173,   63,    4,   75,   80,
   44,    4,    4,   75,   66,  161,   75,   44,   64,   80,
   79,  168,   10,   81,   30,   10,   46,   83,    4,  172,
   65,   32,   46,   81,    4,  104,  178,   83,  106,   68,
   46,   44,   44,   44,  113,  114,   70,   46,   79,   40,
   40,   44,   44,  113,  114,  136,   44,   44,   44,   44,
   44,   44,   44,   44,   44,   44,  100,   44,   44,   44,
   44,   44,   82,   85,   44,   95,   95,   95,   40,   84,
   71,   40,   82,   85,  107,   95,   95,  107,  107,   84,
   95,   95,   95,   95,   95,   95,   95,   95,   95,   95,
   74,   95,   48,   95,   95,   95,   85,   86,   95,   86,
   86,   86,  128,   83,  155,  129,   87,  129,   72,   86,
   86,  139,  140,  109,   86,   86,   88,   89,   86,   86,
   86,   86,   86,   86,  103,   86,  108,   86,   86,   86,
  118,  130,   86,   87,   87,   87,  101,  102,  148,  101,
  102,  150,  152,   87,   87,  153,  157,  158,   87,   87,
  159,  160,   87,   87,   87,   87,   87,   87,  166,   87,
  175,   87,   87,   87,    8,   48,   87,   89,   89,   89,
   46,   22,   60,   17,   64,    8,   54,   89,   89,   73,
  126,  141,   89,   89,   56,    0,   89,   89,   89,   89,
   89,   89,    0,   89,    0,   89,   89,   89,    0,    0,
   89,   90,   90,   90,    0,    0,    0,    0,    0,    0,
    0,   90,   90,    0,    0,    0,   90,   90,    0,    0,
   90,   90,   90,   90,   90,   90,    0,   90,    0,   90,
   90,   90,    0,    0,   90,   91,   91,   91,    0,    0,
    0,    0,    0,    0,    0,   91,   91,    0,   79,   79,
   91,   91,    0,   30,   91,   91,   91,   91,   91,   91,
   32,   91,    0,   91,   91,   91,  113,  114,   91,    0,
  119,  120,  121,  122,  123,  124,    0,   79,    0,    0,
   79,
};
static const short yycheck[] = {                         19,
   31,   60,  263,  257,  265,  260,  266,  261,  294,   65,
  264,   31,  264,  267,   70,   71,   72,  271,  272,  271,
  257,  288,  264,  270,  261,  260,  263,  264,  265,  271,
  267,   87,  257,  288,  271,  272,  261,  291,  283,  291,
  294,  294,  267,  291,   64,  288,  288,  272,  293,  294,
   81,  288,  108,  288,  291,   85,  291,  294,  285,  259,
  260,   81,  118,  119,  120,  121,  122,  123,  124,  294,
  283,  287,  257,  129,  105,  288,  261,  294,  263,  264,
  265,  111,  267,  113,  114,  105,  271,  272,  288,  275,
  276,  291,  273,  274,  259,  260,  283,  294,  257,  158,
  159,  288,  261,  284,  288,  264,  291,  257,  267,  294,
  293,  261,  271,  272,  264,  171,  294,  267,  283,  258,
  285,  271,  272,  288,  264,  156,  291,  292,  283,  268,
  260,  162,  291,  258,  264,  294,  156,  258,  288,  170,
  283,  271,  162,  268,  294,   75,  177,  268,   78,  271,
  170,  258,  259,  260,  273,  274,  292,  177,  288,  259,
  260,  268,  269,  273,  274,  284,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,  288,  258,  258,  291,  258,  259,  260,  288,  258,
  285,  291,  268,  268,  284,  268,  269,  287,  288,  268,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  290,  284,  285,  286,  287,  288,  273,  274,  291,  258,
  259,  260,  284,  294,  284,  287,  283,  287,  283,  268,
  269,  116,  117,  284,  273,  274,  293,  294,  277,  278,
  279,  280,  281,  282,  293,  284,  292,  286,  287,  288,
  283,  286,  291,  258,  259,  260,  284,  284,  268,  287,
  287,  286,  284,  268,  269,  284,  258,  288,  273,  274,
  288,  269,  277,  278,  279,  280,  281,  282,  259,  284,
  258,  286,  287,  288,  288,  285,  291,  258,  259,  260,
  286,  284,  269,  284,  258,    5,   24,  268,  269,   53,
   98,  118,  273,  274,   26,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,  286,  287,  288,   -1,   -1,
  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,  286,
  287,  288,   -1,   -1,  291,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,  259,  260,
  273,  274,   -1,  264,  277,  278,  279,  280,  281,  282,
  271,  284,   -1,  286,  287,  288,  273,  274,  291,   -1,
  277,  278,  279,  280,  281,  282,   -1,  288,   -1,   -1,
  291,
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
"variable : entire_variable",
"variable : component_variable",
"entire_variable : variable_id",
"variable_id : IDENT",
"component_variable : indexed_variable",
"$$9 :",
"indexed_variable : array_variable LBRACKET expression $$9 RBRACKET",
"array_variable : variable",
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
#line 724 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 503 "y.tab.c"

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
                ftmp.range = 0;
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
#line 120 "parser.y"
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
                ftmp.range = 0;
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
#line 151 "parser.y"
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
#line 160 "parser.y"
	{
                Factor tmp, arg1;
                tmp = lookup(decltl->fname);
                arg1.type = LOCAL_VAR;
                arg1.cal = tmp.ret;
                arg1.range = 0;
                factorpush(arg1);
                create_llvmcode(Load);
                create_llvmcode(Ret);                
                delete(); 
                Proc_Term--;
                Func_Term--;
        }
break;
case 16:
#line 177 "parser.y"
	{arity_decl=1;}
break;
case 17:
#line 177 "parser.y"
	{arity_decl=0;}
break;
case 19:
#line 182 "parser.y"
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
#line 200 "parser.y"
	{arity_decl=1;}
break;
case 22:
#line 200 "parser.y"
	{arity_decl=0;}
break;
case 24:
#line 204 "parser.y"
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
                f_tmp.range = 0;
                factorpush(f_tmp);
                create_llvmcode(Alloca);
        }
break;
case 25:
#line 227 "parser.y"
	{Arity_Alloca();}
break;
case 30:
#line 239 "parser.y"
	{
                if_flg = 0;
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 31:
#line 246 "parser.y"
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
#line 255 "parser.y"
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
#line 267 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 34:
#line 276 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 35:
#line 283 "parser.y"
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
#line 308 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 42:
#line 316 "parser.y"
	{
                create_llvmcode(GetElem);
        }
break;
case 44:
#line 327 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 46:
#line 338 "parser.y"
	{
                create_llvmcode(Sext);
        }
break;
case 49:
#line 351 "parser.y"
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
case 50:
#line 362 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 51:
#line 367 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->uncoll;
                add_llvmnode(tmp);
        }
break;
case 52:
#line 378 "parser.y"
	{ if_flg = 1;}
break;
case 53:
#line 380 "parser.y"
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
case 55:
#line 394 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 56:
#line 399 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 57:
#line 403 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 58:
#line 407 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 59:
#line 419 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 60:
#line 423 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 61:
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
case 62:
#line 438 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 63:
#line 442 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 64:
#line 447 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 65:
#line 452 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 66:
#line 455 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 67:
#line 460 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 68:
#line 467 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 69:
#line 472 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 70:
#line 477 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 71:
#line 485 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 72:
#line 488 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 75:
#line 503 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 77:
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
case 78:
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
case 80:
#line 557 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 81:
#line 562 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 82:
#line 567 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 83:
#line 572 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 84:
#line 577 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 85:
#line 582 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 88:
#line 592 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 89:
#line 599 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 90:
#line 603 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 91:
#line 607 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 93:
#line 615 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 94:
#line 620 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 95:
#line 627 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 96:
#line 631 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 98:
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
case 100:
#line 669 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 107:
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
case 108:
#line 706 "parser.y"
	{ 
                if(arity_decl==1)decltl->arity++;
                Factor f_tmp;
                f_tmp = insert(yystack.l_mark[-5].ident, 0);
                f_tmp.range = yystack.l_mark[-1].num+1;
                Stack_tl->range = yystack.l_mark[-1].num+1;
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
#line 1364 "y.tab.c"
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
