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
    2,    0,    3,    4,    4,    8,    8,    9,    5,    5,
   11,   11,   14,   12,   15,   12,   13,   13,   16,   16,
    6,    6,   17,   17,   18,   18,   19,   23,   24,   19,
   21,   20,   26,   27,   20,   25,   28,   22,   29,   29,
    7,   32,    7,   34,    7,    7,    7,    7,    7,    7,
    7,   41,   30,    1,    1,   44,   43,   46,   47,   49,
   31,   48,   50,   48,   51,   52,   53,   33,   54,   55,
   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,
   66,   35,   36,   36,   67,   38,   39,   40,   37,   45,
   45,   45,   45,   45,   45,   42,   42,   70,   42,   42,
   42,   69,   69,   69,   71,   71,   71,   71,   72,   73,
   68,   68,   10,   10,   74,   74,   75,   76,
};
static const short yylen[] = {                            2,
    0,    6,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    0,    5,    0,    5,    0,    3,    3,    1,
    0,    2,    3,    1,    1,    1,    4,    0,    0,    9,
    1,    4,    0,    0,    9,    1,    0,    3,    3,    1,
    1,    0,    2,    0,    2,    1,    1,    1,    1,    1,
    1,    0,    4,    1,    1,    0,    5,    0,    0,    0,
    8,    0,    0,    3,    0,    0,    0,    7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,    1,    4,    1,    3,    4,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    0,    3,    3,
    3,    1,    3,    3,    1,    1,    3,    1,    4,    1,
    1,    3,    1,    3,    1,    1,    1,    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,  113,  115,  116,    2,    0,    0,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
   25,   26,    0,    6,    0,  114,   15,   13,   36,    0,
   31,    0,    0,    0,    0,    0,    0,    0,    3,   41,
    0,    0,   46,   47,   48,   49,   50,   51,   55,    0,
    0,   11,    0,    0,    0,   33,    0,   28,    0,   40,
    0,   69,    0,    0,    0,    0,    0,   43,   65,   45,
    0,   23,    0,    0,   16,   14,    0,   37,   32,    0,
   27,   86,    0,    0,   54,    0,    0,   98,    0,  106,
    0,    0,    0,    0,  102,  108,    0,    0,    0,    0,
   58,    0,    0,    0,  118,   20,    0,    0,    0,    0,
   39,    0,   87,    0,    0,    0,    0,    0,   88,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,   84,    0,   18,    0,    0,   38,    0,    0,
    0,  107,    0,    0,  103,  104,    0,   57,    0,    0,
    0,    0,    0,    0,   59,    0,    0,   19,    0,    0,
    0,  109,    0,   67,    0,    0,   71,   60,    0,   35,
   30,   72,    0,   68,   73,   63,   61,    0,    0,    0,
   64,    0,   75,   76,    0,   77,   78,   79,   80,   81,
   82,
};
static const short yydgoto[] = {                          2,
  102,    3,    7,   88,   18,   28,   49,    9,   10,   12,
   19,   20,   85,   65,   64,  117,   29,   30,   31,   32,
   42,   89,   90,  149,   40,   87,  147,  119,   71,   50,
   78,   51,   80,   52,   53,   54,   55,   56,   57,   58,
   76,  110,   59,  133,  111,  141,  173,  187,  183,  189,
  112,  166,  179,   94,  171,  182,  185,  188,  192,  194,
  195,  197,  198,  199,  200,  201,   60,  114,  104,  125,
  105,  106,  107,   13,   14,   15,
};
static const short yysindex[] = {                      -241,
    0,    0, -248, -215, -154, -151, -173, -112, -111,    0,
 -116, -105,    0,    0,    0,    0, -205, -176, -104,    0,
 -154,  -91, -151,  -76,  -63,  -59,  -58, -218,  -45,    0,
    0,    0, -112,    0,  -61,    0,    0,    0,    0, -272,
    0, -226, -218,  -44,  -27,  -18,    0,  -34,    0,    0,
   -1,   -2,    0,    0,    0,    0,    0,    0,    0,    1,
 -176,    0,  -23,    2,    2,    0, -154,    0, -154,    0,
 -236,    0,   -5, -119, -119,   -6, -119,    0,    0,    0,
 -119,    0,    4,    3,    0,    0, -151,    0,    0, -151,
    0,    0, -218,    7,    0, -277, -135,    0, -119,    0,
    0,  -34, -171, -196,    0,    0,   20,  -65, -119,  132,
    0, -119,  -65, -223,    0,    0,  -77, -105, -218, -105,
    0, -119,    0, -196, -135, -145, -135, -135,    0, -135,
 -135, -119,   18,  -65, -119, -119, -119, -119, -119, -119,
   42,    0,    0, -119,    0,   19,   30,    0,   31,  -65,
 -196,    0, -196, -196,    0,    0,  -32,    0,  -65,  -65,
  -65,  -65,  -65,  -65,    0,   60,  -65,    0,   32,   35,
   50,    0, -218,    0, -154, -154,    0,    0, -218,    0,
    0,    0,   65,    0,    0,    0,    0, -119, -218,  -65,
    0,   73,    0,    0, -218,    0,    0,    0,    0,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -179,    0,    0, -167,    0,    0,
 -122,   45,    0,    0,    0,    0,    0, -235,    0,    0,
 -244,    0,    0,    0,    0,    0,    0, -190,    0,    0,
    0,    0, -131,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -165,    0,    0,    0, -250,   46,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -47,
 -115,    0,    0,   49,   49,    0, -150,    0, -150,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -165,    0,    0,    0,    0,    0,    0,    0,
  -88,  -54,    0,  -20,    0,    0,    0,   57,    0,    0,
    0,    0,   -8,    0,    0,    0,    0,   61, -216,   62,
    0,    0,    0,   14,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -13,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   75,
   48,    0,   82,  116,    0,    0,    0,    0, -254, -148,
 -133,  -90,  -85,  -57,    0,    0,   -7,    0,    0,    0,
    0,    0,  128,    0, -150, -150,    0,    0,  128,    0,
    0,    0, -257,    0,    0,    0,    0,    0,  128,   89,
    0,    0,    0,    0,  128,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
  -28,    0,    0,  343,    0,    0,  -42,    0,  328,  155,
    0,  319,  288,    0,    0,    0,    0,  293,    0,    0,
    0,  -67,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -69,    0,    0,  245,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  226,  184,    0,
   86,    0,    0,  342,    0,    0,
};
#define YYTABLESIZE 419
static const short yytable[] = {                         48,
   70,   91,   62,   90,  103,  108,  123,   75,   85,   85,
   66,  113,    5,   90,   48,   67,    5,    5,    5,    5,
    5,   21,    5,   92,    1,   21,    5,    5,   21,  126,
   62,   21,   85,   62,   54,   21,   21,   85,   43,  134,
   85,   54,   44,    5,   96,    4,    5,   42,   45,    5,
  121,   93,  150,   46,   44,   21,   68,   24,   21,   25,
  143,   69,  113,  144,   48,  159,  160,  161,  162,  163,
  164,   89,    5,   42,  167,   47,  148,    4,  130,  131,
   44,    4,    4,    4,    4,    4,   26,    4,   27,    9,
   48,    4,    4,    9,   89,    9,    9,    9,   42,    9,
   89,  127,  128,    9,    9,   44,    4,  180,  181,   91,
    4,    4,  129,    4,    4,    6,    4,   16,  190,   91,
    4,    4,   89,    9,   93,   10,    9,  127,  128,   10,
  178,   10,   10,   10,   93,   10,  184,    4,  152,   10,
   10,   22,   11,    4,   48,   22,  191,   99,   22,   17,
   48,   22,  196,   97,   98,   22,   22,  100,  101,   10,
   48,  117,   10,   99,  117,  117,   48,   92,   22,   54,
   54,   54,   95,  100,  101,   22,   21,   92,   22,   54,
   54,   23,   95,   33,   54,   54,   54,   54,   54,   54,
   54,   54,   54,   54,  110,   54,   54,   54,   54,   54,
   94,   35,   54,  105,  105,  105,  145,  127,  128,  146,
   94,   83,   83,  105,  105,  155,  156,   37,  105,  105,
  105,  105,  105,  105,  105,  105,  105,  105,   63,  105,
   38,  105,  105,  105,   39,   41,  105,   96,   96,   96,
   83,  118,   61,   83,  120,   53,   53,   96,   96,   72,
   75,  172,   96,   96,  144,   73,   96,   96,   96,   96,
   96,   96,   77,   96,   74,   96,   96,   96,   79,   83,
   96,   97,   97,   97,   53,  111,  112,   53,  111,  112,
  124,   97,   97,   81,   84,  109,   97,   97,   95,  115,
   97,   97,   97,   97,   97,   97,  116,   97,  122,   97,
   97,   97,  132,  158,   97,   99,   99,   99,  151,  165,
  153,  154,  168,  169,  170,   99,   99,  174,  177,  175,
   99,   99,  176,  186,   99,   99,   99,   99,   99,   99,
  193,   99,    8,   99,   99,   99,   17,   52,   99,  100,
  100,  100,   56,   70,   34,   29,   74,    8,   34,  100,
  100,   62,   86,   82,  100,  100,  142,  157,  100,  100,
  100,  100,  100,  100,   36,  100,    0,  100,  100,  100,
    0,    0,  100,  101,  101,  101,    0,    0,    0,    0,
    0,    0,    0,  101,  101,    0,   89,   89,  101,  101,
    0,   42,  101,  101,  101,  101,  101,  101,   44,  101,
    0,  101,  101,  101,  127,  128,  101,    0,  135,  136,
  137,  138,  139,  140,    0,   89,    0,    0,   89,
};
static const short yycheck[] = {                         28,
   43,   69,  260,  258,   74,   75,  284,  285,  259,  260,
  283,   81,  257,  268,   43,  288,  261,  262,  263,  264,
  265,  257,  267,  260,  266,  261,  271,  272,  264,   99,
  288,  267,  283,  291,  285,  271,  272,  288,  257,  109,
  291,  292,  261,  288,   73,  294,  291,  264,  267,  294,
   93,  288,  122,  272,  271,  291,  283,  263,  294,  265,
  284,  288,  132,  287,   93,  135,  136,  137,  138,  139,
  140,  288,  288,  264,  144,  294,  119,  257,  275,  276,
  271,  261,  262,  263,  264,  265,  263,  267,  265,  257,
  119,  271,  272,  261,  260,  263,  264,  265,  264,  267,
  291,  273,  274,  271,  272,  271,  257,  175,  176,  258,
  261,  291,  284,  264,  294,  270,  267,  291,  188,  268,
  271,  272,  288,  291,  258,  257,  294,  273,  274,  261,
  173,  263,  264,  265,  268,  267,  179,  288,  284,  271,
  272,  257,  294,  294,  173,  261,  189,  283,  264,  262,
  179,  267,  195,  273,  274,  271,  272,  293,  294,  291,
  189,  284,  294,  283,  287,  288,  195,  258,  285,  258,
  259,  260,  258,  293,  294,  291,  288,  268,  294,  268,
  269,  287,  268,  288,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  258,  293,  291,  258,  259,  260,  284,  273,  274,  287,
  268,  259,  260,  268,  269,  130,  131,  294,  273,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  290,  284,
  294,  286,  287,  288,  294,  294,  291,  258,  259,  260,
  288,   87,  288,  291,   90,  259,  260,  268,  269,  294,
  285,  284,  273,  274,  287,  283,  277,  278,  279,  280,
  281,  282,  264,  284,  283,  286,  287,  288,  271,  293,
  291,  258,  259,  260,  288,  284,  284,  291,  287,  287,
   97,  268,  269,  283,  283,  292,  273,  274,  294,  286,
  277,  278,  279,  280,  281,  282,  294,  284,  292,  286,
  287,  288,  283,  286,  291,  258,  259,  260,  125,  268,
  127,  128,  294,  284,  284,  268,  269,  258,  269,  288,
  273,  274,  288,  259,  277,  278,  279,  280,  281,  282,
  258,  284,  288,  286,  287,  288,  288,  292,  291,  258,
  259,  260,  286,  269,  284,  284,  258,    5,   21,  268,
  269,   33,   65,   61,  273,  274,  112,  132,  277,  278,
  279,  280,  281,  282,   23,  284,   -1,  286,  287,  288,
   -1,   -1,  291,  258,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,  269,   -1,  259,  260,  273,  274,
   -1,  264,  277,  278,  279,  280,  281,  282,  271,  284,
   -1,  286,  287,  288,  273,  274,  291,   -1,  277,  278,
  279,  280,  281,  282,   -1,  288,   -1,   -1,  291,
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
"outblock : var_decl_part forward_decl_part subprog_decl_part statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"forward_decl_part :",
"forward_decl_part : forward_decl_list SEMICOLON",
"forward_decl_list : forward_decl_list SEMICOLON forward_decl",
"forward_decl_list : forward_decl",
"$$2 :",
"forward_decl : FORWARD PROCEDURE IDENT $$2 forward_arg_list",
"$$3 :",
"forward_decl : FORWARD FUNCTION IDENT $$3 forward_arg_list",
"forward_arg_list :",
"forward_arg_list : LPAREN forward_arg RPAREN",
"forward_arg : forward_arg COMMA IDENT",
"forward_arg : IDENT",
"subprog_decl_part :",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"subprog_decl : func_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"$$4 :",
"$$5 :",
"proc_decl : PROCEDURE proc_name LPAREN $$4 id_list $$5 RPAREN SEMICOLON inblock",
"proc_name : IDENT",
"func_decl : FUNCTION func_name SEMICOLON inblock",
"$$6 :",
"$$7 :",
"func_decl : FUNCTION func_name LPAREN $$6 id_list $$7 RPAREN SEMICOLON inblock",
"func_name : IDENT",
"$$8 :",
"inblock : var_decl_part $$8 statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"$$9 :",
"statement : $$9 if_statement",
"$$10 :",
"statement : $$10 while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$11 :",
"assignment_statement : variable $$11 ASSIGN expression",
"variable : IDENT",
"variable : indexed_variable",
"$$12 :",
"indexed_variable : variable LBRACKET expression $$12 RBRACKET",
"$$13 :",
"$$14 :",
"$$15 :",
"if_statement : IF condition $$13 THEN $$14 statement $$15 else_statement",
"else_statement :",
"$$16 :",
"else_statement : ELSE $$16 statement",
"$$17 :",
"$$18 :",
"$$19 :",
"while_statement : WHILE $$17 condition $$18 DO $$19 statement",
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
"$$31 :",
"$$32 :",
"for_statement : FOR IDENT $$20 ASSIGN expression $$21 TO $$22 $$23 $$24 expression $$25 DO $$26 $$27 statement $$28 $$29 $$30 $$31 $$32",
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
"$$33 :",
"expression : MINUS $$33 term",
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
#line 757 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 523 "y.tab.c"

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
case 13:
#line 108 "parser.y"
	{
                insert(yystack.l_mark[0].ident,2);
        }
break;
case 15:
#line 112 "parser.y"
	{
                insert(yystack.l_mark[0].ident,2);
        }
break;
case 21:
#line 129 "parser.y"
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
case 22:
#line 152 "parser.y"
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
case 25:
#line 184 "parser.y"
	{
                delete(); 
                Proc_Term--;
                Factor retval;
                strcpy(retval.val,"void");
                factorpush(retval);
                create_llvmcode(Ret);
        }
break;
case 26:
#line 193 "parser.y"
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
case 28:
#line 211 "parser.y"
	{arity_decl=1;}
break;
case 29:
#line 211 "parser.y"
	{arity_decl=0;}
break;
case 31:
#line 216 "parser.y"
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
case 33:
#line 234 "parser.y"
	{arity_decl=1;}
break;
case 34:
#line 234 "parser.y"
	{arity_decl=0;}
break;
case 36:
#line 238 "parser.y"
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
case 37:
#line 262 "parser.y"
	{Arity_Alloca();}
break;
case 42:
#line 274 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 43:
#line 280 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->end = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 44:
#line 287 "parser.y"
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
case 45:
#line 299 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 46:
#line 308 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 47:
#line 315 "parser.y"
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
case 52:
#line 340 "parser.y"
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
case 53:
#line 350 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 54:
#line 357 "parser.y"
	{
                Factor f_tmp;
                f_tmp = lookup(yystack.l_mark[0].ident);
                factorpush(f_tmp);
                yyval.num = f_tmp.off;
        }
break;
case 55:
#line 364 "parser.y"
	{
                create_llvmcode(GetElem);
        }
break;
case 56:
#line 372 "parser.y"
	{
                Factor f_tmp;
                f_tmp.type = CONSTANT;
                f_tmp.cal = yystack.l_mark[-2].num;
                factorpush(f_tmp);
                create_llvmcode(Sub);
                create_llvmcode(Sext);
        }
break;
case 58:
#line 388 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 59:
#line 392 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 60:
#line 397 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 61:
#line 401 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 63:
#line 413 "parser.y"
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
case 65:
#line 426 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 66:
#line 431 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 67:
#line 435 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 68:
#line 439 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 69:
#line 451 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 70:
#line 455 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 71:
#line 459 "parser.y"
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
case 72:
#line 470 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 73:
#line 474 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 74:
#line 479 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 75:
#line 484 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 76:
#line 487 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 77:
#line 492 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 78:
#line 499 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 79:
#line 504 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 80:
#line 509 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 81:
#line 517 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 82:
#line 520 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 85:
#line 535 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 87:
#line 545 "parser.y"
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
case 88:
#line 565 "parser.y"
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
case 90:
#line 589 "parser.y"
	{ 
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 91:
#line 594 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 92:
#line 599 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 93:
#line 604 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 94:
#line 609 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 95:
#line 614 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 98:
#line 624 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 99:
#line 631 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 100:
#line 635 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 101:
#line 639 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 103:
#line 647 "parser.y"
	{ 
                create_llvmcode(Mul);
        }
break;
case 104:
#line 652 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 105:
#line 659 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 106:
#line 663 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 108:
#line 671 "parser.y"
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
case 110:
#line 700 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 117:
#line 721 "parser.y"
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
case 118:
#line 737 "parser.y"
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
#line 1412 "y.tab.c"
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
