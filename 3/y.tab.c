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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int yylineno;
extern char *yytext;

/*記号表の管理+変数・定数の区別用*/
typedef enum {
        GLOBAL_VAR, /*大域変数*/
        LOCAL_VAR,  /*局所変数*/
        PROC_NAME,  /*手続き*/
} Scope;

typedef struct symbol{
        Scope type; /* 変数, 手続きの区別 */
        char val[MAXLENGTH+1]; /* 変数や手続きの場合の名前 */ 
        int cal; /* 変数の場合割り当てたレジスタ番号 */
        struct symbol *before;
        struct symbol *next;
} Symbol;


int Proc_Term = 0;
Symbol *Stack_hd = NULL;
Symbol *Stack_tl = NULL;
int Last_Register = 2;

void lookall(Symbol *SymboL){
        if (SymboL == NULL) return;
        switch (SymboL->type) {
                case GLOBAL_VAR:
                        printf("== GLOBAL       %s\n", SymboL->val);
                        break;
                case LOCAL_VAR:
                        printf("== LOCAL    %d   %s\n", SymboL->cal, SymboL->val);
                        break;
                case PROC_NAME:
                        printf("== PROC         %s\n", SymboL->val);
                        break;
        }
        lookall(SymboL->next);
        return;
}

void insert(char *name, int flag) {
        printf("insert\n");
        Symbol *tmp;
        tmp = (Symbol *)malloc(sizeof(Symbol));
        tmp->type = flag + Proc_Term;
        tmp->before = Stack_tl;
        tmp->next = NULL;
        strcpy(tmp->val, name);
        if (tmp->type == LOCAL_VAR) {
                tmp->cal = Last_Register;
                Last_Register++;
        }
        if (Stack_hd == NULL){
                Stack_hd = tmp;
        } else {
                Stack_tl->next = tmp;
        }
        Stack_tl = tmp;
        printf("======================\n");
        lookall(Stack_hd);
        printf("======================\n");
}

void lookup(char *name){
        Symbol *symb;
        symb = Stack_tl;
        while (strcmp(symb->val, name)){
                symb = symb->before;
                if (symb == NULL){
                        printf("No Member(This is Error)\n");
                        return;
                }
        }
        switch (symb->type) {
                case GLOBAL_VAR:
                        printf("FOUND == GLOBAL       %s\n", symb->val);
                        break;
                case LOCAL_VAR:
                        printf("FOUND == LOCAL    %d   %s\n", symb->cal, symb->val);
                        break;
                case PROC_NAME:
                        printf("FOUND == PROC         %s\n", symb->val);
                        break;
        }
}

void delete(){
        printf("delete\n");
        Symbol *tmp;
        while((Stack_tl->type == LOCAL_VAR)){
                tmp = Stack_tl->before;
                free(Stack_tl);
                Stack_tl = tmp;
                Stack_tl->next = NULL;
        }
        printf("======================\n");
        lookall(Stack_hd);
        printf("======================\n");
        Last_Register = 2;
}

void __del__(){
        Symbol *tmp;
        while (Stack_hd != NULL){
                tmp = Stack_hd->next;
                free(Stack_hd);
                Stack_hd = tmp;
        }
}
#line 123 "parser.y"
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
#line 151 "y.tab.c"

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
    0,    1,    2,    2,    5,    5,    6,    3,    3,    8,
    8,    9,   10,   11,   13,   12,   14,   14,    4,    4,
    4,    4,    4,    4,    4,    4,    4,   24,   15,   16,
   27,   27,   17,   28,   18,   19,   29,   21,   30,   22,
   23,   20,   26,   26,   26,   26,   26,   26,   25,   25,
   25,   25,   25,   31,   31,   31,   32,   32,   32,   33,
   34,   34,    7,    7,
};
static const short yylen[] = {                            2,
    5,    3,    0,    2,    3,    1,    2,    0,    2,    3,
    1,    1,    4,    1,    0,    3,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    0,    4,    5,
    0,    2,    4,    0,    9,    1,    1,    3,    0,    5,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    2,    3,    3,    1,    3,    3,    1,    1,    3,    1,
    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   63,
    0,    1,    0,    0,    0,   11,   12,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    2,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   36,    0,
    5,   64,   15,   18,    0,   34,    0,    0,    0,   58,
   60,    0,    0,    0,   54,   57,    0,    0,    0,    0,
   10,   13,    0,   38,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   39,    0,    0,    0,    0,   17,    0,   59,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   55,   56,    0,
   33,   41,    0,   16,    0,    0,   30,   40,    0,   32,
    0,    0,   35,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   29,    8,    9,   11,   15,   16,   17,
   21,   62,   63,   45,   30,   31,   32,   33,   34,   35,
   36,   37,   38,   60,   52,   53,  107,   66,   39,  100,
   54,   55,   56,    0,
};
static const short yysindex[] = {                      -260,
 -282,    0, -274, -250, -271, -245, -234, -253,    0,    0,
 -220,    0, -230, -151, -215,    0,    0, -250, -196,    0,
 -209, -151, -194,  -33, -180,  -33, -172,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -234,
    0,    0,    0,    0, -256,    0, -278, -278,  -33,    0,
    0,   -9, -187, -267,    0,    0, -177, -124,  -33, -150,
    0,    0, -250,    0, -151, -142, -267, -267, -145, -278,
 -278,  -33,  -33,  -33,  -33,  -33,  -33, -151, -278, -278,
    0, -151, -114,  -33, -151,    0,  -33,    0, -267, -267,
 -117, -117, -117, -117, -117, -117,  -95,    0,    0, -115,
    0,    0, -117,    0, -108, -151,    0,    0,  -33,    0,
 -199, -151,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -195,    0,    0, -254,    0,    0,    0,
 -111,    0,    0, -107,    0,    0,    0, -223,    0,    0,
    0, -241,    0,    0,    0,    0,    0, -238,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -179,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -133,    0,    0,    0,    0,    0,    0,
    0,    0, -170,    0, -241,    0, -106,  -79,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -208,    0,    0,
    0, -208,    0,    0, -105,    0,    0,    0,  -52,  -25,
 -213, -163, -154, -149, -136, -135, -258,    0,    0,    0,
    0,    0, -202,    0,    0, -208,    0,    0,    0,    0,
    0, -208,    0,
};
static const short yygindex[] = {                         0,
    0,  123,    0,  -22,    0,  169,    0,    0,  148,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -48,  165,    0,    0,    0,    0,
   60,   58,    0,    0,
};
#define YYTABLESIZE 273
static const short yytable[] = {                         44,
   69,   31,    8,   64,   49,    1,    8,   79,   80,    8,
   83,    3,    8,    4,   50,   51,    8,    8,   42,    5,
   37,   37,   10,   91,   92,   93,   94,   95,   96,   31,
   13,   65,   31,    4,   18,  103,    8,    4,  105,    8,
    4,    4,   86,    4,   43,   12,   42,    4,    4,   37,
   42,   42,   37,   28,   43,   97,   29,   29,  112,  101,
  111,    3,  104,   20,    4,    3,   19,    4,    3,    3,
    4,    3,   40,   70,   71,    3,    3,    9,   43,   42,
   78,    9,   42,  110,    9,   29,    3,    9,   29,  113,
    3,    9,    9,    3,   44,    3,    3,   42,    3,   46,
    3,    3,   57,   46,   44,   22,   67,   68,   45,   23,
   59,    9,   24,   46,    9,   25,   81,    3,   45,   26,
   27,   48,   47,    3,   49,   49,   49,   70,   71,   89,
   90,   48,   47,   82,   49,   49,   98,   99,   88,   49,
   49,   84,   28,   49,   49,   49,   49,   49,   49,   87,
   49,   50,   50,   50,   49,   70,   71,   49,   70,   71,
  109,   50,   50,  106,   70,   71,   50,   50,  108,  102,
   50,   50,   50,   50,   50,   50,    7,   50,   51,   51,
   51,   50,   42,   42,   50,   85,   41,   61,   51,   51,
   58,    0,    0,   51,   51,    0,    0,   51,   51,   51,
   51,   51,   51,    0,   51,   52,   52,   52,   51,    0,
    0,   51,    0,    0,    0,   52,   52,    0,    0,    0,
   52,   52,    0,    0,   52,   52,   52,   52,   52,   52,
    0,   52,   53,   53,   53,   52,    0,    0,   52,   47,
   48,    0,   53,   53,    0,    0,    0,   53,   53,   49,
    0,   53,   53,   53,   53,   53,   53,    0,   53,   50,
   51,    0,   53,   70,   71,   53,    0,   72,   73,   74,
   75,   76,   77,
};
static const short yycheck[] = {                         22,
   49,  260,  257,  260,  283,  266,  261,  275,  276,  264,
   59,  294,  267,  288,  293,  294,  271,  272,  260,  270,
  259,  260,  294,   72,   73,   74,   75,   76,   77,  288,
  265,  288,  291,  257,  288,   84,  291,  261,   87,  294,
  264,  265,   65,  267,  258,  291,  288,  271,  272,  288,
  259,  260,  291,  292,  268,   78,  259,  260,  258,   82,
  109,  257,   85,  294,  288,  261,  287,  291,  264,  265,
  294,  267,  288,  273,  274,  271,  272,  257,  288,  288,
  268,  261,  291,  106,  264,  288,  257,  267,  291,  112,
  261,  271,  272,  264,  258,  291,  267,  294,  294,  294,
  271,  272,  283,  258,  268,  257,   47,   48,  258,  261,
  283,  291,  264,  268,  294,  267,  294,  288,  268,  271,
  272,  258,  258,  294,  258,  259,  260,  273,  274,   70,
   71,  268,  268,  258,  268,  269,   79,   80,  284,  273,
  274,  292,  294,  277,  278,  279,  280,  281,  282,  292,
  284,  258,  259,  260,  288,  273,  274,  291,  273,  274,
  269,  268,  269,  259,  273,  274,  273,  274,  284,  284,
  277,  278,  279,  280,  281,  282,  288,  284,  258,  259,
  260,  288,  288,  291,  291,   63,   18,   40,  268,  269,
   26,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,  258,  259,  260,  288,   -1,
   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,  273,
  274,   -1,  268,  269,   -1,   -1,   -1,  273,  274,  283,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,  293,
  294,   -1,  288,  273,  274,  291,   -1,  277,  278,  279,
  280,  281,  282,
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
"program : PROGRAM IDENT SEMICOLON outblock PERIOD",
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
"$$1 :",
"inblock : $$1 var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$2 :",
"assignment_statement : IDENT $$2 ASSIGN expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement :",
"else_statement : ELSE statement",
"while_statement : WHILE condition DO statement",
"$$3 :",
"for_statement : FOR IDENT $$3 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$4 :",
"read_statement : READ LPAREN IDENT $$4 RPAREN",
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
"expression : MINUS term",
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
#line 302 "parser.y"
 

yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=q%s\n", s, yylineno, yytext);
}
#line 486 "y.tab.c"

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
#line 147 "parser.y"
	{
                __del__();
        }
break;
case 14:
#line 189 "parser.y"
	{ insert(yystack.l_mark[0].ident, 2); }
break;
case 15:
#line 193 "parser.y"
	{Proc_Term++;}
break;
case 16:
#line 193 "parser.y"
	{delete(); Proc_Term--;}
break;
case 28:
#line 214 "parser.y"
	{ lookup(yystack.l_mark[0].ident);}
break;
case 34:
#line 231 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 37:
#line 240 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 39:
#line 248 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 60:
#line 289 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 63:
#line 298 "parser.y"
	{ insert(yystack.l_mark[0].ident, 0); }
break;
case 64:
#line 299 "parser.y"
	{ insert(yystack.l_mark[0].ident, 0); }
break;
#line 738 "y.tab.c"
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
