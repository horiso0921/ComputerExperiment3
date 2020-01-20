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
extern int yylineno;
extern char *yytext;

int Proc_Term = 0;
Factor *Stack_hd = NULL;
Factor *Stack_tl = NULL;
int Last_Register = 1;

void lookall(Factor *factor){
        if (factor == NULL) return;
        switch (factor->type) {
                case GLOBAL_VAR:
                        printf("== GLOBAL       %s\n", factor->val);
                        break;
                case LOCAL_VAR:
                        printf("== LOCAL    %d   %s\n", factor->cal, factor->val);
                        break;
                case PROC_NAME:
                        printf("== PROC         %s\n", factor->val);
                        break;
        }
        lookall(factor->next);
        return;
}

Factor insert(char *name, int flag) {
        printf("insert\n");
        Factor *tmp;
        tmp = (Factor *)malloc(sizeof(Factor));
        tmp->type = flag + Proc_Term;
        tmp->before = Stack_tl;
        tmp->next = NULL;
        strcpy(tmp->val, name);
        if (tmp->type == LOCAL_VAR) {
                tmp->cal = Last_Register;
                Last_Register++;
        } else {
                tmp->cal = -1;
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
        Factor res;
        res.type = tmp->type;
        res.cal = tmp->cal;
        strcpy(res.val, name);
        return res;
}

Factor lookup(char *name){
        Factor *fact;
        fact = Stack_tl;
        while (strcmp(fact->val, name)){
                fact = fact->before;
                if (fact == NULL){
                        printf("No Member(This is Error)\n");
                        Factor res;
                        return res;
                }
        }
        switch (fact->type) {
                case GLOBAL_VAR:
                        printf("FOUND == GLOBAL       %s\n", fact->val);
                        break;
                case LOCAL_VAR:
                        printf("FOUND == LOCAL    %d   %s\n", fact->cal, fact->val);
                        break;
                case PROC_NAME:
                        printf("FOUND == PROC         %s\n", fact->val);
                        break;
        }
        Factor res;
        res.type = fact->type;
        res.cal = fact->cal;
        strcpy(res.val, name);
        return res;
}

void delete(){
        printf("delete\n");
        Factor *tmp;
        while((Stack_tl->type == LOCAL_VAR)){
                tmp = Stack_tl->before;
                free(Stack_tl);
                Stack_tl = tmp;
                Stack_tl->next = NULL;
        }
        printf("======================\n");
        lookall(Stack_hd);
        printf("======================\n");
        Last_Register = 1;
}

void __del__(){
        Factor *tmp;
        while (Stack_hd != NULL){
                tmp = Stack_hd->next;
                free(Stack_hd);
                Stack_hd = tmp;
        }
}

void displayFactor( Factor factor ,FILE *fp){
        switch( factor.type ){
                case GLOBAL_VAR:
                        fprintf(fp,"@%s", factor.val );
                        break;
                case LOCAL_VAR:
                        fprintf(fp,"%%%d", factor.cal );
                        break;
                case CONSTANT:
                        fprintf(fp,"%d", factor.cal );
                        break;
                default:
                        break;
        }
        return;
}

void displayLlvmcodes( LLVMcode *code ,FILE *fp){
        if( code == NULL ) return;
        if( code->command  != Global)fprintf(fp,"  ");
        switch( code->command ){
                case Alloca:
                        displayFactor( (code->args).alloca.retval ,fp);
                        fprintf(fp," = alloca i32, align 4\n");
                        break;
                case Global:
                        displayFactor( (code->args).global.retval ,fp);
                        fprintf(fp," = common global i32 0, align 4\n");
                        break;
                case Store:
                        fprintf(fp,"store i32 ");
                        displayFactor( (code->args).store.arg1 ,fp);
                        fprintf(fp,", i32* ");
                        displayFactor( (code->args).store.arg2 ,fp);
                        fprintf(fp,", align 4\n");
                        break;
                case Load:
                        displayFactor( (code->args).load.retval,fp);
                        fprintf(fp," = load i32, i32* ");
                        displayFactor( (code->args).load.arg1 ,fp);
                        fprintf(fp,", align 4\n");
                        break;
                case Add:
                        displayFactor( (code->args).cal.retval ,fp);
                        fprintf(fp," = add nsw i32 ");
                        displayFactor( (code->args).cal.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).cal.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Sub:
                        displayFactor( (code->args).cal.retval,fp );
                        fprintf(fp," = sub nsw i32 ");
                        displayFactor( (code->args).cal.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).cal.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Mul:
                        displayFactor( (code->args).cal.retval,fp );
                        fprintf(fp," = mul nsw i32 ");
                        displayFactor( (code->args).cal.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).cal.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Div:
                        displayFactor( (code->args).cal.retval,fp );
                        fprintf(fp," = sdiv i32 ");
                        displayFactor( (code->args).cal.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).cal.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Ret:
                        if (strcmp((code->args).ret.arg1.val, "void")) {
                                fprintf(fp,"ret i32 "); 
                                displayFactor( (code->args).ret.arg1,fp);
                        } else {
                                fprintf(fp,"ret void"); 
                        }
                        fprintf(fp,"\n");
                        break;
                default:
                        fprintf(fp,"This is error");
                        break;
        }
        displayLlvmcodes( code->next,fp );
}

void displayLlvmfundecl( Fundecl *decl ,FILE *fp){
        if( decl == NULL ) return;
        if (strcmp(decl->fname, "main")){
                fprintf(fp, "define void @%s() {\n", decl->fname );
        } else {
                fprintf(fp, "define i32 @%s() {\n", decl->fname );
        }
        displayLlvmcodes( decl->codes,fp );
        fprintf(fp,"}\n");
        if( decl->next != NULL ) {
                fprintf(fp,"\n");
                displayLlvmfundecl(decl->next,fp);
        }
        return;
}

void add_node(LLVMcode *tmp){
        if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                if( decltl == NULL ){ /* 解析中の関数がない場合 */
                        /* 関数宣言を処理する段階でリストが作られているので，ありえない */
                        fprintf(stderr,"unexpected error 1\n");
                }
                decltl->codes = tmp; /* 関数定義の命令列の先頭の命令に設定 */
                codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
        } else { /* 解析中の関数の命令列に 1 つ以上命令が存在する場合 */
                codetl->next = tmp; /* 命令列の末尾に追加 */
                codetl = tmp; /* 命令列の末尾の命令として記憶 */
        }
}
void add_globalnode(LLVMcode *tmp){
        if (global_codehd == NULL){
                Fundecl *glob;
                glob = (Fundecl *)malloc(sizeof(Fundecl));
                global_decl = glob;
                global_decl->codes = tmp;
                global_codehd = tmp;
        } else {
                global_codetl->next = tmp;
        }
        global_codetl = tmp;
        return;
}

#line 255 "parser.y"
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
#line 283 "y.tab.c"

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
    5,    5,    5,    5,    5,    5,    5,    5,   25,   16,
   17,   28,   28,   18,   29,   19,   20,   30,   22,   31,
   23,   24,   21,   27,   27,   27,   27,   27,   27,   26,
   26,   33,   26,   26,   26,   32,   32,   32,   34,   34,
   34,   35,   36,   36,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    1,    0,    3,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    0,    4,
    5,    0,    2,    4,    0,    9,    1,    1,    3,    0,
    5,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    0,    3,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   65,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    3,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   37,
    0,    6,   66,   16,   19,    0,   35,    0,   52,    0,
   60,   62,    0,    0,    0,   56,   59,    0,    0,    0,
    0,   11,   14,    0,   39,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   40,    0,    0,    0,    0,   18,    0,    0,   61,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   57,
   58,    0,   34,   42,    0,   17,    0,    0,   31,   41,
    0,   33,    0,    0,   36,
};
static const short yydgoto[] = {                          2,
    3,    7,    8,   15,   30,    9,   10,   12,   16,   17,
   18,   22,   63,   64,   46,   31,   32,   33,   34,   35,
   36,   37,   38,   39,   61,   53,   54,  109,   67,   40,
  102,   55,   69,   56,   57,    0,
};
static const short yysindex[] = {                      -258,
    0,    0, -284, -274, -254, -273, -236, -232, -231,    0,
    0, -178,    0, -181, -252, -167,    0,    0, -254, -164,
    0, -153, -252, -140,  -35, -128,  -35, -124,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -232,    0,    0,    0,    0, -247,    0, -217,    0,  -35,
    0,    0,  -11, -120, -223,    0,    0, -131,  -96,  -35,
 -125,    0,    0, -254,    0, -252, -117, -223, -217, -179,
 -217, -217,  -35,  -35,  -35,  -35,  -35,  -35, -252, -217,
 -217,    0, -252, -116,  -35, -252,    0,  -35, -223,    0,
 -223, -223, -133, -133, -133, -133, -133, -133,  -95,    0,
    0, -103,    0,    0, -133,    0, -267, -252,    0,    0,
  -35,    0, -155, -252,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -192,    0,    0, -183,    0,    0,
    0, -106,    0,    0, -107,    0,    0,    0, -227,    0,
    0,    0, -229,    0,    0,    0,    0,    0, -242,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -174,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -135,    0,    0,    0,    0,    0,
    0,    0,    0, -157,    0, -229,    0, -108,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -256,    0,
    0,    0, -256,    0,    0, -102,    0,    0,  -81,    0,
  -54,  -27, -210, -176, -172, -152, -146, -132, -159,    0,
    0,    0,    0,    0, -237,    0,    0, -256,    0,    0,
    0,    0,    0, -256,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  121,    0,  -23,    0,  170,    0,    0,  149,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -49,  164,    0,    0,    0,
    0,   -1,    0,   47,    0,    0,
};
#define YYTABLESIZE 271
static const short yytable[] = {                         45,
   70,  111,   43,   43,   23,   71,   72,    1,   24,    4,
   84,   25,   65,    5,   26,    6,   38,   38,   27,   28,
   11,   30,   30,   93,   94,   95,   96,   97,   98,    5,
   43,   43,   14,    5,   43,  105,    5,    5,  107,    5,
   66,   29,   87,    5,    5,   38,   68,   44,   38,   29,
   30,   80,   81,   30,   13,   99,   19,   44,   43,  103,
    5,  113,  106,    5,    4,   50,    5,   89,    4,   91,
   92,    4,    4,    9,    4,   51,   52,    9,    4,    4,
    9,   45,   10,    9,  112,   47,   10,    9,    9,   10,
  115,   45,   10,   71,   72,   47,   10,   10,    4,    4,
   32,    4,  114,    4,   90,   46,    4,    9,   20,    4,
    9,   49,   21,    4,    4,   46,   10,   71,   72,   10,
   41,   49,   50,   50,   50,   48,  100,  101,   32,   43,
    4,   32,   50,   50,   44,   48,    4,   50,   50,   71,
   72,   50,   50,   50,   50,   50,   50,   79,   50,   51,
   51,   51,   50,   47,   58,   50,   71,   72,   60,   51,
   51,   83,   82,  108,   51,   51,   85,  104,   51,   51,
   51,   51,   51,   51,   88,   51,   53,   53,   53,   51,
  110,    8,   51,   43,   86,   43,   53,   53,   42,   62,
   59,   53,   53,    0,    0,   53,   53,   53,   53,   53,
   53,    0,   53,   54,   54,   54,   53,    0,    0,   53,
    0,    0,    0,   54,   54,    0,    0,    0,   54,   54,
    0,    0,   54,   54,   54,   54,   54,   54,    0,   54,
   55,   55,   55,   54,    0,    0,   54,   48,   49,    0,
   55,   55,    0,    0,    0,   55,   55,   50,    0,   55,
   55,   55,   55,   55,   55,    0,   55,   51,   52,    0,
   55,   71,   72,   55,    0,   73,   74,   75,   76,   77,
   78,
};
static const short yycheck[] = {                         23,
   50,  269,  259,  260,  257,  273,  274,  266,  261,  294,
   60,  264,  260,  288,  267,  270,  259,  260,  271,  272,
  294,  259,  260,   73,   74,   75,   76,   77,   78,  257,
  260,  288,  265,  261,  291,   85,  264,  265,   88,  267,
  288,  294,   66,  271,  272,  288,   48,  258,  291,  292,
  288,  275,  276,  291,  291,   79,  288,  268,  288,   83,
  288,  111,   86,  291,  257,  283,  294,   69,  261,   71,
   72,  264,  265,  257,  267,  293,  294,  261,  271,  272,
  264,  258,  257,  267,  108,  258,  261,  271,  272,  264,
  114,  268,  267,  273,  274,  268,  271,  272,  291,  257,
  260,  294,  258,  261,  284,  258,  264,  291,  287,  267,
  294,  258,  294,  271,  272,  268,  291,  273,  274,  294,
  288,  268,  258,  259,  260,  258,   80,   81,  288,  294,
  288,  291,  268,  269,  288,  268,  294,  273,  274,  273,
  274,  277,  278,  279,  280,  281,  282,  268,  284,  258,
  259,  260,  288,  294,  283,  291,  273,  274,  283,  268,
  269,  258,  294,  259,  273,  274,  292,  284,  277,  278,
  279,  280,  281,  282,  292,  284,  258,  259,  260,  288,
  284,  288,  291,  291,   64,  288,  268,  269,   19,   41,
   27,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
  258,  259,  260,  288,   -1,   -1,  291,  273,  274,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,  283,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,  293,  294,   -1,
  288,  273,  274,  291,   -1,  277,  278,  279,  280,  281,
  282,
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
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$3 :",
"assignment_statement : IDENT $$3 ASSIGN expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement :",
"else_statement : ELSE statement",
"while_statement : WHILE condition DO statement",
"$$4 :",
"for_statement : FOR IDENT $$4 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$5 :",
"read_statement : READ LPAREN IDENT $$5 RPAREN",
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
"$$6 :",
"expression : MINUS $$6 term",
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
#line 705 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 620 "y.tab.c"

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
#line 278 "parser.y"
	{init_fstack();}
break;
case 2:
#line 279 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = Ret;
                tmp->next = NULL;
                Factor retval;
                retval.type = CONSTANT;
                retval.cal = 0;
                (tmp->args).ret.arg1 = retval;
                add_node(tmp);
                char fname[256];
                strcpy(fname, "result.ll");
                FILE *fp = fopen(fname, "wb");
                if(global_decl != NULL ) {displayLlvmcodes(global_decl->codes,fp );
                fprintf(fp,"\n");}
                displayLlvmfundecl( declhd ,fp );
                fclose(fp);
        }
break;
case 9:
#line 319 "parser.y"
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
                Last_Register++;
                LLVMcode *x;
                x = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                x->next = NULL; /* 次の命令へのポインタを初期化 */
                x->command = Alloca; 
                (x->args).alloca.retval = ftmp; /* 命令の第 2 引数を指定 */
                add_node(x);
                factorpush(ftmp);
                Factor f1tmp;
                f1tmp.type = CONSTANT;
                f1tmp.cal = 0;
                factorpush(f1tmp);
                LLVMcode *ltmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2; 
                ltmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                ltmp->next = NULL; /* 次の命令へのポインタを初期化 */
                ltmp->command = Store; 
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                (ltmp->args).store.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (ltmp->args).store.arg2 = arg2; /* 命令の第 2 引数を指定 */
                add_node(ltmp);
        }
break;
case 10:
#line 353 "parser.y"
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
                Last_Register++;
                LLVMcode *x;
                x = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                x->next = NULL; /* 次の命令へのポインタを初期化 */
                x->command = Alloca; 
                (x->args).alloca.retval = ftmp; /* 命令の第 2 引数を指定 */
                add_node(x);
                factorpush(ftmp);
                Factor f1tmp;
                f1tmp.type = CONSTANT;
                f1tmp.cal = 0;
                factorpush(f1tmp);
                LLVMcode *ltmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2; 
                ltmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                ltmp->next = NULL; /* 次の命令へのポインタを初期化 */
                ltmp->command = Store; 
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                (ltmp->args).store.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (ltmp->args).store.arg2 = arg2; /* 命令の第 2 引数を指定 */
                add_node(ltmp);
        }
break;
case 13:
#line 396 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = Ret;
                tmp->next = NULL;
                Factor retval;
                strcpy(retval.val,"void");
                (tmp->args).ret.arg1 = retval;
                add_node(tmp);
        }
break;
case 15:
#line 414 "parser.y"
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
#line 428 "parser.y"
	{Proc_Term++;}
break;
case 17:
#line 428 "parser.y"
	{delete(); Proc_Term--;}
break;
case 29:
#line 449 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 30:
#line 450 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Store; /* 命令の種類を加算に設定 */
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                (tmp->args).store.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).store.arg2 = arg2; /* 命令の第 2 引数を指定 */
                add_node(tmp);
        }
break;
case 35:
#line 478 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 38:
#line 487 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 40:
#line 495 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 52:
#line 519 "parser.y"
	{
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
break;
case 53:
#line 525 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 減算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Sub; /* 命令の種類を減算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).cal.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).cal.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).cal.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 減算の結果をスタックにプッシュ */
        }
break;
case 54:
#line 543 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Add; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).cal.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).cal.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).cal.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 55:
#line 561 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Sub; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).cal.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).cal.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).cal.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 57:
#line 583 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Mul; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).cal.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).cal.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).cal.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 58:
#line 602 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Div; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).cal.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).cal.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).cal.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 59:
#line 623 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Load; /* 命令の種類を加算に設定 */
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register++;
                (tmp->args).load.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).load.retval = retval; /* 命令の第 2 引数を指定 */
                add_node(tmp);  
                factorpush(retval);
        }
break;
case 60:
#line 639 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 62:
#line 649 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 65:
#line 659 "parser.y"
	{ 
                Factor tmp;
                tmp = insert(yystack.l_mark[0].ident, 0); 
                LLVMcode *x; /* 生成した命令へのポインタ */
                
                switch(Proc_Term){
                        case GLOBAL_VAR:
                                x = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                                x->next = NULL; /* 次の命令へのポインタを初期化 */
                                x->command = Global; /* 命令の種類を加算に設定 */
                                (x->args).global.retval = tmp; /* 命令の第 2 引数を指定 */
                                add_globalnode(x);
                                break;
                        case LOCAL_VAR:
                                x = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                                x->next = NULL; /* 次の命令へのポインタを初期化 */
                                x->command = Alloca; /* 命令の種類を加算に設定 */
                                (x->args).alloca.retval = tmp; /* 命令の第 2 引数を指定 */
                                add_node(x);
                                break;
                }
        }
break;
case 66:
#line 682 "parser.y"
	{ 
                Factor tmp;
                tmp = insert(yystack.l_mark[0].ident, 0); 
                LLVMcode *x; /* 生成した命令へのポインタ */
                switch(Proc_Term){
                        case GLOBAL_VAR:
                                x = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                                x->next = NULL; /* 次の命令へのポインタを初期化 */
                                x->command = Global; /* 命令の種類を加算に設定 */
                                (x->args).global.retval = tmp; /* 命令の第 2 引数を指定 */
                                add_globalnode(x);
                                break;
                        case LOCAL_VAR:
                                x = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                                x->next = NULL; /* 次の命令へのポインタを初期化 */
                                x->command = Alloca; /* 命令の種類を加算に設定 */
                                (x->args).alloca.retval = tmp; /* 命令の第 2 引数を指定 */
                                add_node(x);
                                break;
                }
        }
break;
#line 1179 "y.tab.c"
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
