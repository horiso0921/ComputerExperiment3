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

#line 28 "parser.y"
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
#line 56 "y.tab.c"

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
    9,    9,   10,   11,   12,   14,   13,   15,   15,    5,
   18,    5,   20,    5,    5,    5,    5,    5,    5,    5,
   27,   16,   30,   31,   17,   32,   33,   32,   34,   35,
   36,   19,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   47,   48,   49,   21,   22,   50,   24,   51,
   25,   26,   23,   29,   29,   29,   29,   29,   29,   28,
   28,   53,   28,   28,   28,   52,   52,   52,   54,   54,
   54,   55,   56,   56,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    1,    0,    3,    3,    1,    1,
    0,    2,    0,    2,    1,    1,    1,    1,    1,    1,
    0,    4,    0,    0,    7,    0,    0,    3,    0,    0,
    0,    7,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   21,    1,    1,    3,    0,
    5,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    0,    3,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   85,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    3,   20,    0,
    0,   25,   26,   27,   28,   29,   30,   57,    0,    6,
   86,   16,   19,    0,   43,    0,    0,    0,    0,   22,
   39,   24,   11,   14,    0,   59,    0,    0,   60,    0,
   72,    0,   80,   82,    0,    0,   76,   79,    0,    0,
   33,    0,    0,   18,    0,    0,    0,    0,    0,    0,
    0,   62,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   40,   17,    0,   61,    0,   81,    0,    0,
   77,   78,    0,    0,    0,    0,    0,    0,   34,    0,
    0,    0,   41,   45,    0,    0,   46,   37,   35,   42,
   47,    0,    0,   38,    0,    0,   49,   50,    0,   51,
   52,   53,   54,   55,   56,
};
static const short yydgoto[] = {                          2,
    3,    7,    8,   15,   28,    9,   10,   12,   16,   17,
   18,   22,   54,   55,   44,   29,   50,   30,   52,   31,
   32,   33,   34,   35,   36,   37,   48,   70,   71,   92,
  112,  119,  122,   72,  110,  116,   58,  111,  117,  121,
  123,  126,  128,  129,  131,  132,  133,  134,  135,   38,
   76,   66,   78,   67,   68,    0,
};
static const short yysindex[] = {                      -263,
    0,    0, -289, -277, -244, -242, -220, -177, -203,    0,
    0, -197,    0, -196, -239, -185,    0,    0, -244, -189,
    0, -179, -239, -178, -160, -149,    0,    0,    0, -126,
 -114,    0,    0,    0,    0,    0,    0,    0, -177,    0,
    0,    0,    0, -258,    0, -130, -161, -131, -161,    0,
    0,    0,    0,    0, -244,    0, -239, -127,    0, -279,
    0, -161,    0,    0, -156, -266,    0,    0, -161,   -9,
    0, -161, -239,    0, -161, -107, -266, -279, -154, -279,
 -279,    0, -279, -279, -207, -161, -161, -161, -161, -161,
 -161,  -98,    0,    0, -207,    0, -266,    0, -266, -266,
    0,    0, -207, -207, -207, -207, -207, -207,    0,  -75,
  -85, -239,    0,    0,  -73, -239,    0,    0,    0,    0,
    0, -239, -161,    0, -207,  -71,    0,    0, -239,    0,
    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -208,    0,    0, -199,    0,    0,
    0, -100,    0,    0, -195,    0,    0,    0, -240,    0,
    0,    0, -252,    0,    0,    0, -253,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -170,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -157,    0, -252,    0,    0,    0,
    0,    0,    0,    0,    0, -133,    0,    0,    0,    0,
    0,    0, -251,    0,    0,    0, -106,    0,    0,    0,
    0,    0,    0,    0, -213,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -78,    0,  -79,    0,  -52,  -25,
    0,    0, -198, -184, -129, -108, -102,  -99,    0,    0,
    0,  -13,    0,    0, -180,  -13,    0,    0,    0,    0,
    0,  -13,    0,    0,  -66,    0,    0,    0,  -13,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  138,    0,  -23,    0,  177,    0,    0,  158,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -46,  132,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,   59,    0,    0,
};
#define YYTABLESIZE 278
static const short yytable[] = {                         43,
   65,   56,    1,   62,    4,   58,   58,   63,   83,   84,
    5,   21,   21,   63,   64,   79,    5,   23,   23,   23,
    5,   24,   85,    5,    5,    6,    5,   25,   95,   57,
    5,    5,   26,   74,   58,   63,   63,   58,   31,  103,
  104,  105,  106,  107,  108,   32,   32,    5,    4,   94,
    5,   11,    4,    5,   27,    4,    4,    9,    4,   64,
   77,    9,    4,    4,    9,   80,   81,    9,   21,   64,
   13,    9,    9,   65,   32,   23,  125,   32,   97,   36,
   99,  100,    4,   65,   19,    4,   10,   14,  115,   20,
   10,    9,  120,   10,    9,   63,   10,   21,  124,    4,
   10,   10,   39,    4,   41,  130,    4,   36,   42,    4,
   36,   60,   61,    4,    4,   45,   80,   81,   80,   81,
   10,   62,   46,   10,   70,   70,   70,   82,   67,   98,
    4,   63,   64,   47,   70,   70,    4,   49,   67,   70,
   70,  101,  102,   70,   70,   70,   70,   70,   70,   66,
   70,   71,   71,   71,   70,   69,   51,   70,   68,   66,
   69,   71,   71,   59,   75,   69,   71,   71,   68,  109,
   71,   71,   71,   71,   71,   71,   96,   71,   73,   73,
   73,   71,  113,  114,   71,  118,  127,    8,   73,   73,
   44,   48,   73,   73,   73,   40,   53,   73,   73,   73,
   73,   73,   73,   93,   73,   74,   74,   74,   73,    0,
    0,   73,    0,    0,    0,   74,   74,    0,    0,    0,
   74,   74,    0,    0,   74,   74,   74,   74,   74,   74,
    0,   74,   75,   75,   75,   74,    0,    0,   74,    0,
    0,    0,   75,   75,    0,   63,   63,   75,   75,    0,
   21,   75,   75,   75,   75,   75,   75,   23,   75,    0,
    0,    0,   75,   80,   81,   75,    0,   86,   87,   88,
   89,   90,   91,    0,   63,    0,    0,   63,
};
static const short yycheck[] = {                         23,
   47,  260,  266,  283,  294,  259,  260,  260,  275,  276,
  288,  264,  264,  293,  294,   62,  257,  257,  271,  271,
  261,  261,   69,  264,  265,  270,  267,  267,   75,  288,
  271,  272,  272,   57,  288,  288,  288,  291,  292,   86,
   87,   88,   89,   90,   91,  259,  260,  288,  257,   73,
  291,  294,  261,  294,  294,  264,  265,  257,  267,  258,
   60,  261,  271,  272,  264,  273,  274,  267,  264,  268,
  291,  271,  272,  258,  288,  271,  123,  291,   78,  260,
   80,   81,  291,  268,  288,  294,  257,  265,  112,  287,
  261,  291,  116,  264,  294,  291,  267,  294,  122,  257,
  271,  272,  288,  261,  294,  129,  264,  288,  288,  267,
  291,  273,  274,  271,  272,  294,  273,  274,  273,  274,
  291,  283,  283,  294,  258,  259,  260,  284,  258,  284,
  288,  293,  294,  283,  268,  269,  294,  264,  268,  273,
  274,   83,   84,  277,  278,  279,  280,  281,  282,  258,
  284,  258,  259,  260,  288,  258,  271,  291,  258,  268,
  292,  268,  269,  294,  292,  268,  273,  274,  268,  268,
  277,  278,  279,  280,  281,  282,  284,  284,  258,  259,
  260,  288,  258,  269,  291,  259,  258,  288,  268,  269,
  269,  258,   55,  273,  274,   19,   39,  277,  278,  279,
  280,  281,  282,   72,  284,  258,  259,  260,  288,   -1,
   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,   -1,
   -1,   -1,  268,  269,   -1,  259,  260,  273,  274,   -1,
  264,  277,  278,  279,  280,  281,  282,  271,  284,   -1,
   -1,   -1,  288,  273,  274,  291,   -1,  277,  278,  279,
  280,  281,  282,   -1,  288,   -1,   -1,  291,
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
"proc_name : IDENT",
"$$2 :",
"inblock : $$2 var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"$$3 :",
"statement : $$3 if_statement",
"$$4 :",
"statement : $$4 while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$5 :",
"assignment_statement : IDENT $$5 ASSIGN expression",
"$$6 :",
"$$7 :",
"if_statement : IF condition $$6 THEN $$7 statement else_statement",
"else_statement :",
"$$8 :",
"else_statement : ELSE $$8 statement",
"$$9 :",
"$$10 :",
"$$11 :",
"while_statement : WHILE $$9 condition $$10 DO $$11 statement",
"$$12 :",
"$$13 :",
"$$14 :",
"$$15 :",
"$$16 :",
"$$17 :",
"$$18 :",
"$$19 :",
"$$20 :",
"$$21 :",
"$$22 :",
"$$23 :",
"$$24 :",
"for_statement : FOR IDENT $$12 ASSIGN expression $$13 TO $$14 $$15 $$16 expression $$17 DO $$18 $$19 statement $$20 $$21 $$22 $$23 $$24",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$25 :",
"read_statement : READ LPAREN IDENT $$25 RPAREN",
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
"$$26 :",
"expression : MINUS $$26 term",
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
#line 568 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 427 "y.tab.c"

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
#line 51 "parser.y"
	{init_fstack();}
break;
case 2:
#line 52 "parser.y"
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
#line 93 "parser.y"
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
#line 114 "parser.y"
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
#line 145 "parser.y"
	{
                Factor retval;
                strcpy(retval.val,"void");
                factorpush(retval);
                create_llvmcode(Ret);
        }
break;
case 15:
#line 159 "parser.y"
	{ 
                insert(yystack.l_mark[0].ident, 2);
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , yystack.l_mark[0].ident);
                tmp->codes = NULL;
                if (declhd == NULL) declhd = tmp;
                if (decltl != NULL) decltl->next = tmp;
                decltl = tmp; 
                codetl = NULL;
        }
break;
case 16:
#line 173 "parser.y"
	{Proc_Term++;}
break;
case 17:
#line 173 "parser.y"
	{delete(); Proc_Term--;}
break;
case 21:
#line 184 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 22:
#line 190 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 23:
#line 197 "parser.y"
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
case 24:
#line 209 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 25:
#line 218 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 31:
#line 232 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 32:
#line 233 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 33:
#line 240 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 34:
#line 244 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 35:
#line 248 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->uncoll;
                add_llvmnode(tmp);
        }
break;
case 37:
#line 260 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->uncoll;
                add_llvmnode(tmp);
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 39:
#line 273 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 40:
#line 278 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 41:
#line 282 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 42:
#line 286 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 43:
#line 298 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 44:
#line 302 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 45:
#line 306 "parser.y"
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
case 46:
#line 317 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 47:
#line 321 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 48:
#line 326 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 49:
#line 331 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 50:
#line 334 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 51:
#line 339 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 52:
#line 346 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 53:
#line 351 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 54:
#line 356 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 55:
#line 364 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 56:
#line 367 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 58:
#line 383 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
                lookup(yystack.l_mark[0].ident);
                strcpy((tmp->args).call.funcname, yystack.l_mark[0].ident);
                (tmp->args).call.rettype = vo;
                Factor arg1;
                strcpy(arg1.val, "void");
                (tmp->args).call.arg1 = arg1;
                add_llvmnode(tmp);
        }
break;
case 60:
#line 402 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 61:
#line 403 "parser.y"
	{
                
                Factor arg1, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
                arg1 = factorpop();/*スタックから第2引数をポップ*/
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register;
                Last_Register ++;
                (tmp->args).call.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).call.retval = retval; /* 命令の第 2 引数を指定 */
                strcpy((tmp->args).call.funcname, "read");
                (tmp->args).call.rettype = I32;
                add_llvmnode(tmp);
        }
break;
case 62:
#line 423 "parser.y"
	{
                
                Factor arg1, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
                arg1 = factorpop();/*スタックから第2引数をポップ*/
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register;
                Last_Register ++;
                (tmp->args).call.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).call.retval = retval; /* 命令の第 2 引数を指定 */
                strcpy((tmp->args).call.funcname, "write");
                (tmp->args).call.rettype = I32;
                add_llvmnode(tmp);  
        }
break;
case 64:
#line 447 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 65:
#line 452 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 66:
#line 457 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 67:
#line 462 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 68:
#line 467 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 69:
#line 472 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 72:
#line 482 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 73:
#line 489 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 74:
#line 493 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 75:
#line 497 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 77:
#line 505 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 78:
#line 510 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 79:
#line 518 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 80:
#line 522 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 82:
#line 532 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 85:
#line 542 "parser.y"
	{ 
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
case 86:
#line 555 "parser.y"
	{ 
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
#line 1165 "y.tab.c"
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
