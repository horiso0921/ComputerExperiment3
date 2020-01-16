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
   49,   50,   30,   51,   52,   51,   53,   54,   55,   32,
   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,
   66,   67,   68,   34,   35,   35,   69,   37,   38,   39,
   36,   48,   48,   48,   48,   48,   48,   41,   41,   72,
   41,   41,   41,   71,   71,   71,   73,   73,   73,   73,
   74,   75,   70,   70,    9,    9,   76,   76,   77,   78,
};
static const short yylen[] = {                            2,
    0,    6,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    0,    5,    0,    5,    0,    3,    3,    1,
    0,    2,    3,    1,    1,    1,    4,    0,    0,    9,
    1,    4,    0,    0,    9,    1,    0,    3,    3,    1,
    1,    0,    2,    0,    2,    1,    1,    1,    1,    1,
    1,    3,    1,    1,    1,    1,    1,    0,    5,    1,
    0,    0,    7,    0,    0,    3,    0,    0,    0,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   21,    1,    4,    1,    3,    4,    4,
    0,    3,    3,    3,    3,    3,    3,    1,    2,    0,
    3,    3,    3,    1,    3,    3,    1,    1,    3,    1,
    4,    1,    1,    3,    1,    3,    1,    1,    1,    6,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,  115,  117,  118,    2,    0,    0,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
   25,   26,    0,    6,    0,  116,   15,   13,   36,    0,
   31,    0,    0,    0,    0,    0,    0,    3,   41,    0,
    0,   46,   47,   48,   49,   50,   51,    0,   53,   54,
   55,   57,    0,    0,    0,   11,    0,    0,    0,   33,
    0,   28,    0,   40,    0,   71,    0,    0,    0,   43,
   67,   45,    0,    0,    0,   23,    0,    0,   16,   14,
    0,   37,   32,    0,   27,   88,    0,    0,   56,    0,
    0,  100,    0,  108,    0,    0,    0,    0,  104,  110,
    0,    0,   61,    0,    0,    0,    0,    0,  120,   20,
    0,    0,    0,    0,   39,    0,   89,    0,    0,    0,
    0,    0,   90,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   68,    0,   86,    0,   18,    0,    0,
   38,    0,    0,    0,  109,    0,    0,  105,  106,    0,
    0,    0,    0,    0,    0,    0,   62,    0,   59,    0,
   19,    0,    0,    0,  111,    0,   69,    0,    0,   73,
    0,    0,   35,   30,   74,   65,   63,   70,   75,    0,
    0,   66,    0,    0,   77,   78,    0,   79,   80,   81,
   82,   83,   84,
};
static const short yydgoto[] = {                          2,
    3,    7,   92,   18,   28,   48,    9,   10,   12,   19,
   20,   89,   69,   68,  121,   29,   30,   31,   32,   42,
   93,   94,  152,   40,   91,  150,  123,   75,   49,   80,
   50,   82,   51,   52,   53,   54,   55,   56,   57,  106,
  112,   59,   60,   61,   62,   63,  145,  113,  143,  176,
  187,  190,  114,  168,  182,   98,  174,  185,  189,  191,
  194,  196,  197,  199,  200,  201,  202,  203,   64,  118,
  108,  129,  109,  110,  111,   13,   14,   15,
};
static const short yysindex[] = {                      -261,
    0,    0, -280, -248, -218, -206, -195, -161, -173,    0,
 -162, -141,    0,    0,    0,    0, -238, -136, -150,    0,
 -218, -142, -206, -122, -120, -115, -111, -224, -101,    0,
    0,    0, -161,    0,  -68,    0,    0,    0,    0, -229,
    0, -228, -224, -105,  -53,  -52,    0,    0,    0,  -21,
  -12,    0,    0,    0,    0,    0,    0,  -42,    0,    0,
    0,    0,  -25,  -22, -136,    0,  -27,  -19,  -19,    0,
 -218,    0, -218,    0, -242,    0,  -17,   -4,   -4,    0,
    0,    0,   -4,   -4,   -4,    0,   -3,  -10,    0,    0,
 -206,    0,    0, -206,    0,    0, -224,   -1,    0,    8,
 -180,    0,   -4,    0,    0,    0, -267,  -79,    0,    0,
  -18,  146,    0,   -4,  -58,  -58,  -58, -121,    0,    0,
  -94, -141, -224, -141,    0,   -4,    0,  -79, -180, -216,
 -180, -180,    0, -180, -180,   -4,   -4,   -4,   -4,   -4,
   -4,   -4,   25,    0,    9,    0,   -4,    0,    4,   10,
    0,   15,  -58,  -79,    0,  -79,  -79,    0,    0,  -61,
  -58,  -58,  -58,  -58,  -58,  -58,    0,   42,    0,  -58,
    0,   16,   23,   34,    0, -224,    0, -218, -218,    0,
   54, -224,    0,    0,    0,    0,    0,    0,    0, -224,
   -4,    0,  -58,   59,    0,    0, -224,    0,    0,    0,
    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -186,    0,    0, -174,    0,    0,
 -106,   30,    0,    0,    0,    0,    0, -127,    0,    0,
 -241,    0,    0,    0,    0,    0,    0, -191,    0,    0,
    0,    0, -139,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -39,    0,    0,    0, -247,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,    0,    0,
    0,    0,    0, -149, -114,    0,    0,   36,   36,    0,
  -96,    0,  -96,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -39,    0,    0,   38,
    0,    0,    0,    0,  -74,  -40,    0,   -6,    0,    0,
    0,    0,    0,    0, -100,   39,  -60,    0,    0,    0,
    0,   43, -152,   44,    0,    0,    0,   28,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   57,   62,    0,   96,  130,    0,    0,    0,
 -239, -184, -166, -164, -159, -137,    0,    0,    0,  -29,
    0,    0,    0,    0,    0,  142,    0,  -96,  -96,    0,
 -249,  142,    0,    0,    0,    0,    0,    0,    0,  142,
    0,    0,   71,    0,    0,    0,  142,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  327,    0,    0,  -41,    0,  312,   79,    0,
  301,  268,    0,    0,    0,    0,  273,    0,    0,    0,
  -72,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -28,
  -75,    0,    0,    0,    0,    0,    0,  231,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  211,
  -97,    0,  122,    0,    0,  328,    0,    0,
};
#define YYTABLESIZE 433
static const short yytable[] = {                         58,
   95,   74,  107,  128,    1,  131,  132,  115,  116,  117,
   64,   87,   87,    4,   58,    5,  133,   96,   92,    5,
    5,    5,    5,    5,   24,    5,   25,  130,   92,    5,
    5,  154,   43,  156,  157,   87,   44,   56,   64,    5,
   87,   64,   45,   87,   56,   97,    5,   46,  100,    5,
  153,    6,    5,   70,   72,  125,  131,  132,   71,   73,
  117,  161,  162,  163,  164,  165,  166,  155,   58,   47,
    4,  170,   42,   93,    4,    4,    4,    4,    4,   44,
    4,  151,    9,   93,    4,    4,    9,   11,    9,    9,
    9,   95,    9,   94,   58,   16,    9,    9,   97,   91,
   17,   95,  103,   94,    4,  183,  184,    4,   97,   85,
   85,   42,  104,  105,   21,  193,    9,   10,   44,    9,
   96,   10,   22,   10,   10,   10,   26,   10,   27,   21,
   96,   10,   10,   21,  181,   91,   21,   33,   85,   21,
  188,   85,   22,   21,   21,   23,   22,   58,  192,   22,
   35,   10,   22,   58,   10,  198,   22,   22,   52,   52,
    4,   58,  146,   21,    4,  147,   21,    4,   58,  122,
    4,   37,  124,   38,    4,    4,   22,  119,   39,   22,
  119,  119,   41,   56,   56,   56,   65,   52,   76,  148,
   52,    4,  149,   56,   56,  134,  135,    4,   56,   56,
   56,   56,   56,   56,   56,   56,   56,   56,  112,   56,
   56,   56,   56,   56,  131,  132,   56,  107,  107,  107,
   91,   67,  175,  113,   42,  147,  113,  107,  107,   77,
   78,   44,  107,  107,  107,  107,  107,  107,  107,  107,
  107,  107,   79,  107,   60,  107,  107,  107,   91,   83,
  107,   98,   98,   98,  114,  158,  159,  114,   81,   84,
   85,   98,   98,   88,  136,   87,   98,   98,  101,  102,
   98,   98,   98,   98,   98,   98,   99,   98,  103,   98,
   98,   98,  119,  120,   98,   99,   99,   99,  104,  105,
  126,  127,  167,  172,  169,   99,   99,  171,  173,  177,
   99,   99,  180,  178,   99,   99,   99,   99,   99,   99,
  179,   99,  186,   99,   99,   99,  195,    8,   99,  101,
  101,  101,   60,   17,   58,   72,   34,   29,   76,  101,
  101,    8,   34,   66,  101,  101,   90,   86,  101,  101,
  101,  101,  101,  101,  144,  101,  160,  101,  101,  101,
   36,    0,  101,  102,  102,  102,    0,    0,    0,    0,
    0,    0,    0,  102,  102,    0,    0,    0,  102,  102,
    0,    0,  102,  102,  102,  102,  102,  102,    0,  102,
    0,  102,  102,  102,    0,    0,  102,  103,  103,  103,
    0,    0,    0,    0,    0,    0,    0,  103,  103,    0,
   91,   91,  103,  103,    0,   42,  103,  103,  103,  103,
  103,  103,   44,  103,    0,  103,  103,  103,  131,  132,
  103,    0,  137,  138,  139,  140,  141,  142,    0,   91,
    0,    0,   91,
};
static const short yycheck[] = {                         28,
   73,   43,   78,  101,  266,  273,  274,   83,   84,   85,
  260,  259,  260,  294,   43,  257,  284,  260,  258,  261,
  262,  263,  264,  265,  263,  267,  265,  103,  268,  271,
  272,  129,  257,  131,  132,  283,  261,  285,  288,  288,
  288,  291,  267,  291,  292,  288,  288,  272,   77,  291,
  126,  270,  294,  283,  283,   97,  273,  274,  288,  288,
  136,  137,  138,  139,  140,  141,  142,  284,   97,  294,
  257,  147,  264,  258,  261,  262,  263,  264,  265,  271,
  267,  123,  257,  268,  271,  272,  261,  294,  263,  264,
  265,  258,  267,  258,  123,  291,  271,  272,  258,  291,
  262,  268,  283,  268,  291,  178,  179,  294,  268,  259,
  260,  264,  293,  294,  288,  191,  291,  257,  271,  294,
  258,  261,  285,  263,  264,  265,  263,  267,  265,  257,
  268,  271,  272,  261,  176,  288,  264,  288,  288,  267,
  182,  291,  257,  271,  272,  287,  261,  176,  190,  264,
  293,  291,  267,  182,  294,  197,  271,  272,  259,  260,
  257,  190,  284,  291,  261,  287,  294,  264,  197,   91,
  267,  294,   94,  294,  271,  272,  291,  284,  294,  294,
  287,  288,  294,  258,  259,  260,  288,  288,  294,  284,
  291,  288,  287,  268,  269,  275,  276,  294,  273,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  285,  286,  287,  288,  273,  274,  291,  258,  259,  260,
  260,  290,  284,  284,  264,  287,  287,  268,  269,  283,
  283,  271,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  264,  284,  285,  286,  287,  288,  288,  292,
  291,  258,  259,  260,  284,  134,  135,  287,  271,  285,
  283,  268,  269,  283,  283,  293,  273,  274,  273,  274,
  277,  278,  279,  280,  281,  282,  294,  284,  283,  286,
  287,  288,  286,  294,  291,  258,  259,  260,  293,  294,
  292,  284,  268,  284,  286,  268,  269,  294,  284,  258,
  273,  274,  269,  288,  277,  278,  279,  280,  281,  282,
  288,  284,  259,  286,  287,  288,  258,  288,  291,  258,
  259,  260,  285,  288,  286,  269,  284,  284,  258,  268,
  269,    5,   21,   33,  273,  274,   69,   65,  277,  278,
  279,  280,  281,  282,  114,  284,  136,  286,  287,  288,
   23,   -1,  291,  258,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,  286,  287,  288,   -1,   -1,  291,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,
  259,  260,  273,  274,   -1,  264,  277,  278,  279,  280,
  281,  282,  271,  284,   -1,  286,  287,  288,  273,  274,
  291,   -1,  277,  278,  279,  280,  281,  282,   -1,  288,
   -1,   -1,  291,
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
"if_statement : IF condition $$12 THEN $$13 statement else_statement",
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
#line 762 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 529 "y.tab.c"

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
                if_flg = 0;
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 43:
#line 281 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                if (if_flg) br_decl->eluncoll = br_decl->uncoll;
                Last_Register ++;
                br_decl = br_decl->before;
                if_flg = 0;
        }
break;
case 44:
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
case 45:
#line 302 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 46:
#line 311 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 47:
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
case 52:
#line 344 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 54:
#line 352 "parser.y"
	{
                create_llvmcode(GetElem);
        }
break;
case 56:
#line 363 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 58:
#line 374 "parser.y"
	{
                create_llvmcode(Sext);
        }
break;
case 61:
#line 387 "parser.y"
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
case 62:
#line 398 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 63:
#line 403 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->uncoll;
                add_llvmnode(tmp);
        }
break;
case 64:
#line 414 "parser.y"
	{ if_flg = 1;}
break;
case 65:
#line 416 "parser.y"
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
case 67:
#line 430 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 68:
#line 435 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 69:
#line 439 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 70:
#line 443 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 71:
#line 455 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 72:
#line 459 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 73:
#line 463 "parser.y"
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
#line 474 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 75:
#line 478 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 76:
#line 483 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 77:
#line 488 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 78:
#line 491 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 79:
#line 496 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 80:
#line 503 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 81:
#line 508 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 82:
#line 513 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 83:
#line 521 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 84:
#line 524 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 87:
#line 539 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 89:
#line 549 "parser.y"
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
#line 569 "parser.y"
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
#line 593 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 93:
#line 598 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 94:
#line 603 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 95:
#line 608 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 96:
#line 613 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 97:
#line 618 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 100:
#line 628 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 101:
#line 635 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 102:
#line 639 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 103:
#line 643 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 105:
#line 651 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 106:
#line 656 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 107:
#line 663 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 108:
#line 667 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 110:
#line 676 "parser.y"
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
#line 705 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 119:
#line 726 "parser.y"
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
#line 742 "parser.y"
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
#line 1408 "y.tab.c"
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
