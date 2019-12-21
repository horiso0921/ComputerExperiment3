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
        /* printf("insert\n");*/
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
        /* printf("======================\n");*/
        /* lookall(Stack_hd);*/
        /* printf("======================\n");*/
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
        /* switch (fact->type) {*/
        /*         case GLOBAL_VAR:*/
        /*                 printf("FOUND == GLOBAL       %s\n", fact->val);*/
        /*                 break;*/
        /*         case LOCAL_VAR:*/
        /*                 printf("FOUND == LOCAL    %d   %s\n", fact->cal, fact->val);*/
        /*                 break;*/
        /*         case PROC_NAME:*/
        /*                 printf("FOUND == PROC         %s\n", fact->val);*/
        /*                 break;*/
        /* }*/
        Factor res;
        res.type = fact->type;
        res.cal = fact->cal;
        strcpy(res.val, name);
        return res;
}

void delete(){
        /* printf("delete\n");*/
        Factor *tmp;
        while((Stack_tl->type == LOCAL_VAR)){
                tmp = Stack_tl->before;
                free(Stack_tl);
                Stack_tl = tmp;
                Stack_tl->next = NULL;
        }
        /* printf("======================\n");*/
        /* lookall(Stack_hd);*/
        /* printf("======================\n");*/
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

void displayCmptype( Cmptype cmptype, FILE *fp){
        switch(cmptype){
                case EQUAL:
                        fprintf(fp,"eq" );
                        break;
                case NE:
                        fprintf(fp,"ne" );
                        break;
                case SGT:
                        fprintf(fp,"sgt" );
                        break;
                case SGE:
                        fprintf(fp,"sge" );
                        break;
                case SLT:
                        fprintf(fp,"slt" );
                        break;
                case SLE:
                        fprintf(fp,"sle" );
                        break;
                default:
                        break;
        }
}

void displayLlvmcodes( LLVMcode *code ,FILE *fp){
        if( code == NULL ) return;
        if( code->command  != Global && code->command != Label)fprintf(fp,"  ");
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
                case BrUncond:
                        fprintf(fp, "br label %%%d\n\n",(code->args).bruncond.arg1);
                        break;
                case BrCond:
                        fprintf(fp, "br i1 ");
                        displayFactor((code->args).brcond.arg1, fp);
                        fprintf(fp, ", label %%%d, label %%%d\n\n", *(code->args).brcond.arg2, *(code->args).brcond.arg3);
                        break;
                case Label:
                        fprintf(fp, "%d:\n",(code->args).label.l);
                        break;
                case Add:
                        displayFactor( (code->args).add.retval ,fp);
                        fprintf(fp," = add nsw i32 ");
                        displayFactor( (code->args).add.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).add.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Sub:
                        displayFactor( (code->args).sub.retval,fp );
                        fprintf(fp," = sub nsw i32 ");
                        displayFactor( (code->args).sub.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).sub.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Mul:
                        displayFactor( (code->args).mul.retval,fp );
                        fprintf(fp," = mul nsw i32 ");
                        displayFactor( (code->args).mul.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).mul.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Div:
                        displayFactor( (code->args).div.retval,fp );
                        fprintf(fp," = sdiv i32 ");
                        displayFactor( (code->args).div.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor( (code->args).div.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                case Call:
                        if  (!strcmp((code->args).call.funcname, "write")){
                                displayFactor( (code->args).call.retval,fp );
                                fprintf(fp," = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 ");
                                displayFactor( (code->args).call.arg1,fp );
                        } else if (!strcmp((code->args).call.funcname, "read")){
                                displayFactor( (code->args).call.retval,fp );
                                fprintf(fp," = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* ");
                                displayFactor( (code->args).call.arg1,fp );
                        } else{
                                if ((code->args).call.rettype == I32){
                                        displayFactor( (code->args).call.retval,fp );
                                        fprintf(fp," = call i32 @%s", (code->args).call.funcname);
                                } else {
                                        fprintf(fp,"call void @%s", (code->args).call.funcname);
                                }
                                if (!strcmp((code->args).call.arg1.val, "void")){
                                        fprintf(fp,"(");
                                } else {
                                        fprintf(fp,"( i32");
                                        displayFactor( (code->args).call.arg1,fp);
                                }
                        }
                        fprintf(fp,")\n");
                        break;
                case Ret:
                        if ((code->args).ret.arg1.type == CONSTANT) {
                                fprintf(fp,"ret i32 "); 
                                displayFactor( (code->args).ret.arg1,fp);
                        } else {
                                fprintf(fp,"ret void"); 
                        }
                        fprintf(fp,"\n");
                        break;
                case Icmp:
                        displayFactor((code->args).icmp.retval,fp);
                        fprintf(fp," = icmp ");
                        displayCmptype((code->args).icmp.type,fp);
                        fprintf(fp," i32 ");
                        displayFactor((code->args).icmp.arg1,fp);
                        fprintf(fp,", ");
                        displayFactor((code->args).icmp.arg2,fp);
                        fprintf(fp,"\n");
                        break;
                default:
                        fprintf(fp,"This is error\n");
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

void add_brnode(Brdecl *tmp){
        if (!(br_decl == NULL)){
                br_decl->next = tmp;
        }
        tmp->next = NULL;
        tmp->before = br_decl;
        br_decl = tmp;
}

#line 335 "parser.y"
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
#line 363 "y.tab.c"

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
   18,    5,   20,    5,   22,    5,    5,    5,    5,    5,
    5,   28,   16,   31,   32,   33,   17,   34,   35,   34,
   36,   37,   38,   19,   21,   23,   39,   25,   40,   26,
   27,   24,   30,   30,   30,   30,   30,   30,   29,   29,
   29,   29,   29,   41,   41,   41,   42,   42,   42,   43,
   44,   44,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    1,    0,    3,    3,    1,    1,
    0,    2,    0,    2,    0,    2,    1,    1,    1,    1,
    1,    0,    4,    0,    0,    0,    8,    0,    0,    3,
    0,    0,    0,    7,    6,    1,    1,    3,    0,    5,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    2,    3,    3,    1,    3,    3,    1,    1,    3,    1,
    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   73,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   15,    0,    0,    0,    0,    0,    3,   20,    0,    0,
    0,   27,   28,   29,   30,   31,   46,    0,    6,   74,
   16,   19,    0,    0,    0,    0,   34,   22,   41,   24,
    0,   26,   11,   14,    0,   48,    0,   49,    0,    0,
    0,   68,   70,    0,    0,   64,   67,    0,    0,    0,
   32,    0,    0,   18,    0,    0,    0,    0,    0,    0,
   51,    0,    0,    0,    0,   35,   42,    0,   17,   50,
   69,    0,    0,   65,   66,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,   43,    0,    0,    0,   45,    0,   44,   39,   37,
    0,   40,
};
static const short yydgoto[] = {                          2,
    3,    7,    8,   15,   27,    9,   10,   12,   16,   17,
   18,   22,   54,   55,   43,   28,   48,   29,   50,   30,
   52,   31,   32,   33,   34,   35,   36,   46,   85,   86,
   69,  102,  114,  120,  121,   70,  103,  115,   37,   75,
   65,   66,   67,    0,
};
static const short yysindex[] = {                      -261,
    0,    0, -287, -279, -241, -249, -242, -206, -226,    0,
    0, -222,    0, -223, -209, -215,    0,    0, -241, -217,
    0, -208, -209, -187, -165,    0,    0,    0, -171, -157,
 -136,    0,    0,    0,    0,    0,    0, -206,    0,    0,
    0,    0, -257, -155,  -25, -152,    0,    0,    0,    0,
 -150,    0,    0,    0, -241,    0, -209,    0, -268, -268,
  -25,    0,    0,  -85, -248,    0,    0,  -25,  -25,  -25,
    0, -124, -209,    0, -132, -248, -248,  -58, -268, -268,
    0, -268, -268, -161,    1,    0,    0,  -25,    0,    0,
    0, -248, -248,    0,    0,  -25,  -25,  -25,  -25,  -25,
  -25, -109,  -95, -190, -161, -161, -161, -161, -161, -161,
    0,    0, -209, -209, -209,    0,  -93,    0,    0,    0,
 -209,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -225,    0,    0, -197,    0,    0,
    0, -121,    0,    0, -183,    0,    0,    0, -253,    0,
    0,    0,  -18,    0,    0, -156,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -185,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -251,    0,  -18,    0,    0,    0,
    0,    0,    0,    0, -158,    0,    0,    0,    0,    0,
    0,    0, -130,    0,    0, -131, -104,    0,    0,    0,
    0,    0,    0,  -98,    0,    0,    0,    0,    0,    0,
    0,  -77,  -50,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -207, -169, -163, -151,  -73,  -46,
    0,    0,  -24,  -24,  -24,    0, -258,    0,    0,    0,
  -24,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  113,    0,  -23,    0,  153,    0,    0,  141,
    0,    0,    0,    0,    0,  135,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -44,  124,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  192,  -60,    0,    0,
};
#define YYTABLESIZE 283
static const short yytable[] = {                         42,
   64,   38,   56,    5,    1,    4,    4,    5,    5,    4,
    5,    5,    4,    5,   61,    4,   78,    5,    5,    4,
    4,   94,   95,   84,   62,   63,   82,   83,    6,   38,
   57,    4,   38,   74,    5,    4,    4,    5,    4,    4,
    5,    4,    4,  104,   11,    4,    4,   23,   13,   89,
   53,  105,  106,  107,  108,  109,  110,   24,   14,    9,
   53,   19,   25,    9,   20,    4,    9,  113,    4,    9,
   21,   10,   38,    9,    9,   10,   40,   25,   10,   41,
   21,   10,   79,   80,   26,   10,   10,   23,   54,  116,
  117,  118,   47,    9,   56,   44,    9,  122,   54,   59,
   59,   59,   47,   47,   56,   10,   55,   52,   10,   59,
   59,   79,   80,   49,   59,   59,   55,   45,   59,   59,
   59,   59,   59,   59,   51,   59,   60,   60,   60,   59,
   25,   47,   59,   21,   47,   32,   60,   60,   58,   68,
   23,   60,   60,   71,   88,   60,   60,   60,   60,   60,
   60,   90,   60,   61,   61,   61,   60,   52,  111,   60,
   33,   33,  112,   61,   61,  119,    8,   73,   61,   61,
   33,   39,   61,   61,   61,   61,   61,   61,   53,   61,
   62,   62,   62,   61,   58,   72,   61,   79,   80,   33,
   62,   62,   33,   87,   58,   62,   62,    0,   81,   62,
   62,   62,   62,   62,   62,    0,   62,   63,   63,   63,
   62,   57,    0,   62,   79,   80,    0,   63,   63,    0,
    0,   57,   63,   63,    0,   91,   63,   63,   63,   63,
   63,   63,    0,   63,   52,   52,   25,   63,    0,   21,
   63,   52,   25,    0,    0,   21,   23,   59,   60,    0,
   76,   77,   23,    0,    0,    0,    0,   61,    0,    0,
    0,    0,    0,   52,    0,    0,   52,   62,   63,   52,
   92,   93,    0,   79,   80,    0,    0,   96,   97,   98,
   99,  100,  101,
};
static const short yycheck[] = {                         23,
   45,  260,  260,  257,  266,  257,  294,  261,  288,  261,
  264,  265,  264,  267,  283,  267,   61,  271,  272,  271,
  272,   82,   83,   68,  293,  294,  275,  276,  270,  288,
  288,  257,  291,   57,  288,  261,  288,  291,  264,  265,
  294,  267,  294,   88,  294,  271,  272,  257,  291,   73,
  258,   96,   97,   98,   99,  100,  101,  267,  265,  257,
  268,  288,  272,  261,  287,  291,  264,  258,  294,  267,
  294,  257,  288,  271,  272,  261,  294,  261,  264,  288,
  264,  267,  273,  274,  294,  271,  272,  271,  258,  113,
  114,  115,  264,  291,  258,  283,  294,  121,  268,  258,
  259,  260,  259,  260,  268,  291,  258,  291,  294,  268,
  269,  273,  274,  271,  273,  274,  268,  283,  277,  278,
  279,  280,  281,  282,  261,  284,  258,  259,  260,  288,
  261,  288,  291,  264,  291,  292,  268,  269,  294,  292,
  271,  273,  274,  294,  269,  277,  278,  279,  280,  281,
  282,  284,  284,  258,  259,  260,  288,  288,  268,  291,
  259,  260,  258,  268,  269,  259,  288,   55,  273,  274,
  269,   19,  277,  278,  279,  280,  281,  282,   38,  284,
  258,  259,  260,  288,  258,   51,  291,  273,  274,  288,
  268,  269,  291,   70,  268,  273,  274,   -1,  284,  277,
  278,  279,  280,  281,  282,   -1,  284,  258,  259,  260,
  288,  258,   -1,  291,  273,  274,   -1,  268,  269,   -1,
   -1,  268,  273,  274,   -1,  284,  277,  278,  279,  280,
  281,  282,   -1,  284,  259,  260,  261,  288,   -1,  264,
  291,  260,  261,   -1,   -1,  264,  271,  273,  274,   -1,
   59,   60,  271,   -1,   -1,   -1,   -1,  283,   -1,   -1,
   -1,   -1,   -1,  288,   -1,   -1,  291,  293,  294,  288,
   79,   80,   -1,  273,  274,   -1,   -1,  277,  278,  279,
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
"$$5 :",
"statement : $$5 for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"$$6 :",
"assignment_statement : IDENT $$6 ASSIGN expression",
"$$7 :",
"$$8 :",
"$$9 :",
"if_statement : IF $$7 condition $$8 THEN $$9 statement else_statement",
"else_statement :",
"$$10 :",
"else_statement : ELSE $$10 statement",
"$$11 :",
"$$12 :",
"$$13 :",
"while_statement : WHILE $$11 condition $$12 DO $$13 statement",
"for_statement : FOR assignment_statement TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$14 :",
"read_statement : READ LPAREN IDENT $$14 RPAREN",
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
#line 1095 "parser.y"
 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
#line 717 "y.tab.c"

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
#line 358 "parser.y"
	{init_fstack();}
break;
case 2:
#line 359 "parser.y"
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
                fprintf(fp,"@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");
                fprintf(fp, "@.str.1 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n");
                fprintf(fp, "declare i32 @__isoc99_scanf(i8*, ...)\n");
                fprintf(fp, "declare i32 @printf(i8*, ...)\n");
                if(global_decl != NULL ) {displayLlvmcodes(global_decl->codes,fp );
                fprintf(fp,"\n");}
                displayLlvmfundecl( declhd ,fp );
                fclose(fp);
        }
break;
case 9:
#line 403 "parser.y"
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
                x->command = Alloca; /* 命令の種類を加算に設定 */
                (x->args).alloca.retval = ftmp; /* 命令の第 2 引数を指定 */
                add_node(x);
                factorpush(ftmp);
                Factor f1tmp;
                f1tmp.type = CONSTANT;
                f1tmp.cal = 0;
                factorpush(f1tmp);
                LLVMcode *ltmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* 加算の引数・結果 */
                ltmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                ltmp->next = NULL; /* 次の命令へのポインタを初期化 */
                ltmp->command = Store; /* 命令の種類を加算に設定 */
                arg1 = factorpop();/*スタックから第2引数をポップ*/
                arg2 = factorpop();/*スタックから第1引数をポップ*/
                (ltmp->args).store.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (ltmp->args).store.arg2 = arg2; /* 命令の第 2 引数を指定 */
                add_node(ltmp);
        }
break;
case 10:
#line 437 "parser.y"
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
                x->command = Alloca; /* 命令の種類を加算に設定 */
                (x->args).alloca.retval = ftmp; /* 命令の第 2 引数を指定 */
                add_node(x);
                factorpush(ftmp);
                Factor f1tmp;
                f1tmp.type = CONSTANT;
                f1tmp.cal = 0;
                factorpush(f1tmp);
                LLVMcode *ltmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* 加算の引数・結果 */
                ltmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                ltmp->next = NULL; /* 次の命令へのポインタを初期化 */
                ltmp->command = Store; /* 命令の種類を加算に設定 */
                arg1 = factorpop();/*スタックから第2引数をポップ*/
                arg2 = factorpop();/*スタックから第1引数をポップ*/
                (ltmp->args).store.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (ltmp->args).store.arg2 = arg2; /* 命令の第 2 引数を指定 */
                add_node(ltmp);
        }
break;
case 13:
#line 480 "parser.y"
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
#line 498 "parser.y"
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
#line 512 "parser.y"
	{Proc_Term++;}
break;
case 17:
#line 512 "parser.y"
	{delete(); Proc_Term--;}
break;
case 21:
#line 523 "parser.y"
	{
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 22:
#line 529 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 23:
#line 541 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = Last_Register;
                add_node(tmp);
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 24:
#line 553 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                printf("%d, %d, %d\n", br_decl->cond, br_decl->coll, br_decl->uncoll);
                br_decl = br_decl->before;

        }
break;
case 25:
#line 567 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = Last_Register;
                add_node(tmp);
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
break;
case 26:
#line 579 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
break;
case 32:
#line 598 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 33:
#line 599 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Store; /* 命令の種類を加算に設定 */
                arg1 = factorpop();/*スタックから第2引数をポップ*/
                arg2 = factorpop();/*スタックから第1引数をポップ*/
                (tmp->args).store.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).store.arg2 = arg2; /* 命令の第 2 引数を指定 */
                add_node(tmp);
        }
break;
case 34:
#line 615 "parser.y"
	{
                if (codetl->command != Label){
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                Last_Register ++;
                }
        }
break;
case 35:
#line 626 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrCond; /* 命令の種類を加算に設定 */
                Factor arg1;
                arg1 = factorpop();
                (tmp->args).brcond.arg1 = arg1;
                (tmp->args).brcond.arg2 = &br_decl->coll;
                (tmp->args).brcond.arg3 = &br_decl->uncoll;
                br_decl->coll = Last_Register;
                add_node(tmp);
        }
break;
case 36:
#line 640 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                Last_Register ++;
        }
break;
case 37:
#line 649 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = Last_Register;
                add_node(tmp);
        }
break;
case 39:
#line 662 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                Last_Register ++;
        }
break;
case 41:
#line 675 "parser.y"
	{
                
                if (codetl->command != Label){
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                }
                br_decl->cond = Last_Register;
                Last_Register ++;
        }
break;
case 42:
#line 688 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrCond; /* 命令の種類を加算に設定 */
                Factor arg1;
                arg1 = factorpop();
                (tmp->args).brcond.arg1 = arg1;
                (tmp->args).brcond.arg2 = &br_decl->coll;
                (tmp->args).brcond.arg3 = &br_decl->uncoll;
                br_decl->coll = Last_Register;
                add_node(tmp);
        }
break;
case 43:
#line 701 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Label; /* 命令の種類を加算に設定 */
                (tmp->args).label.l = Last_Register;
                add_node(tmp);
                Last_Register ++;
        }
break;
case 44:
#line 710 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = br_decl->cond;
                add_node(tmp);
        }
break;
case 47:
#line 729 "parser.y"
	{
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
                lookup(yystack.l_mark[0].ident);
                strcpy((tmp->args).call.funcname, yystack.l_mark[0].ident);
                (tmp->args).call.rettype = vo;
                Factor arg1;
                strcpy(arg1.val, "void");
                (tmp->args).call.arg1 = arg1;
                add_node(tmp);
                }
break;
case 49:
#line 749 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 50:
#line 750 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
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
                add_node(tmp);
        }
break;
case 51:
#line 770 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
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
                add_node(tmp);  
        }
break;
case 53:
#line 794 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                (tmp->args).icmp.type = EQUAL;
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 54:
#line 813 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                (tmp->args).icmp.type = NE;
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 55:
#line 832 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                (tmp->args).icmp.type = SLT;
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 56:
#line 851 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                (tmp->args).icmp.type = SLE;
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 57:
#line 870 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                (tmp->args).icmp.type = SGT;
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 58:
#line 889 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1 = factorpop();/*スタックから第1引数をポップ*/
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                (tmp->args).icmp.type = SGE;
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 61:
#line 913 "parser.y"
	{
                LLVMcode *tmp; /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Sub; /* 命令の種類を加算に設定 */
                arg2 = factorpop();/*スタックから第2引数をポップ*/
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
                retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
                Last_Register ++; /* カウンタをインクリメント */
                (tmp->args).sub.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).sub.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).sub.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 62:
#line 932 "parser.y"
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
                (tmp->args).add.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).add.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).add.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 63:
#line 950 "parser.y"
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
                (tmp->args).sub.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).sub.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).sub.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 65:
#line 972 "parser.y"
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
                (tmp->args).mul.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).mul.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).mul.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 66:
#line 991 "parser.y"
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
                (tmp->args).div.arg1 = arg1; /* 命令の第 1 引数を指定 */
                (tmp->args).div.arg2 = arg2; /* 命令の第 2 引数を指定 */
                (tmp->args).div.retval = retval; /* 結果のレジスタを指定 */
                add_node(tmp);
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
break;
case 67:
#line 1013 "parser.y"
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
case 68:
#line 1029 "parser.y"
	{
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 70:
#line 1039 "parser.y"
	{factorpush(lookup(yystack.l_mark[0].ident));}
break;
case 73:
#line 1049 "parser.y"
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
case 74:
#line 1072 "parser.y"
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
#line 1644 "y.tab.c"
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
