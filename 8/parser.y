%{
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
%type <num> variable

%%

program
        : PROGRAM {init_fstack();} IDENT SEMICOLON outblock PERIOD
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
        ;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        :  proc_decl
        {
                delete(); 
                Proc_Term--;
                Factor retval;
                strcpy(retval.val,"void");
                factorpush(retval);
                create_llvmcode(Ret);
        }
        | func_decl
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
        ;

proc_decl
        : PROCEDURE proc_name SEMICOLON inblock
        | PROCEDURE proc_name LPAREN {arity_decl=1;} id_list {arity_decl=0;} RPAREN SEMICOLON inblock
        ;

proc_name
        : IDENT 
        { 
                insert($1, 2);
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , $1);
                tmp->codes = NULL;
                tmp->arity = 0;
                tmp->rettype = vo;
                if (declhd == NULL) declhd = tmp;
                if (decltl != NULL) decltl->next = tmp;
                decltl = tmp; 
                codetl = NULL;
                Proc_Term++;
        }
        ;

func_decl
        : FUNCTION func_name SEMICOLON inblock
        | FUNCTION func_name LPAREN {arity_decl=1;} id_list {arity_decl=0;} RPAREN SEMICOLON inblock

func_name
        : IDENT
        {
                insert($1, 2);
                Fundecl *tmp;
                tmp = (Fundecl *)malloc(sizeof(Fundecl));
                strcpy(tmp->fname , $1);
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
        ;
inblock
        :  var_decl_part {Arity_Alloca();} statement 
        ;


statement_list
        : statement_list SEMICOLON statement
        | statement
        ;

statement
        : assignment_statement
        |
        {
                Brdecl *br_tmp;
                br_tmp = (Brdecl *)malloc(sizeof(Brdecl));
                add_brnode(br_tmp);
        }
        if_statement
        {
                create_llvmcode(Label);
                br_decl->end = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
        | 
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
        while_statement
        {
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;

        }
        |
        for_statement
        {
                create_llvmcode(Label);
                br_decl->uncoll = Last_Register;
                Last_Register ++;
                br_decl = br_decl->before;
        }
        | proc_call_statement
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
                (tmp->args).call.arity = i;
                (tmp->args).call.proc = arg;
                (tmp->args).call.rettype = vo;
                add_llvmnode(tmp);
        }
        | null_statement
        | block_statement
        | read_statement
        | write_statement
        ;

assignment_statement
        : variable 
        {
                Factor f_tmp;
                f_tmp = factorpop();
                if(f_tmp.type == PROC_NAME){
                        f_tmp.type = LOCAL_VAR;
                        f_tmp.cal = f_tmp.ret;
                }
                factorpush(f_tmp);
        }
                ASSIGN expression 
        {
                create_llvmcode(Store);
        }
        ;

variable
        : IDENT
        {
                Factor f_tmp;
                f_tmp = lookup($1);
                factorpush(f_tmp);
                $$ = f_tmp.off;
        }
        | indexed_variable RBRACKET
        {
                create_llvmcode(GetElem);
        }
        ;


indexed_variable
        : variable LBRACKET expression 
        {
                Factor f_tmp;
                f_tmp.type = CONSTANT;
                f_tmp.cal = $1;
                factorpush(f_tmp);
                create_llvmcode(Sub);
                create_llvmcode(Sext);
        }
        ;


if_statement 
        : IF condition 
        {
                create_llvmcode(BrCond);
        }
                THEN 
        {
                create_llvmcode(Label);
                Last_Register ++;
        }
                statement 
        {
                br_decl->uncoll = Last_Register;
        }
                else_statement
        {
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
        }
        ;

else_statement 
        : /* empty */
        | ELSE 
        {
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->end;
                add_llvmnode(tmp);
                create_llvmcode(Label);
                Last_Register ++;
        } statement
        ;

while_statement 
        : WHILE 
        {
                create_llvmcode(Label);
                br_decl->cond = Last_Register;
                Last_Register ++;
        } condition 
        {
                create_llvmcode(BrCond);
        } DO 
        {
                create_llvmcode(Label);
                Last_Register ++;
        } statement
        {
                
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL; /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond; 
                (tmp->args).bruncond.arg1 = &br_decl->cond;
                add_llvmnode(tmp);
        }
        ;

for_statement 
        : FOR IDENT 
        {
                factorpush(lookup($2));
        } 
                ASSIGN expression
        {
                create_llvmcode(Store);
        }
                TO 
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
                factorpush(lookup($2));
                create_llvmcode(Load);
        }
                expression 
        {
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
                DO 
        {
                create_llvmcode(BrCond);
                create_llvmcode(Label);
                Last_Register ++;
        }
                statement 
        {
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
                tmp->command = BrUncond;
                tmp->next = NULL;
                (tmp->args).bruncond.arg1 = &br_decl->inc;
                add_llvmnode(tmp);
                create_llvmcode(Label);
                br_decl->inc = Last_Register;
                Last_Register ++;
                factorpush(lookup($2));
                factorpush(lookup($2));
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
        ;

proc_call_statement
        : proc_call_name
        | proc_call_name LPAREN arg_list RPAREN
        ;

proc_call_name 
        : IDENT {factorpush(lookup($1));}
        ;


block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN variable RPAREN 
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
        ;

write_statement 
        : WRITE LPAREN expression RPAREN
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
        ;

null_statement 
        : /* empty */
        ;

condition 
        : expression EQ expression
        {
                icmptype = EQUAL;
                create_llvmcode(Icmp);
        }
        | expression NEQ expression
        {
                icmptype = NE;
                create_llvmcode(Icmp);
        }
        | expression LT expression
        {
                icmptype = SLT;
                create_llvmcode(Icmp);
        }
        | expression LE expression
        {
                icmptype = SLE;
                create_llvmcode(Icmp);
        }
        | expression GT expression
        {
                icmptype = SGT;
                create_llvmcode(Icmp);
        }
        | expression GE expression
        {
                icmptype = SGE;
                create_llvmcode(Icmp);
        }
        ;

expression 
        : term
        | PLUS term
        | MINUS 
        {
                Factor arg1;
                arg1.type = CONSTANT;/*第1引数*/
                arg1.cal = 0;
                factorpush(arg1);
        }
                term
        {
                create_llvmcode(Sub);
        }
        | expression PLUS term
        {
                create_llvmcode(Add);
        }
        | expression MINUS term
        {
                create_llvmcode(Sub);
        }
        ;

term 
        : factor
        | term MULT factor
        {
                create_llvmcode(Mul);
        }
        ;
        | term DIV factor
        {
                create_llvmcode(Div);
        }
        ;

factor 
        : variable
        {
                create_llvmcode(Load);
        }
        | NUMBER 
        {
                Factor tmp;
                tmp.type=CONSTANT;
                
                tmp.cal=$1;
                factorpush(tmp);
        }
        | LPAREN expression RPAREN
        | func_call
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
        ;

func_call
        : func_call_name LPAREN RPAREN
        | func_call_name LPAREN arg_list RPAREN
        ;

func_call_name 
        : IDENT {factorpush(lookup($1));}
        ;


arg_list 
        : expression
        | arg_list COMMA expression
        ;

id_list
        : var_id
        | id_list COMMA var_id
        ;

var_id
        : id_var
        | id_array
        ;

id_var
        : IDENT
        { 
                if(arity_decl==1)decltl->arity++;
                factorpush(insert($1, 0)); 
                switch(Proc_Term){
                        case GLOBAL_VAR:
                                create_llvmcode(Global);
                                break;
                        case LOCAL_VAR:
                                create_llvmcode(Alloca);
                                break;
                }
        }
        ;

id_array
        : IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET
        { 
                if(arity_decl==1)decltl->arity++;
                Factor f_tmp;
                f_tmp = insert($1, 0);
                f_tmp.off = $3;
                f_tmp.fin = $5;
                Stack_tl->fin = $5;
                Stack_tl->off = $3;
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
        ; 

%% 

void yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=%s\n", s, yylineno, yytext);
}
