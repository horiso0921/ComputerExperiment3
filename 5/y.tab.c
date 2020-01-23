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
#define PP 277
#define EQ 278
#define NEQ 279
#define LE 280
#define LT 281
#define GE 282
#define GT 283
#define LPAREN 284
#define RPAREN 285
#define LBRACKET 286
#define RBRACKET 287
#define COMMA 288
#define SEMICOLON 289
#define COLON 290
#define INTERVAL 291
#define PERIOD 292
#define ASSIGN 293
#define NUMBER 294
#define IDENT 295
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    1,    0,    2,    3,    3,    6,    6,    7,    4,    4,
    9,    9,   10,   11,   12,   14,   13,   15,   15,    5,
   18,    5,   20,    5,    5,    5,    5,    5,    5,    5,
   27,   16,   30,   31,   33,   17,   32,   34,   32,   35,
   36,   37,   19,   38,   39,   40,   41,   42,   21,   22,
   43,   24,   44,   25,   26,   23,   29,   29,   29,   29,
   29,   29,   28,   28,   46,   28,   28,   28,   45,   45,
   45,   47,   47,   47,   48,   49,   49,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    1,    0,    3,    3,    1,    1,
    0,    2,    0,    2,    1,    1,    1,    1,    1,    1,
    0,    4,    0,    0,    0,    8,    0,    0,    3,    0,
    0,    0,    7,    0,    0,    0,    0,    0,   13,    1,
    1,    3,    0,    5,    4,    0,    3,    3,    3,    3,
    3,    3,    1,    2,    0,    3,    3,    3,    1,    3,
    3,    1,    1,    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   78,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    3,   20,    0,
    0,   25,   26,   27,   28,   29,   30,   50,    0,    6,
   79,   16,   19,    0,   44,    0,    0,    0,    0,   22,
   40,   24,   11,   14,    0,   52,    0,    0,   53,    0,
   65,    0,   73,   75,    0,    0,   69,   72,    0,    0,
   33,    0,    0,   18,    0,    0,    0,    0,    0,    0,
    0,   55,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,   17,    0,   54,    0,   74,    0,    0,
   70,   71,    0,    0,    0,    0,    0,    0,   34,    0,
    0,    0,   42,   46,   35,    0,    0,    0,   43,    0,
   38,   36,    0,    0,   48,   39,    0,   49,
};
static const short yydgoto[] = {                          2,
    3,    7,    8,   15,   28,    9,   10,   12,   16,   17,
   18,   22,   54,   55,   44,   29,   50,   30,   52,   31,
   32,   33,   34,   35,   36,   37,   48,   70,   71,   92,
  112,  122,  118,  124,   72,  110,  116,   58,  111,  117,
  123,  127,   38,   76,   66,   78,   67,   68,    0,
};
static const short yysindex[] = {                      -258,
    0,    0, -269, -243, -211, -231, -222, -192, -210,    0,
    0, -183,    0, -185, -239, -173,    0,    0, -211, -181,
    0, -172, -239, -170, -161, -156,    0,    0,    0, -135,
 -134,    0,    0,    0,    0,    0,    0,    0, -192,    0,
    0,    0,    0, -253,    0, -151,  -43, -145,  -43,    0,
    0,    0,    0,    0, -211,    0, -239, -141,    0, -175,
    0,  -43,    0,    0, -270, -264,    0,    0,  -43,  -15,
    0,  -43, -239,    0,  -43, -129, -264, -175, -199, -175,
 -175,    0, -175, -175, -260,  -43,  -43,  -43,  -43,  -43,
  -43, -111,    0,    0, -260,    0, -264,    0, -264, -264,
    0,    0, -260, -260, -260, -260, -260, -260,    0,  -93,
  -97, -239,    0,    0,    0, -239,  -43,  -79,    0, -260,
    0,    0,  -74, -239,    0,    0, -239,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -204,    0,    0, -195,    0,    0,
    0, -104,    0,    0, -262,    0,    0,    0, -240,    0,
    0,    0, -206,    0,    0,    0, -254,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -177,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -165,    0, -206,    0,    0,    0,
    0,    0,    0,    0,    0, -147,    0,    0,    0,    0,
    0,    0, -186,    0,    0,    0, -119,    0,    0,    0,
    0,    0,    0,    0,  -85,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -83,    0,  -91,    0,  -63,  -35,
    0,    0, -248, -221, -160, -115,  -87,  -65,    0,    0,
    0, -113,    0,    0,    0, -113,    0, -241,    0,  -59,
    0,    0,    0, -113,    0,    0, -113,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  145,    0,  -23,    0,  183,    0,    0,  169,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -46,  137,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  175,    0,   -2,    0,    0,
};
#define YYTABLESIZE 268
static const short yytable[] = {                         43,
   65,   21,   80,   81,   51,   51,   56,    1,   23,   57,
   83,   84,   80,   81,   82,   79,    5,   23,   37,   57,
    5,   24,   85,    5,    5,    4,    5,   25,   95,   56,
    5,    5,   26,   74,   51,   57,   58,   51,   31,  103,
  104,  105,  106,  107,  108,    5,   58,   37,    5,   94,
   37,    5,    4,   56,    5,   27,    4,   21,    6,    4,
    4,    9,    4,   11,   23,    9,    4,    4,    9,   13,
  120,    9,   14,   80,   81,    9,    9,   21,   19,   10,
  101,  102,   56,   10,   23,   98,   10,    4,  115,   10,
    4,    4,  119,   10,   10,    4,    9,   60,    4,    9,
  126,    4,   56,  128,   20,    4,    4,   60,   62,   21,
   63,   63,   63,   41,   10,   39,   42,   10,   63,   64,
   63,   63,   46,    4,   45,   63,   63,   47,   49,    4,
   63,   63,   63,   63,   63,   63,   51,   63,   64,   64,
   64,   63,   59,   59,   63,   56,   56,   69,   64,   64,
   21,   75,   59,   64,   64,   96,  109,   23,   64,   64,
   64,   64,   64,   64,  113,   64,   66,   66,   66,   64,
   62,  114,   64,   32,   32,   56,   66,   66,   56,  121,
   62,   66,   66,  125,    8,   45,   66,   66,   66,   66,
   66,   66,   61,   66,   67,   67,   67,   66,   47,   73,
   66,   40,   61,   32,   67,   67,   32,   53,   93,   67,
   67,    0,    0,    0,   67,   67,   67,   67,   67,   67,
    0,   67,   68,   68,   68,   67,    0,    0,   67,   60,
   61,    0,   68,   68,   77,    0,    0,   68,   68,    0,
   62,    0,   68,   68,   68,   68,   68,   68,    0,   68,
   63,   64,   97,   68,   99,  100,   68,   80,   81,    0,
    0,    0,   86,   87,   88,   89,   90,   91,
};
static const short yycheck[] = {                         23,
   47,  264,  273,  274,  259,  260,  260,  266,  271,  258,
  275,  276,  273,  274,  285,   62,  257,  257,  260,  268,
  261,  261,   69,  264,  265,  295,  267,  267,   75,  292,
  271,  272,  272,   57,  289,  289,  258,  292,  293,   86,
   87,   88,   89,   90,   91,  289,  268,  289,  289,   73,
  292,  292,  257,  260,  295,  295,  261,  264,  270,  264,
  265,  257,  267,  295,  271,  261,  271,  272,  264,  292,
  117,  267,  265,  273,  274,  271,  272,  264,  289,  257,
   83,   84,  289,  261,  271,  285,  264,  292,  112,  267,
  295,  257,  116,  271,  272,  261,  292,  258,  264,  295,
  124,  267,  289,  127,  288,  271,  272,  268,  284,  295,
  258,  259,  260,  295,  292,  289,  289,  295,  294,  295,
  268,  269,  284,  289,  295,  273,  274,  284,  264,  295,
  278,  279,  280,  281,  282,  283,  271,  285,  258,  259,
  260,  289,  258,  295,  292,  259,  260,  293,  268,  269,
  264,  293,  268,  273,  274,  285,  268,  271,  278,  279,
  280,  281,  282,  283,  258,  285,  258,  259,  260,  289,
  258,  269,  292,  259,  260,  289,  268,  269,  292,  259,
  268,  273,  274,  258,  289,  269,  278,  279,  280,  281,
  282,  283,  258,  285,  258,  259,  260,  289,  258,   55,
  292,   19,  268,  289,  268,  269,  292,   39,   72,  273,
  274,   -1,   -1,   -1,  278,  279,  280,  281,  282,  283,
   -1,  285,  258,  259,  260,  289,   -1,   -1,  292,  273,
  274,   -1,  268,  269,   60,   -1,   -1,  273,  274,   -1,
  284,   -1,  278,  279,  280,  281,  282,  283,   -1,  285,
  294,  295,   78,  289,   80,   81,  292,  273,  274,   -1,
   -1,   -1,  278,  279,  280,  281,  282,  283,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 295
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
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","PP","EQ","NEQ","LE","LT","GE","GT",
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
"for_statement : FOR IDENT $$13 ASSIGN expression $$14 TO $$15 expression $$16 DO $$17 statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$18 :",
"read_statement : READ LPAREN IDENT $$18 RPAREN",
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
"$$19 :",
"expression : MINUS $$19 term",
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
#line 556 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 412 "y.tab.c"

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
#line 52 "parser.y"
	{init_fstack();}
break;
case 2:
#line 53 "parser.y"
	{
                Factor retval;
                retval.type = CONSTANT;
                retval.cal = 0;
                factorpush(retval);
                create_llvmcode(Ret);
                char fname[256];
                strcpy(fname, "result.ll");
                fp = fopen(fname, "wb");
                fprintf(fp,"@.str = private constant [3 x i8] c\"%%d\\00\", align 1\n");
                fprintf(fp, "@.str.1 = private constant [4 x i8] c\"%%d\\0A\\00\", align 1\n");
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
#line 94 "parser.y"
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
#line 115 "parser.y"
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
#line 146 "parser.y"
	{
                Factor retval;
                strcpy(retval.val,"void");
                factorpush(retval);
                create_llvmcode(Ret);
        }
break;
case 15:
#line 161 "parser.y"
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
#line 175 "parser.y"
	{Proc_Term++;}
break;
case 17:
#line 175 "parser.y"
	{delete(); Proc_Term--;}
break;
case 21:
#line 186 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 22:
#line 192 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->end = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 23:
#line 199 "parser.y"
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
#line 211 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
break;
case 25:
#line 220 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 31:
#line 234 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 32:
#line 235 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 33:
#line 242 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 34:
#line 246 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 35:
#line 251 "parser.y"
	{
                br_decl->uncoll = Last_Register;
        }
break;
case 36:
#line 255 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
break;
case 38:
#line 267 "parser.y"
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
#line 280 "parser.y"
	{
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 41:
#line 285 "parser.y"
	{
                create_llvmcode(BrCond);
        }
break;
case 42:
#line 288 "parser.y"
	{
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 43:
#line 292 "parser.y"
	{
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
break;
case 44:
#line 304 "parser.y"
	{
                factorpush(lookup(yystack.l_mark[0].ident));
        }
break;
case 45:
#line 308 "parser.y"
	{
                create_llvmcode(Store);
        }
break;
case 46:
#line 312 "parser.y"
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
case 47:
#line 328 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 48:
#line 333 "parser.y"
	{
                create_llvmcode(BrCond);
                create_llvmcode(Label);
                Last_Register ++;
        }
break;
case 49:
#line 339 "parser.y"
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
case 51:
#line 371 "parser.y"
	{
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; 
                lookup(yystack.l_mark[0].ident);
                strcpy((tmp->args).call.funcname, yystack.l_mark[0].ident);
                (tmp->args).call.rettype = vo;
                Factor arg1;
                strcpy(arg1.val, "void");
                (tmp->args).call.arg1 = arg1;
                add_llvmnode(tmp);
        }
break;
case 53:
#line 390 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 54:
#line 391 "parser.y"
	{
                
                Factor arg1, retval; 
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; 
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register;
                Last_Register ++;
                (tmp->args).call.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).call.retval = retval; 
                strcpy((tmp->args).call.funcname, "read");
                (tmp->args).call.rettype = I32;
                add_llvmnode(tmp);
        }
break;
case 55:
#line 411 "parser.y"
	{
                
                Factor arg1, retval; 
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; 
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR;
                retval.cal = Last_Register;
                Last_Register ++;
                (tmp->args).call.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).call.retval = retval; 
                strcpy((tmp->args).call.funcname, "write");
                (tmp->args).call.rettype = I32;
                add_llvmnode(tmp);  
        }
break;
case 57:
#line 435 "parser.y"
	{
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
break;
case 58:
#line 440 "parser.y"
	{
                icmptype = NE;
                create_llvmcode(Icmp);
        }
break;
case 59:
#line 445 "parser.y"
	{
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
break;
case 60:
#line 450 "parser.y"
	{
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
break;
case 61:
#line 455 "parser.y"
	{
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
break;
case 62:
#line 460 "parser.y"
	{
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
break;
case 65:
#line 470 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 66:
#line 477 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 67:
#line 481 "parser.y"
	{
                create_llvmcode(Add);
        }
break;
case 68:
#line 485 "parser.y"
	{
                create_llvmcode(Sub);
        }
break;
case 70:
#line 493 "parser.y"
	{
                create_llvmcode(Mul);
        }
break;
case 71:
#line 498 "parser.y"
	{
                create_llvmcode(Div);
        }
break;
case 72:
#line 506 "parser.y"
	{
                create_llvmcode(Load);
        }
break;
case 73:
#line 510 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 75:
#line 520 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 78:
#line 530 "parser.y"
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
case 79:
#line 543 "parser.y"
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
#line 1113 "y.tab.c"
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
