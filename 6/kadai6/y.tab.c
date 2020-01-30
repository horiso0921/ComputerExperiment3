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

#line 31 "parser.y"
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
#line 59 "y.tab.c"

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
    9,    9,   10,   11,   14,   15,   11,   12,   16,   13,
   17,   17,    5,   20,    5,   22,    5,    5,    5,    5,
    5,    5,    5,   29,   18,   32,   33,   35,   19,   34,
   36,   34,   37,   38,   39,   21,   40,   41,   42,   43,
   44,   23,   24,   24,   45,   26,   47,   27,   28,   25,
   31,   31,   31,   31,   31,   31,   30,   30,   49,   30,
   30,   30,   48,   48,   48,   50,   50,   50,   51,   46,
   46,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    0,    0,    9,    1,    0,    3,
    3,    1,    1,    0,    2,    0,    2,    1,    1,    1,
    1,    1,    1,    0,    4,    0,    0,    0,    8,    0,
    0,    3,    0,    0,    0,    7,    0,    0,    0,    0,
    0,   13,    1,    4,    1,    3,    0,    5,    4,    0,
    3,    3,    3,    3,    3,    3,    1,    2,    0,    3,
    3,    3,    1,    3,    3,    1,    1,    3,    1,    1,
    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   82,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   18,    0,    0,    0,    0,    0,    0,    3,   23,    0,
    0,   28,   29,   30,   31,   32,   33,    0,    0,    6,
   83,   15,    0,   22,    0,   47,    0,    0,    0,    0,
   25,   43,   27,    0,   11,    0,   19,   14,   56,    0,
    0,   57,    0,   69,    0,   77,   79,    0,    0,   73,
   76,    0,    0,   36,    0,    0,    0,    0,    0,   21,
    0,    0,    0,    0,    0,    0,    0,   59,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   44,   54,
    0,    0,   20,    0,   58,    0,   78,    0,    0,   74,
   75,    0,    0,    0,    0,    0,    0,   37,    0,    0,
    0,    0,    0,   45,    0,   49,   38,    0,   17,    0,
    0,   46,    0,   41,   39,    0,    0,   51,   42,    0,
   52,
};
static const short yydgoto[] = {                          2,
    3,    7,   57,   15,   28,    9,   10,   12,   16,   17,
   18,   22,   58,   56,  102,   79,   45,   29,   51,   30,
   53,   31,   32,   33,   34,   35,   36,   37,   49,   73,
   74,   98,  123,  135,  131,  137,   75,  119,  128,   61,
  122,  130,  136,  140,   38,   77,   82,   69,   84,   70,
   71,
};
static const short yysindex[] = {                      -228,
    0,    0, -289, -273, -208, -230, -207, -188, -189,    0,
    0, -192,    0, -147, -253, -138,    0,    0, -208, -141,
    0, -256, -253, -133, -129, -115,    0,    0,    0,  -94,
  -90,    0,    0,    0,    0,    0,    0, -114, -188,    0,
    0,    0, -208,    0, -257,    0, -100, -134, -109, -134,
    0,    0,    0, -134,    0, -230,    0,    0,    0, -253,
  -97,    0, -272,    0, -134,    0,    0, -193, -246,    0,
    0, -134,   17,    0, -134, -153, -261, -192, -253,    0,
 -134,  -85, -246, -272, -111, -272, -272,    0, -272, -272,
 -153, -134, -134, -134, -134, -134, -134,  -66,    0,    0,
 -134,  -81,    0, -153,    0, -246,    0, -246, -246,    0,
    0, -153, -153, -153, -153, -153, -153,    0,  -54, -153,
  -80,  -62, -253,    0, -208,    0,    0, -253,    0, -134,
  -44,    0, -153,    0,    0,  -41, -253,    0,    0, -253,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -206,    0,    0, -204,    0,    0,
    0,  -67,    0,    0, -251,    0,    0,    0, -255,    0,
    0,    0, -236,    0,    0,    0, -181,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -217, -175,    0,
    0,    0, -163,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -236,
    0,    0,    0,    0,    0,    0,    0,    0, -136,    0,
    0,    0,    0,    0,    0, -214,    0,  -57, -195,    0,
    0,    0, -102,    0,    0,    0,    0,    0,    0,    0,
  -95,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -51,    0,  -68,    0,  -34,    1,    0,
    0, -155, -140, -132,  -84,  -71,  -70,    0,    0, -172,
    0,    0,   13,    0, -163,    0,    0,   13,    0,    0,
 -216,    0,  -36,    0,    0,    0,   13,    0,    0,   13,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,  223,    0,  -23,    0,  210,  174,    0,  192,
    0,    0,  107,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -47,
  158,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   43,    0,   45,
    0,
};
#define YYTABLESIZE 304
static const short yytable[] = {                         44,
   68,    5,   59,   23,    4,    5,   76,   24,    5,    5,
   65,    5,   24,   25,    5,    5,    5,   85,   26,   26,
   66,   67,  100,   60,   91,  101,   42,   24,   89,   90,
   60,   43,    5,  104,   26,    5,   80,    1,    5,   60,
   27,   53,   53,   40,  112,  113,  114,  115,  116,  117,
    4,   60,    9,  120,    4,  103,    9,    4,    4,    9,
    4,    6,    9,   11,    4,    4,    9,    9,   24,   80,
   53,   40,   80,   53,   40,   26,   14,   55,   55,   86,
   87,   10,  133,   13,    4,   10,    9,    4,   10,    9,
   88,   10,   60,    4,   20,   10,   10,    4,   19,  127,
    4,   55,   61,    4,  132,   83,   55,    4,    4,   55,
   34,   81,   61,  139,   81,   10,  141,   62,   10,   86,
   87,   67,   67,   67,    4,   64,  106,   62,  108,  109,
    4,   67,   67,  110,  111,   64,   67,   67,   63,   64,
   67,   67,   67,   67,   67,   67,   21,   67,   65,   39,
   67,   67,   41,   47,   67,   68,   68,   68,   66,   67,
   46,   86,   87,   35,   35,   68,   68,   48,   54,   50,
   68,   68,  107,   63,   68,   68,   68,   68,   68,   68,
   52,   68,   72,   63,   68,   68,   66,   65,   68,   70,
   70,   70,   35,   62,   81,   35,   66,   65,  105,   70,
   70,  118,  121,  124,   70,   70,  126,  125,   70,   70,
   70,   70,   70,   70,  134,   70,  138,   48,   70,   70,
    8,   50,   70,   71,   71,   71,   16,    8,   40,   78,
   55,  129,   99,   71,   71,    0,    0,    0,   71,   71,
    0,    0,   71,   71,   71,   71,   71,   71,    0,   71,
    0,    0,   71,   71,    0,    0,   71,    0,   72,   72,
   72,    0,    0,    0,    0,    0,    0,    0,   72,   72,
    0,   60,   60,   72,   72,    0,   24,   72,   72,   72,
   72,   72,   72,   26,   72,    0,    0,   72,   72,   86,
   87,   72,    0,   92,   93,   94,   95,   96,   97,    0,
   60,    0,    0,   60,
};
static const short yycheck[] = {                         23,
   48,  257,  260,  257,  294,  261,   54,  261,  264,  265,
  283,  267,  264,  267,  288,  271,  272,   65,  272,  271,
  293,  294,  284,  260,   72,  287,  283,  264,  275,  276,
  288,  288,  288,   81,  271,  291,   60,  266,  294,  291,
  294,  259,  260,  260,   92,   93,   94,   95,   96,   97,
  257,  288,  257,  101,  261,   79,  261,  264,  265,  264,
  267,  270,  267,  294,  271,  272,  271,  272,  264,  284,
  288,  288,  287,  291,  291,  271,  265,  259,  260,  273,
  274,  257,  130,  291,  291,  261,  291,  294,  264,  294,
  284,  267,  288,  257,  287,  271,  272,  261,  288,  123,
  264,  283,  258,  267,  128,   63,  288,  271,  272,  291,
  292,  284,  268,  137,  287,  291,  140,  258,  294,  273,
  274,  258,  259,  260,  288,  258,   84,  268,   86,   87,
  294,  268,  269,   89,   90,  268,  273,  274,  273,  274,
  277,  278,  279,  280,  281,  282,  294,  284,  283,  288,
  287,  288,  294,  283,  291,  258,  259,  260,  293,  294,
  294,  273,  274,  259,  260,  268,  269,  283,  283,  264,
  273,  274,  284,  258,  277,  278,  279,  280,  281,  282,
  271,  284,  292,  268,  287,  288,  258,  258,  291,  258,
  259,  260,  288,  294,  292,  291,  268,  268,  284,  268,
  269,  268,  284,  258,  273,  274,  269,  288,  277,  278,
  279,  280,  281,  282,  259,  284,  258,  269,  287,  288,
  288,  258,  291,  258,  259,  260,  284,    5,   19,   56,
   39,  125,   75,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,   -1,  287,  288,   -1,   -1,  291,   -1,  258,  259,
  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,
   -1,  259,  260,  273,  274,   -1,  264,  277,  278,  279,
  280,  281,  282,  271,  284,   -1,   -1,  287,  288,  273,
  274,  291,   -1,  277,  278,  279,  280,  281,  282,   -1,
  288,   -1,   -1,  291,
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
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"$$2 :",
"$$3 :",
"proc_decl : PROCEDURE proc_name LPAREN $$2 id_list $$3 RPAREN SEMICOLON inblock",
"proc_name : IDENT",
"$$4 :",
"inblock : var_decl_part $$4 statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"$$5 :",
"statement : $$5 if_statement",
"$$6 :",
"statement : $$6 while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$7 :",
"assignment_statement : IDENT $$7 ASSIGN expression",
"$$8 :",
"$$9 :",
"$$10 :",
"if_statement : IF condition $$8 THEN $$9 statement $$10 else_statement",
"else_statement :",
"$$11 :",
"else_statement : ELSE $$11 statement",
"$$12 :",
"$$13 :",
"$$14 :",
"while_statement : WHILE $$12 condition $$13 DO $$14 statement",
"$$15 :",
"$$16 :",
"$$17 :",
"$$18 :",
"$$19 :",
"for_statement : FOR IDENT $$15 ASSIGN expression $$16 TO $$17 expression $$18 DO $$19 statement",
"proc_call_statement : proc_call_name",
"proc_call_statement : proc_call_name LPAREN arg_list RPAREN",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$20 :",
"read_statement : READ LPAREN IDENT $$20 RPAREN",
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
"$$21 :",
"expression : MINUS $$21 term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
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
#line 573 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 436 "y.tab.c"

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
#line 54 "parser.y"
	{init_fstack();}
break;
case 2:
#line 55 "parser.y"
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
#line 96 "parser.y"
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
#line 117 "parser.y"
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
#line 148 "parser.y"
	{
                delete(); 
                Proc_Term--;
                Factor retval;
                strcpy(retval.val,"void");
                factorpush(retval);
                create_llvmcode(Ret);
        }
break;
case 15:
#line 160 "parser.y"
	{arity_decl=1;}
break;
case 16:
#line 160 "parser.y"
	{arity_decl=0;}
break;
case 18:
#line 165 "parser.y"
	{ 
                insert(yystack.l_mark[0].ident, 2);
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , yystack.l_mark[0].ident);
                tmp->codes = NULL;
                tmp->arity = 0;
                if (declhd == NULL) declhd = tmp;
                if (decltl != NULL) decltl->next = tmp;
                decltl = tmp; 
                codetl = NULL;
                Proc_Term++;
        }
break;
case 19:
#line 181 "parser.y"
	{Arity_Alloca();}
break;
case 24:
#line 192 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 25:
#line 198 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->end = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 26:
#line 205 "parser.y"
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
case 27:
#line 217 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 28:
#line 226 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 29:
#line 233 "parser.y"
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
                (tmp->args).call.proc = arg;
                (tmp->args).call.rettype = vo;
                
                add_llvmnode(tmp);

        }
break;
case 34:
#line 258 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 35:
#line 259 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 36:
#line 266 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 37:
#line 270 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 38:
#line 275 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 39:
#line 279 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 41:
#line 291 "parser.y"
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
case 43:
#line 305 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 44:
#line 310 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 45:
#line 313 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 46:
#line 317 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; 
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 47:
#line 329 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 48:
#line 333 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 49:
#line 337 "parser.y"
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
case 50:
#line 353 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 51:
#line 358 "parser.y"
	{
                create_llvmcode(BrCond);
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 52:
#line 364 "parser.y"
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
case 55:
#line 396 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 57:
#line 404 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 58:
#line 405 "parser.y"
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
case 59:
#line 425 "parser.y"
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
case 61:
#line 449 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 62:
#line 454 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 63:
#line 459 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 64:
#line 464 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 65:
#line 469 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 66:
#line 474 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 69:
#line 484 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 70:
#line 491 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 71:
#line 495 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 72:
#line 499 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 74:
#line 507 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 75:
#line 512 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 76:
#line 520 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 77:
#line 524 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 79:
#line 534 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 82:
#line 544 "parser.y"
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
case 83:
#line 559 "parser.y"
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
#line 1158 "y.tab.c"
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
