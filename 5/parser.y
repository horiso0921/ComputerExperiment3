%{
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

%}

%union {
        int num;
        char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS
%left MULT DIV

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER
%token <ident> IDENT

%%

program
        : PROGRAM {init_fstack();}IDENT SEMICOLON outblock PERIOD
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
        ;

outblock
        : var_decl_part subprog_decl_part statement
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
        ;

var_decl_list
        : var_decl_list SEMICOLON var_decl
        | var_decl
        ;

var_decl
        : VAR id_list
        ;

subprog_decl_part
        : /* empty */
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
        | subprog_decl_list SEMICOLON
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
        ;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        : proc_decl
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
        ;

proc_decl
        : PROCEDURE proc_name SEMICOLON inblock
        ;

proc_name
        : IDENT 
        { 
                insert($1, 2);
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , $1);
                tmp->codes = NULL;
                if (declhd == NULL) declhd = tmp;
                if (decltl != NULL) decltl->next = tmp;
                decltl = tmp; 
                codetl = NULL;
        }
        ;

inblock
        : {Proc_Term++;} var_decl_part statement {delete(); Proc_Term--;}
        ;

statement_list
        : statement_list SEMICOLON statement
        | statement
        ;

statement
        : assignment_statement
        | if_statement
        | while_statement
        | for_statement
        | proc_call_statement
        | null_statement
        | block_statement
        | read_statement
        | write_statement
        ;

assignment_statement
        : IDENT {factorpush(lookup($1));} ASSIGN expression 
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
        ;

if_statement 
        : IF condition THEN statement else_statement
        ;

else_statement 
        : /* empty */
        | ELSE statement
        ;

while_statement 
        : WHILE condition DO statement
        ;

for_statement 
        : FOR IDENT {lookup($2);} ASSIGN expression
                TO expression DO statement 
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name 
        : IDENT {
                LLVMcode *tmp;
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = Call; /* 命令の種類を加算に設定 */
                lookup($1);
                strcpy((tmp->args).call.funcname, $1);
                (tmp->args).call.rettype = vo;
                Factor arg1;
                strcpy(arg1.val, "void");
                (tmp->args).call.arg1 = arg1;
                add_node(tmp);
                }
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement 
        : READ LPAREN IDENT {factorpush(lookup($3));} RPAREN 
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
        ;

write_statement 
        : WRITE LPAREN expression RPAREN
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
        ;

null_statement 
        : /* empty */
        ;

condition 
        : expression EQ expression
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
        | expression NEQ expression
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
        | expression LT expression
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
        | expression LE expression
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
        | expression GT expression
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
        | expression GE expression
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
        ;

expression 
        : term
        | PLUS term
        | MINUS term
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
        | expression PLUS term
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
        | expression MINUS term
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
        ;

term 
        : factor
        | term MULT factor
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
        ;
        | term DIV factor
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
        ;
        ;

factor 
        : var_name
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
        | NUMBER 
        {
                Factor tmp;
                tmp.type=CONSTANT;
                tmp.cal=$1;
                factorpush(tmp);
        }
        | LPAREN expression RPAREN
        ;

var_name 
        : IDENT {factorpush(lookup($1));}
        ;

arg_list 
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT 
        { 
                Factor tmp;
                tmp = insert($1, 0); 
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
        | id_list COMMA IDENT 
        { 
                Factor tmp;
                tmp = insert($3, 0); 
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
        ;

%% 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
