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
   16,   16,    6,    6,   17,   17,   18,   18,   19,   23,
   24,   19,   21,   20,   26,   27,   20,   25,   28,   22,
   29,   29,    7,   32,    7,   34,    7,    7,    7,    7,
    7,    7,    7,   41,   30,    1,    1,   44,   43,   46,
   47,   49,   31,   48,   50,   48,   51,   52,   53,   33,
   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   35,   36,   36,   67,   38,   39,   40,
   37,   45,   45,   45,   45,   45,   45,   42,   42,   70,
   42,   42,   42,   69,   69,   69,   71,   71,   71,   71,
   72,   73,   68,   68,   10,   10,   74,   74,   75,   76,
};
static const short yylen[] = {                            2,
    0,    6,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    0,    5,    0,    5,    0,    3,    3,    8,
    1,    6,    0,    2,    3,    1,    1,    1,    4,    0,
    0,    9,    1,    4,    0,    0,    9,    1,    0,    3,
    3,    1,    1,    0,    2,    0,    2,    1,    1,    1,
    1,    1,    1,    0,    4,    1,    1,    0,    5,    0,
    0,    0,    8,    0,    0,    3,    0,    0,    0,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   21,    1,    4,    1,    3,    4,    4,
    0,    3,    3,    3,    3,    3,    3,    1,    2,    0,
    3,    3,    3,    1,    3,    3,    1,    1,    3,    1,
    4,    1,    1,    3,    1,    3,    1,    1,    1,    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,  115,  117,  118,    2,    0,    0,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   26,
   27,   28,    0,    6,    0,  116,   15,   13,   38,    0,
   33,    0,    0,    0,    0,    0,    0,    0,    3,   43,
    0,    0,   48,   49,   50,   51,   52,   53,   57,    0,
    0,   11,    0,    0,    0,   35,    0,   30,    0,   42,
    0,   71,    0,    0,    0,    0,    0,   45,   67,   47,
    0,   25,    0,    0,   16,   14,    0,   39,   34,    0,
   29,   88,    0,    0,   56,    0,    0,  100,    0,  108,
    0,    0,    0,    0,  104,  110,    0,    0,    0,    0,
   60,    0,    0,    0,  120,    0,    0,    0,    0,    0,
   41,    0,   89,    0,    0,    0,    0,    0,   90,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   68,   86,    0,    0,   18,    0,    0,   40,    0,
    0,    0,  109,    0,    0,  105,  106,    0,   59,    0,
    0,    0,    0,    0,    0,   61,    0,    0,    0,    0,
    0,    0,    0,  111,    0,   69,    0,    0,    0,    0,
   73,   62,    0,    0,    0,   37,   32,   74,    0,   70,
   22,    0,   75,   65,   63,    0,    0,    0,   20,    0,
   66,    0,   77,   78,    0,   79,   80,   81,   82,   83,
   84,
};
static const short yydgoto[] = {                          2,
  102,    3,    7,   88,   18,   28,   49,    9,   10,   12,
   19,   20,   85,   65,   64,  117,   29,   30,   31,   32,
   42,   89,   90,  150,   40,   87,  148,  119,   71,   50,
   78,   51,   80,   52,   53,   54,   55,   56,   57,   58,
   76,  110,   59,  133,  111,  141,  175,  195,  189,  198,
  112,  167,  183,   94,  173,  188,  193,  197,  202,  204,
  205,  207,  208,  209,  210,  211,   60,  114,  104,  125,
  105,  106,  107,   13,   14,   15,
};
static const short yysindex[] = {                      -241,
    0,    0, -248, -190, -163, -191, -173, -137, -161,    0,
 -128, -135,    0,    0,    0,    0, -205, -178, -100,    0,
 -163,  -73, -191,  -72,  -66,  -54,  -52, -218,  -61,    0,
    0,    0, -137,    0,  -37,    0,    0,    0,    0, -272,
    0, -226, -218,  -33,  -62,  -21,    0,  -22,    0,    0,
   10,    5,    0,    0,    0,    0,    0,    0,    0,   -3,
 -178,    0,  -12,   13,   13,    0, -163,    0, -163,    0,
 -236,    0,    7,  -27,  -27,   16,  -27,    0,    0,    0,
  -27,    0,   24,   20,    0,    0, -191,    0,    0, -191,
    0,    0, -218,   23,    0, -277, -177,    0,  -27,    0,
    0,  -22, -113,  -89,    0,    0,   37,  -80,  -27,  143,
    0,  -27,  -80, -223,    0,   36, -133, -135, -218, -135,
    0,  -27,    0,  -89, -177,  -55, -177, -177,    0, -177,
 -177,  -27,   38,  -80,  -27,  -27,  -27,  -27,  -27,  -27,
   54,    0,    0,  -27,   30,    0,   31,   42,    0,   45,
  -80,  -89,    0,  -89,  -89,    0,    0, -118,    0,  -80,
  -80,  -80,  -80,  -80,  -80,    0,   72,  -80,   41,   49,
   47,   56,   73,    0, -218,    0,   55,   61, -163, -163,
    0,    0, -218,   63,   65,    0,    0,    0,   97,    0,
    0,   64,    0,    0,    0,   74,  -27, -218,    0,  -80,
    0,  100,    0,    0, -218,    0,    0,    0,    0,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -183,    0,    0, -171,    0,    0,
  -30,   71,    0,    0,    0,    0,    0, -235,    0,    0,
 -244,    0,    0,    0,    0,    0,    0, -167,    0,    0,
    0,    0, -127,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -129,    0,    0,    0, -250,   76,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -138,
 -162,    0,    0,   75,   75,    0,  -99,    0,  -99,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -129,    0,    0,    0,    0,    0,    0,    0,
  -77,  -43,    0,   -9,    0,    0,    0,   78,    0,    0,
    0,    0,    2,    0,    0,    3,    0,   81, -216,   85,
    0,    0,    0,   25,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -36,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  107,   59,    0,   93,  127,    0,    0,    0,    0, -254,
 -185, -119,  -84,  -83,  -78,    0,    0,    4,    0,    8,
    0,    0,    0,    0, -145,    0,    0,    0,  -99,  -99,
    0,    0, -145,    0,    0,    0,    0,    0, -257,    0,
    0,    0,    0,    0,    0,    0,    0, -145,    0,  120,
    0,    0,    0,    0, -145,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
  -28,    0,    0,  377,    0,    0,  -42,    0,  362,  210,
    0,  355,  324,    0,    0,    0,    0,  329,    0,    0,
    0,  -67,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -69,    0,    0,  279,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  260,   51,    0,
   82,    0,    0,  370,    0,    0,
};
#define YYTABLESIZE 425
static const short yytable[] = {                         48,
   70,   91,   64,   92,  103,  108,  123,   75,   87,   87,
   66,  113,    5,   92,   48,   67,    5,    5,    5,    5,
    5,   23,    5,   92,    1,   23,    5,    5,   23,  126,
   64,   23,   87,   64,   56,   23,   23,   87,   43,  134,
   87,   56,   44,    5,   96,    4,    5,   44,   45,    5,
  121,   93,  151,   46,   46,   23,   68,   24,   23,   25,
  143,   69,  113,  144,   48,  160,  161,  162,  163,  164,
  165,   91,   93,    4,  168,   47,  149,    4,    4,    4,
    4,    4,   93,    4,   26,    9,   27,    4,    4,    9,
   48,    9,    9,    9,   24,    9,   44,    5,   24,    9,
    9,   24,   11,   46,   24,   99,    6,    4,   24,   24,
    4,  186,  187,   91,   91,  100,  101,   16,   44,    9,
   85,   85,    9,   91,   17,   46,   21,  200,   24,   10,
   91,   24,  182,   10,   44,   10,   10,   10,   95,   10,
  190,   46,   91,   10,   10,   91,   48,  124,   95,   85,
  146,   23,   85,  147,   48,  201,   22,    4,   91,  127,
  128,    4,  206,   10,    4,  174,   10,    4,  144,   48,
  129,    4,    4,   94,   97,  152,   48,  154,  155,   96,
   56,   56,   56,   94,   97,  130,  131,   33,    4,   96,
   56,   56,  127,  128,    4,   56,   56,   56,   56,   56,
   56,   56,   56,   56,   56,  112,   56,   56,   56,   56,
   56,  156,  157,   56,  107,  107,  107,  127,  128,   35,
   73,   37,   55,   55,  107,  107,   61,   38,  153,  107,
  107,  107,  107,  107,  107,  107,  107,  107,  107,   39,
  107,   41,  107,  107,  107,   97,   98,  107,   98,   98,
   98,   55,   63,  119,   55,   99,  119,  119,   98,   98,
   72,   74,   75,   98,   98,  100,  101,   98,   98,   98,
   98,   98,   98,   77,   98,   79,   98,   98,   98,   81,
   83,   98,   99,   99,   99,  113,   21,  114,  113,   21,
  114,   19,   99,   99,   19,   84,  118,   99,   99,  120,
   95,   99,   99,   99,   99,   99,   99,  109,   99,  115,
   99,   99,   99,  116,  122,   99,  101,  101,  101,  132,
  145,  166,  169,  159,  170,  171,  101,  101,  172,  176,
  177,  101,  101,  178,  179,  101,  101,  101,  101,  101,
  101,  181,  101,  180,  101,  101,  101,  184,  191,  101,
  102,  102,  102,  185,  192,  194,  196,  203,    8,  199,
  102,  102,   17,   58,   36,  102,  102,   54,   31,  102,
  102,  102,  102,  102,  102,   72,  102,   76,  102,  102,
  102,    8,   34,  102,  103,  103,  103,   62,   86,   82,
  142,  158,   36,    0,  103,  103,    0,    0,    0,  103,
  103,    0,    0,  103,  103,  103,  103,  103,  103,    0,
  103,    0,  103,  103,  103,  127,  128,  103,    0,  135,
  136,  137,  138,  139,  140,
};
static const short yycheck[] = {                         28,
   43,   69,  260,  258,   74,   75,  284,  285,  259,  260,
  283,   81,  257,  268,   43,  288,  261,  262,  263,  264,
  265,  257,  267,  260,  266,  261,  271,  272,  264,   99,
  288,  267,  283,  291,  285,  271,  272,  288,  257,  109,
  291,  292,  261,  288,   73,  294,  291,  264,  267,  294,
   93,  288,  122,  272,  271,  291,  283,  263,  294,  265,
  284,  288,  132,  287,   93,  135,  136,  137,  138,  139,
  140,  288,  258,  257,  144,  294,  119,  261,  262,  263,
  264,  265,  268,  267,  263,  257,  265,  271,  272,  261,
  119,  263,  264,  265,  257,  267,  264,  288,  261,  271,
  272,  264,  294,  271,  267,  283,  270,  291,  271,  272,
  294,  179,  180,  259,  260,  293,  294,  291,  264,  291,
  259,  260,  294,  291,  262,  271,  288,  197,  291,  257,
  260,  294,  175,  261,  264,  263,  264,  265,  258,  267,
  183,  271,  288,  271,  272,  291,  175,   97,  268,  288,
  284,  287,  291,  287,  183,  198,  285,  257,  288,  273,
  274,  261,  205,  291,  264,  284,  294,  267,  287,  198,
  284,  271,  272,  258,  258,  125,  205,  127,  128,  258,
  258,  259,  260,  268,  268,  275,  276,  288,  288,  268,
  268,  269,  273,  274,  294,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  287,
  288,  130,  131,  291,  258,  259,  260,  273,  274,  293,
  283,  294,  259,  260,  268,  269,  288,  294,  284,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  294,
  284,  294,  286,  287,  288,  273,  274,  291,  258,  259,
  260,  288,  290,  284,  291,  283,  287,  288,  268,  269,
  294,  283,  285,  273,  274,  293,  294,  277,  278,  279,
  280,  281,  282,  264,  284,  271,  286,  287,  288,  283,
  293,  291,  258,  259,  260,  284,  284,  284,  287,  287,
  287,  284,  268,  269,  287,  283,   87,  273,  274,   90,
  294,  277,  278,  279,  280,  281,  282,  292,  284,  286,
  286,  287,  288,  294,  292,  291,  258,  259,  260,  283,
  285,  268,  293,  286,  294,  284,  268,  269,  284,  258,
  290,  273,  274,  285,  288,  277,  278,  279,  280,  281,
  282,  269,  284,  288,  286,  287,  288,  293,  286,  291,
  258,  259,  260,  293,  290,  259,  293,  258,  288,  286,
  268,  269,  288,  286,  284,  273,  274,  292,  284,  277,
  278,  279,  280,  281,  282,  269,  284,  258,  286,  287,
  288,    5,   21,  291,  258,  259,  260,   33,   65,   61,
  112,  132,   23,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,   -1,  286,  287,  288,  273,  274,  291,   -1,  277,
  278,  279,  280,  281,  282,
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
"forward_arg : forward_arg COMMA IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",
"forward_arg : IDENT",
"forward_arg : IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",
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
#line 760 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 530 "y.tab.c"

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
case 23:
#line 132 "parser.y"
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
case 24:
#line 155 "parser.y"
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
case 27:
#line 187 "parser.y"
	{
                delete(); 
                Proc_Term--;
                Factor retval;
                strcpy(retval.val,"void");
                factorpush(retval);
                create_llvmcode(Ret);
        }
break;
case 28:
#line 196 "parser.y"
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
case 30:
#line 214 "parser.y"
	{arity_decl=1;}
break;
case 31:
#line 214 "parser.y"
	{arity_decl=0;}
break;
case 33:
#line 219 "parser.y"
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
case 35:
#line 237 "parser.y"
	{arity_decl=1;}
break;
case 36:
#line 237 "parser.y"
	{arity_decl=0;}
break;
case 38:
#line 241 "parser.y"
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
case 39:
#line 265 "parser.y"
	{Arity_Alloca();}
break;
case 44:
#line 277 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 45:
#line 283 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->end = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 46:
#line 290 "parser.y"
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
case 47:
#line 302 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 48:
#line 311 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 49:
#line 318 "parser.y"
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
case 54:
#line 343 "parser.y"
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
case 55:
#line 353 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 56:
#line 360 "parser.y"
	{
                Factor f_tmp;
                f_tmp = lookup(yystack.l_mark[0].ident);
                factorpush(f_tmp);
                yyval.num = f_tmp.off;
        }
break;
case 57:
#line 367 "parser.y"
	{
                create_llvmcode(GetElem);
        }
break;
case 58:
#line 375 "parser.y"
	{
                Factor f_tmp;
                f_tmp.type = CONSTANT;
                f_tmp.cal = yystack.l_mark[-2].num;
                factorpush(f_tmp);
                create_llvmcode(Sub);
                create_llvmcode(Sext);
        }
break;
case 60:
#line 391 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 61:
#line 395 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 62:
#line 400 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 63:
#line 404 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 65:
#line 416 "parser.y"
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
case 67:
#line 429 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 68:
#line 434 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 69:
#line 438 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 70:
#line 442 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 71:
#line 454 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 72:
#line 458 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 73:
#line 462 "parser.y"
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
case 74:
#line 473 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 75:
#line 477 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 76:
#line 482 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 77:
#line 487 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 78:
#line 490 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 79:
#line 495 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 80:
#line 502 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 81:
#line 507 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 82:
#line 512 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 83:
#line 520 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 84:
#line 523 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 87:
#line 538 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 89:
#line 548 "parser.y"
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
case 90:
#line 568 "parser.y"
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
case 92:
#line 592 "parser.y"
	{ 
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 93:
#line 597 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 94:
#line 602 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 95:
#line 607 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 96:
#line 612 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 97:
#line 617 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 100:
#line 627 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 101:
#line 634 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 102:
#line 638 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 103:
#line 642 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 105:
#line 650 "parser.y"
	{ 
                create_llvmcode(Mul);
        }
break;
case 106:
#line 655 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 107:
#line 662 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 108:
#line 666 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 110:
#line 674 "parser.y"
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
case 112:
#line 703 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 119:
#line 724 "parser.y"
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
case 120:
#line 740 "parser.y"
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
#line 1419 "y.tab.c"
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
