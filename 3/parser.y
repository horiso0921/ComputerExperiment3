%{
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
        : PROGRAM IDENT SEMICOLON outblock PERIOD
        {
                __del__();
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
        | subprog_decl_list SEMICOLON
        ;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        : proc_decl
        ;

proc_decl
        : PROCEDURE proc_name SEMICOLON inblock
        ;

proc_name
        : IDENT { insert($1, 2); }
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
        : IDENT { lookup($1);} ASSIGN expression  
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
        : FOR IDENT{lookup($2);} ASSIGN expression
                TO expression DO statement 
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name 
        : IDENT {lookup($1);}
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement 
        : READ LPAREN IDENT {lookup($3);} RPAREN 
        ;

write_statement 
        : WRITE LPAREN expression RPAREN
        ;

null_statement 
        : /* empty */
        ;

condition 
        : expression EQ expression
        | expression NEQ expression
        | expression LT expression
        | expression LE expression
        | expression GT expression
        | expression GE expression
        ;

expression 
        : term
        | PLUS term
        | MINUS term
        | expression PLUS term
        | expression MINUS term
        ;

term 
        : factor
        | term MULT factor
        | term DIV factor
        ;

factor 
        : var_name
        | NUMBER
        | LPAREN expression RPAREN
        ;

var_name 
        : IDENT {lookup($1);}
        ;

arg_list 
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT { insert($1, 0); }
        | id_list COMMA IDENT { insert($3, 0); }
        ;

%% 

yyerror(char *s)
{
  fprintf(stderr, "%s \nline=%d token=q%s\n", s, yylineno, yytext);
}
