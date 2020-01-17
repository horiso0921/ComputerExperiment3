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
    1,    0,    2,    3,    3,    7,    7,    8,    4,    4,
   10,   10,   13,   11,   14,   11,   12,   12,   15,   15,
    5,    5,   16,   16,   17,   17,   18,   22,   23,   18,
   20,   19,   25,   26,   19,   24,   27,   21,   28,   28,
    6,   31,    6,   33,    6,    6,    6,    6,    6,    6,
    6,   29,   40,   40,   42,   44,   43,   47,   45,   46,
   49,   50,   52,   30,   51,   53,   51,   54,   55,   56,
   32,   57,   58,   59,   60,   61,   62,   63,   64,   65,
   66,   67,   68,   69,   34,   35,   35,   70,   37,   38,
   39,   36,   48,   48,   48,   48,   48,   48,   41,   41,
   73,   41,   41,   41,   72,   72,   72,   74,   74,   74,
   74,   75,   76,   71,   71,    9,    9,   77,   77,   78,
   79,
};
static const short yylen[] = {                            2,
    0,    6,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    0,    5,    0,    5,    0,    3,    3,    1,
    0,    2,    3,    1,    1,    1,    4,    0,    0,    9,
    1,    4,    0,    0,    9,    1,    0,    3,    3,    1,
    1,    0,    2,    0,    2,    1,    1,    1,    1,    1,
    1,    3,    1,    1,    1,    1,    1,    0,    5,    1,
    0,    0,    0,    8,    0,    0,    3,    0,    0,    0,
    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,    1,    4,    1,    3,    4,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    0,    3,    3,    3,    1,    3,    3,    1,    1,    3,
    1,    4,    1,    1,    3,    1,    3,    1,    1,    1,
    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,  116,  118,  119,    2,    0,    0,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
   25,   26,    0,    6,    0,  117,   15,   13,   36,    0,
   31,    0,    0,    0,    0,    0,    0,    3,   41,    0,
    0,   46,   47,   48,   49,   50,   51,    0,   53,   54,
   55,   57,    0,    0,    0,   11,    0,    0,    0,   33,
    0,   28,    0,   40,    0,   72,    0,    0,    0,   43,
   68,   45,    0,    0,    0,   23,    0,    0,   16,   14,
    0,   37,   32,    0,   27,   89,    0,    0,   56,    0,
    0,  101,    0,  109,    0,    0,    0,    0,  105,  111,
    0,    0,   61,    0,    0,    0,    0,    0,  121,   20,
    0,    0,    0,    0,   39,    0,   90,    0,    0,    0,
    0,    0,   91,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   69,    0,   87,    0,   18,    0,    0,
   38,    0,    0,    0,  110,    0,    0,  106,  107,    0,
    0,    0,    0,    0,    0,    0,   62,    0,   59,    0,
   19,    0,    0,    0,  112,    0,   70,    0,    0,   74,
   63,    0,   35,   30,   75,    0,   71,   76,   66,   64,
    0,    0,    0,   67,    0,   78,   79,    0,   80,   81,
   82,   83,   84,   85,
};
static const short yydgoto[] = {                          2,
    3,    7,   92,   18,   28,   48,    9,   10,   12,   19,
   20,   89,   69,   68,  121,   29,   30,   31,   32,   42,
   93,   94,  152,   40,   91,  150,  123,   75,   49,   80,
   50,   82,   51,   52,   53,   54,   55,   56,   57,  106,
  112,   59,   60,   61,   62,   63,  145,  113,  143,  176,
  190,  186,  192,  114,  168,  182,   98,  174,  185,  188,
  191,  195,  197,  198,  200,  201,  202,  203,  204,   64,
  118,  108,  129,  109,  110,  111,   13,   14,   15,
};
static const short yysindex[] = {                      -261,
    0,    0, -276, -266, -242, -201, -244, -140, -160,    0,
 -122,  -81,    0,    0,    0,    0,  -85,  -14, -143,    0,
 -242,  -60, -201,  -82,  -55,  -54,  -48, -215,  -41,    0,
    0,    0, -140,    0,  -40,    0,    0,    0,    0, -258,
    0, -247, -215,  -39,  -29,  -27,    0,    0,    0,   -5,
  -11,    0,    0,    0,    0,    0,    0,  -25,    0,    0,
    0,    0,  -12,   -9,  -14,    0,  -24,   -4,   -4,    0,
 -242,    0, -242,    0, -243,    0,  -13, -121, -121,    0,
    0,    0, -121, -121, -121,    0,   -6,  -10,    0,    0,
 -201,    0,    0, -201,    0,    0, -215,   -7,    0,   -2,
 -235,    0, -121,    0,    0,    0, -187, -169,    0,    0,
    5,  148,    0, -121,  -52,  -52,  -52, -207,    0,    0,
 -141,  -81, -215,  -81,    0, -121,    0, -169, -235, -105,
 -235, -235,    0, -235, -235, -121, -121, -121, -121, -121,
 -121, -121,   15,    0,    3,    0, -121,    0,   -1,    6,
    0,   17,  -52, -169,    0, -169, -169,    0,    0,  -73,
  -52,  -52,  -52,  -52,  -52,  -52,    0,   36,    0,  -52,
    0,   19,   20,   34,    0, -215,    0, -242, -242,    0,
    0, -215,    0,    0,    0,   54,    0,    0,    0,    0,
 -121, -215,  -52,    0,   56,    0,    0, -215,    0,    0,
    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -189,    0,    0, -173,    0,    0,
 -101,   27,    0,    0,    0,    0,    0, -238,    0,    0,
 -251,    0,    0,    0,    0,    0,    0, -240,    0,    0,
    0,    0, -134,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -175,    0,    0,    0,  127,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
    0,    0,    0, -221, -147,    0,    0,   29,   29,    0,
 -106,    0, -106,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -175,    0,    0,   31,
    0,    0,    0,    0,  -84,  -50,    0,  -16,    0,    0,
    0,    0,    0,    0, -156,   32,  -71,    0,    0,    0,
    0,   35, -152,   38,    0,    0,    0,   18,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   55,   52,    0,   86,  120,    0,    0,    0,
 -214, -142, -109,  -91,  -87,  -53,    0,    0,    0,  -67,
    0,    0,    0,    0,    0,  132,    0, -106, -106,    0,
    0,  132,    0,    0,    0, -256,    0,    0,    0,    0,
    0,  132,   65,    0,    0,    0,    0,  132,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  322,    0,    0,  -42,    0,  307,  154,    0,
  302,  268,    0,    0,    0,    0,  276,    0,    0,    0,
  -70,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -28,
  -76,    0,    0,    0,    0,    0,    0,  228,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  211,   10,    0,  -34,    0,    0,  325,    0,    0,
};
#define YYTABLESIZE 430
static const short yytable[] = {                         58,
   74,  107,   95,   65,    1,    5,  115,  116,  117,    5,
    5,    5,    5,    5,   58,    5,   96,    4,   21,    5,
    5,    5,   21,   42,   70,   21,  130,    6,   21,   71,
   44,   65,   21,   21,   65,   72,    5,   86,   86,    5,
   73,   43,    5,   93,   97,   44,   16,  103,  100,  153,
   92,   45,   21,   93,  125,   21,   46,  104,  105,  117,
  161,  162,  163,  164,  165,  166,   86,    4,   58,   86,
  170,    4,    4,    4,    4,    4,  146,    4,   47,  147,
  151,    4,    4,    9,   92,  131,  132,    9,   42,    9,
    9,    9,   11,    9,   58,   44,  133,    9,    9,  158,
  159,    4,   52,   52,    4,  134,  135,  183,  184,   22,
  128,   42,   92,   22,  193,   94,   22,    9,   44,   22,
    9,   17,   10,   22,   22,   94,   10,   21,   10,   10,
   10,   52,   10,  181,   52,   92,   10,   10,  154,  187,
  156,  157,  148,   22,   33,  149,   22,   58,   96,  194,
    4,  101,  102,   58,    4,  199,   10,    4,   96,   10,
    4,  103,   22,   58,    4,    4,   95,  131,  132,   58,
   98,  104,  105,   56,   56,   56,   95,   24,  155,   25,
   98,    4,  120,   56,   56,  120,  120,    4,   56,   56,
   56,   56,   56,   56,   56,   56,   56,   56,  113,   56,
   56,   56,   56,   56,   97,   23,   56,  108,  108,  108,
  175,   37,  114,  147,   97,  114,  115,  108,  108,  115,
  131,  132,  108,  108,  108,  108,  108,  108,  108,  108,
  108,  108,   35,  108,   60,  108,  108,  108,   38,   39,
  108,   99,   99,   99,  122,   41,   65,  124,   26,   67,
   27,   99,   99,   77,   76,   78,   99,   99,   79,   81,
   99,   99,   99,   99,   99,   99,   83,   99,   87,   99,
   99,   99,   84,   85,   99,  100,  100,  100,   88,  119,
   99,  127,  167,  120,  126,  100,  100,  136,  169,  172,
  100,  100,  171,  177,  100,  100,  100,  100,  100,  100,
  173,  100,  180,  100,  100,  100,  178,  179,  100,  102,
  102,  102,  189,  196,    8,   60,   17,   58,   34,  102,
  102,   29,   77,   73,  102,  102,    8,   34,  102,  102,
  102,  102,  102,  102,   66,  102,   90,  102,  102,  102,
   86,  144,  102,  103,  103,  103,  160,   36,    0,    0,
    0,    0,    0,  103,  103,    0,    0,    0,  103,  103,
    0,    0,  103,  103,  103,  103,  103,  103,    0,  103,
    0,  103,  103,  103,    0,    0,  103,  104,  104,  104,
    0,    0,    0,    0,    0,   88,   88,  104,  104,    0,
   92,   92,  104,  104,    0,   42,  104,  104,  104,  104,
  104,  104,   44,  104,    0,  104,  104,  104,    0,   88,
  104,   56,    0,    0,   88,    0,    0,   88,   56,   92,
  131,  132,   92,    0,  137,  138,  139,  140,  141,  142,
};
static const short yycheck[] = {                         28,
   43,   78,   73,  260,  266,  257,   83,   84,   85,  261,
  262,  263,  264,  265,   43,  267,  260,  294,  257,  271,
  272,  288,  261,  264,  283,  264,  103,  270,  267,  288,
  271,  288,  271,  272,  291,  283,  288,  259,  260,  291,
  288,  257,  294,  258,  288,  261,  291,  283,   77,  126,
  291,  267,  291,  268,   97,  294,  272,  293,  294,  136,
  137,  138,  139,  140,  141,  142,  288,  257,   97,  291,
  147,  261,  262,  263,  264,  265,  284,  267,  294,  287,
  123,  271,  272,  257,  260,  273,  274,  261,  264,  263,
  264,  265,  294,  267,  123,  271,  284,  271,  272,  134,
  135,  291,  259,  260,  294,  275,  276,  178,  179,  257,
  101,  264,  288,  261,  191,  258,  264,  291,  271,  267,
  294,  262,  257,  271,  272,  268,  261,  288,  263,  264,
  265,  288,  267,  176,  291,  288,  271,  272,  129,  182,
  131,  132,  284,  291,  288,  287,  294,  176,  258,  192,
  257,  273,  274,  182,  261,  198,  291,  264,  268,  294,
  267,  283,  285,  192,  271,  272,  258,  273,  274,  198,
  258,  293,  294,  258,  259,  260,  268,  263,  284,  265,
  268,  288,  284,  268,  269,  287,  288,  294,  273,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  285,  286,  287,  288,  258,  287,  291,  258,  259,  260,
  284,  294,  284,  287,  268,  287,  284,  268,  269,  287,
  273,  274,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  293,  284,  285,  286,  287,  288,  294,  294,
  291,  258,  259,  260,   91,  294,  288,   94,  263,  290,
  265,  268,  269,  283,  294,  283,  273,  274,  264,  271,
  277,  278,  279,  280,  281,  282,  292,  284,  293,  286,
  287,  288,  285,  283,  291,  258,  259,  260,  283,  286,
  294,  284,  268,  294,  292,  268,  269,  283,  286,  284,
  273,  274,  294,  258,  277,  278,  279,  280,  281,  282,
  284,  284,  269,  286,  287,  288,  288,  288,  291,  258,
  259,  260,  259,  258,  288,  285,  288,  286,  284,  268,
  269,  284,  258,  269,  273,  274,    5,   21,  277,  278,
  279,  280,  281,  282,   33,  284,   69,  286,  287,  288,
   65,  114,  291,  258,  259,  260,  136,   23,   -1,   -1,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,  286,  287,  288,   -1,   -1,  291,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,  259,  260,  268,  269,   -1,
  259,  260,  273,  274,   -1,  264,  277,  278,  279,  280,
  281,  282,  271,  284,   -1,  286,  287,  288,   -1,  283,
  291,  285,   -1,   -1,  288,   -1,   -1,  291,  292,  288,
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
"assignment_statement : variable ASSIGN expression",
"variable : entire_variable",
"variable : component_variable",
"entire_variable : variable_id",
"variable_id : IDENT",
"component_variable : indexed_variable",
"$$11 :",
"indexed_variable : array_variable LBRACKET expression $$11 RBRACKET",
"array_variable : variable",
"$$12 :",
"$$13 :",
"$$14 :",
"if_statement : IF condition $$12 THEN $$13 statement $$14 else_statement",
"else_statement :",
"$$15 :",
"else_statement : ELSE $$15 statement",
"$$16 :",
"$$17 :",
"$$18 :",
"while_statement : WHILE $$16 condition $$17 DO $$18 statement",
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
"$$31 :",
"for_statement : FOR IDENT $$19 ASSIGN expression $$20 TO $$21 $$22 $$23 expression $$24 DO $$25 $$26 statement $$27 $$28 $$29 $$30 $$31",
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
"$$32 :",
"expression : MINUS $$32 term",
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
#line 751 "parser.y"
 

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
#line 55 "parser.y"
	{init_fstack();}
break;
case 2:
#line 56 "parser.y"
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
#line 107 "parser.y"
	{
                insert(yystack.l_mark[0].ident,2);
        }
break;
case 15:
#line 111 "parser.y"
	{
                insert(yystack.l_mark[0].ident,2);
        }
break;
case 21:
#line 128 "parser.y"
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
#line 151 "parser.y"
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
#line 183 "parser.y"
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
#line 192 "parser.y"
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
#line 210 "parser.y"
	{arity_decl=1;}
break;
case 29:
#line 210 "parser.y"
	{arity_decl=0;}
break;
case 31:
#line 215 "parser.y"
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
#line 233 "parser.y"
	{arity_decl=1;}
break;
case 34:
#line 233 "parser.y"
	{arity_decl=0;}
break;
case 36:
#line 237 "parser.y"
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
#line 261 "parser.y"
	{Arity_Alloca();}
break;
case 42:
#line 273 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 43:
#line 279 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->end = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 44:
#line 286 "parser.y"
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
#line 298 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 46:
#line 307 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 47:
#line 314 "parser.y"
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
#line 339 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 54:
#line 347 "parser.y"
	{
                create_llvmcode(GetElem);
        }
break;
case 56:
#line 358 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 58:
#line 369 "parser.y"
	{
                create_llvmcode(Sext);
        }
break;
case 61:
#line 382 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 62:
#line 386 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 63:
#line 391 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 64:
#line 395 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 66:
#line 407 "parser.y"
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
case 68:
#line 420 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 69:
#line 425 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 70:
#line 429 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 71:
#line 433 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 72:
#line 445 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 73:
#line 449 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 74:
#line 453 "parser.y"
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
case 75:
#line 464 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 76:
#line 468 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 77:
#line 473 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 78:
#line 478 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 79:
#line 481 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 80:
#line 486 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 81:
#line 493 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 82:
#line 498 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 83:
#line 503 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 84:
#line 511 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 85:
#line 514 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 88:
#line 529 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 90:
#line 539 "parser.y"
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
case 91:
#line 559 "parser.y"
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
case 93:
#line 583 "parser.y"
	{ 
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 94:
#line 588 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 95:
#line 593 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 96:
#line 598 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 97:
#line 603 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 98:
#line 608 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 101:
#line 618 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 102:
#line 625 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 103:
#line 629 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 104:
#line 633 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 106:
#line 641 "parser.y"
	{ 
                create_llvmcode(Mul);
        }
break;
case 107:
#line 646 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 108:
#line 653 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 109:
#line 657 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 111:
#line 665 "parser.y"
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
case 113:
#line 694 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 120:
#line 715 "parser.y"
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
case 121:
#line 731 "parser.y"
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
#line 1399 "y.tab.c"
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
