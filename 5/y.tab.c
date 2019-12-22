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
   27,   16,   30,   31,   33,   17,   32,   34,   32,   35,
   36,   37,   19,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   47,   48,   49,   50,   21,   22,   51,   24,
   52,   25,   26,   23,   29,   29,   29,   29,   29,   29,
   28,   28,   54,   28,   28,   28,   53,   53,   53,   55,
   55,   55,   56,   57,   57,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    1,    0,    3,    3,    1,    1,
    0,    2,    0,    2,    1,    1,    1,    1,    1,    1,
    0,    4,    0,    0,    0,    8,    0,    0,    3,    0,
    0,    0,    7,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,    1,    1,    3,
    0,    5,    4,    0,    3,    3,    3,    3,    3,    3,
    1,    2,    0,    3,    3,    3,    1,    3,    3,    1,
    1,    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   86,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    3,   20,    0,
    0,   25,   26,   27,   28,   29,   30,   58,    0,    6,
   87,   16,   19,    0,   44,    0,    0,    0,    0,   22,
   40,   24,   11,   14,    0,   60,    0,    0,   61,    0,
   73,    0,   81,   83,    0,    0,   77,   80,    0,    0,
   33,    0,    0,   18,    0,    0,    0,    0,    0,    0,
    0,   63,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,   17,    0,   62,    0,   82,    0,    0,
   78,   79,    0,    0,    0,    0,    0,    0,   34,    0,
    0,    0,   42,   46,   35,    0,   47,    0,   43,   48,
   38,   36,    0,    0,    0,   39,    0,   50,   51,    0,
   52,   53,   54,   55,   56,   57,
};
static const short yydgoto[] = {                          2,
    3,    7,    8,   15,   28,    9,   10,   12,   16,   17,
   18,   22,   54,   55,   44,   29,   50,   30,   52,   31,
   32,   33,   34,   35,   36,   37,   48,   70,   71,   92,
  112,  122,  118,  124,   72,  110,  116,   58,  111,  117,
  120,  123,  127,  129,  130,  132,  133,  134,  135,  136,
   38,   76,   66,   78,   67,   68,    0,
};
static const short yysindex[] = {                      -263,
    0,    0, -289, -277, -244, -242, -222, -194, -203,    0,
    0, -197,    0, -190, -239, -191,    0,    0, -244, -174,
    0, -156, -239, -171, -136, -132,    0,    0,    0, -104,
  -98,    0,    0,    0,    0,    0,    0,    0, -194,    0,
    0,    0,    0, -258,    0, -127,  -16, -115,  -16,    0,
    0,    0,    0,    0, -244,    0, -239, -114,    0, -279,
    0,  -16,    0,    0, -165, -266,    0,    0,  -16,   -8,
    0,  -16, -239,    0,  -16, -110, -266, -279, -160, -279,
 -279,    0, -279, -279, -145,  -16,  -16,  -16,  -16,  -16,
  -16,  -92,    0,    0, -145,    0, -266,    0, -266, -266,
    0,    0, -145, -145, -145, -145, -145, -145,    0,  -77,
  -87, -239,    0,    0,    0, -239,    0,  -76,    0,    0,
    0,    0,  -16, -239, -145,    0,  -72,    0,    0, -239,
    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -208,    0,    0, -199,    0,    0,
    0, -101,    0,    0, -204,    0,    0,    0, -240,    0,
    0,    0, -252,    0,    0,    0, -253,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -173,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -161,    0, -252,    0,    0,    0,
    0,    0,    0,    0,    0, -143,    0,    0,    0,    0,
    0,    0, -251,    0,    0,    0, -116,    0,    0,    0,
    0,    0,    0,    0, -213,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -75,    0,  -89,    0,  -62,  -35,
    0,    0, -192, -188, -146, -118, -112, -109,    0,    0,
    0,   -9,    0,    0,    0,   -9,    0, -186,    0,    0,
    0,    0,    0,   -9,  -58,    0,    0,    0,    0,   -9,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  146,    0,  -23,    0,  184,    0,    0,  165,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -46,  133,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,   71,    0,    0,
};
#define YYTABLESIZE 282
static const short yytable[] = {                         43,
   65,   56,    1,   62,    4,   59,   59,   64,   83,   84,
    5,   21,   21,   63,   64,   79,    5,   23,   23,   23,
    5,   24,   85,    5,    5,    6,    5,   25,   95,   57,
    5,    5,   26,   74,   59,   64,   64,   59,   31,  103,
  104,  105,  106,  107,  108,   32,   32,    5,    4,   94,
    5,   11,    4,    5,   27,    4,    4,    9,    4,   21,
   77,    9,    4,    4,    9,   65,   23,    9,   13,   66,
   14,    9,    9,   37,   32,   65,  125,   32,   97,   66,
   99,  100,    4,   10,   19,    4,   64,   10,  115,   20,
   10,    9,  119,   10,    9,    4,   39,   10,   10,    4,
  126,   37,    4,   21,   37,    4,  131,   80,   81,    4,
    4,   68,   80,   81,   71,   71,   71,   10,   82,   41,
   10,   68,   45,   98,   71,   71,    4,   80,   81,   71,
   71,   42,    4,   71,   71,   71,   71,   71,   71,   67,
   71,   72,   72,   72,   71,   70,   46,   71,   69,   67,
   47,   72,   72,  101,  102,   70,   72,   72,   69,   49,
   72,   72,   72,   72,   72,   72,   59,   72,   74,   74,
   74,   72,   51,   96,   72,  109,   69,   75,   74,   74,
  113,  114,  121,   74,   74,  128,    8,   74,   74,   74,
   74,   74,   74,   45,   74,   75,   75,   75,   74,   49,
   73,   74,   40,   53,   93,   75,   75,    0,    0,    0,
   75,   75,    0,    0,   75,   75,   75,   75,   75,   75,
    0,   75,   76,   76,   76,   75,    0,    0,   75,    0,
    0,    0,   76,   76,    0,    0,    0,   76,   76,    0,
    0,   76,   76,   76,   76,   76,   76,    0,   76,   64,
   64,    0,   76,    0,   21,   76,   60,   61,    0,    0,
    0,   23,    0,    0,   80,   81,   62,    0,   86,   87,
   88,   89,   90,   91,    0,    0,   63,   64,   64,    0,
    0,   64,
};
static const short yycheck[] = {                         23,
   47,  260,  266,  283,  294,  259,  260,  260,  275,  276,
  288,  264,  264,  293,  294,   62,  257,  257,  271,  271,
  261,  261,   69,  264,  265,  270,  267,  267,   75,  288,
  271,  272,  272,   57,  288,  288,  288,  291,  292,   86,
   87,   88,   89,   90,   91,  259,  260,  288,  257,   73,
  291,  294,  261,  294,  294,  264,  265,  257,  267,  264,
   60,  261,  271,  272,  264,  258,  271,  267,  291,  258,
  265,  271,  272,  260,  288,  268,  123,  291,   78,  268,
   80,   81,  291,  257,  288,  294,  291,  261,  112,  287,
  264,  291,  116,  267,  294,  257,  288,  271,  272,  261,
  124,  288,  264,  294,  291,  267,  130,  273,  274,  271,
  272,  258,  273,  274,  258,  259,  260,  291,  284,  294,
  294,  268,  294,  284,  268,  269,  288,  273,  274,  273,
  274,  288,  294,  277,  278,  279,  280,  281,  282,  258,
  284,  258,  259,  260,  288,  258,  283,  291,  258,  268,
  283,  268,  269,   83,   84,  268,  273,  274,  268,  264,
  277,  278,  279,  280,  281,  282,  294,  284,  258,  259,
  260,  288,  271,  284,  291,  268,  292,  292,  268,  269,
  258,  269,  259,  273,  274,  258,  288,  277,  278,  279,
  280,  281,  282,  269,  284,  258,  259,  260,  288,  258,
   55,  291,   19,   39,   72,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,   -1,
   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,  259,
  260,   -1,  288,   -1,  264,  291,  273,  274,   -1,   -1,
   -1,  271,   -1,   -1,  273,  274,  283,   -1,  277,  278,
  279,  280,  281,  282,   -1,   -1,  293,  294,  288,   -1,
   -1,  291,
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
"$$8 :",
"if_statement : IF condition $$6 THEN $$7 statement $$8 else_statement",
"else_statement :",
"$$9 :",
"else_statement : ELSE $$9 statement",
"$$10 :",
"$$11 :",
"$$12 :",
"while_statement : WHILE $$10 condition $$11 DO $$12 statement",
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
"$$25 :",
"for_statement : FOR IDENT $$13 ASSIGN expression $$14 TO $$15 $$16 $$17 expression $$18 DO $$19 $$20 statement $$21 $$22 $$23 $$24 $$25",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$26 :",
"read_statement : READ LPAREN IDENT $$26 RPAREN",
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
"$$27 :",
"expression : MINUS $$27 term",
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
#line 430 "y.tab.c"

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
                br_decl->end = Last_Register;
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
#line 249 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 36:
#line 253 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 38:
#line 265 "parser.y"
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
case 40:
#line 278 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 41:
#line 283 "parser.y"
	{
                create_llvmcode(BrCond);
                add_llvmnode(tmp);
        }
break;
case 42:
#line 287 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 43:
#line 291 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 44:
#line 303 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 45:
#line 307 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 46:
#line 311 "parser.y"
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
case 47:
#line 322 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register++;
        }
break;
case 48:
#line 326 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-7].ident));
                create_llvmcode(Load);
        }
break;
case 49:
#line 331 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 50:
#line 336 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 51:
#line 339 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 52:
#line 344 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
        }
break;
case 53:
#line 351 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
        }
break;
case 54:
#line 356 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[-16].ident));
                factorpush(lookup(yystack.l_mark[-16].ident));
                create_llvmcode(Load);
        }
break;
case 55:
#line 361 "parser.y"
	{
                
                Factor arg2; /* 加算の引数・結果 */
                arg2.type = CONSTANT;
                arg2.cal = 1;
                factorpush(arg2);
                create_llvmcode(Add);
        }
break;
case 56:
#line 369 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 57:
#line 372 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 59:
#line 388 "parser.y"
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
case 61:
#line 407 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 62:
#line 408 "parser.y"
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
case 63:
#line 428 "parser.y"
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
case 65:
#line 452 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 66:
#line 457 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 67:
#line 462 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 68:
#line 467 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 69:
#line 472 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 70:
#line 477 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 73:
#line 487 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 74:
#line 494 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 75:
#line 498 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 76:
#line 502 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 78:
#line 510 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 79:
#line 515 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 80:
#line 523 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 81:
#line 527 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 83:
#line 537 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 86:
#line 547 "parser.y"
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
case 87:
#line 560 "parser.y"
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
#line 1174 "y.tab.c"
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
