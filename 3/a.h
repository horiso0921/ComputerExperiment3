
/*記号表の管理+変数・定数の区別用*/
typedef enum {
        GLOBAL_VAR, /*大域変数*/
        LOCAL_VAR,  /*局所変数*/
        PROC_NAME,  /*手続き*/
        CONSTANT    /*定数*/
} Scope;

typedef struct {
        Scope type; /* 変数, 定数, 手続きの区別 */
        char val[256]; /* 変数や手続きの場合の名前 */ 
        int cal; /* 整数の場合はその値, 変数の場合は割り当てたレジスタ番号 */
} Symbol;

Symbol Symbol_Stack[10000];

int Proc_Term = 0;
int Stack_pointer = 0;
int Last_Register = 2;

void lookall(){
        printf("======================\n");
        for(int i;i < Stack_pointer;i++){
                switch (Symbol_Stack[i].type) {
                        case GLOBAL_VAR:
                                printf("== GLOBAL       %s\n", Symbol_Stack[i].val);
                                break;
                        case LOCAL_VAR:
                                printf("== LOCAL    %d   %s\n", Symbol_Stack[i].cal, Symbol_Stack[i].val);
                                break;
                        case PROC_NAME:
                                printf("== PROC         %s\n", Symbol_Stack[i].val);
                                break;
                        case CONSTANT:
                                printf("== CONSTANT %d  %s\n", Symbol_Stack[i].cal, Symbol_Stack[i].val);
                                break;
                }
        }
        
        printf("======================\n");
        return;
}

void insert(char name[256], int flag) {
        printf("insert\n");
        Symbol_Stack[Stack_pointer].type = flag + Proc_Term;
        strcpy(Symbol_Stack[Stack_pointer].val, name);
        if (Symbol_Stack[Stack_pointer].type == LOCAL_VAR) {
                Symbol_Stack[Stack_pointer].cal = Last_Register;
                Last_Register++;
        }
        
        Stack_pointer++;
        lookall();
}

void lookup(char name[256]){
        printf("lookup\n======================\n");
        for(int i = Stack_pointer-1;i >= 0;i--){
                if (*Symbol_Stack[i].val == *name){
                        switch (Symbol_Stack[i].type) {
                                case GLOBAL_VAR:
                                        printf("== GLOBAL       %s\n", Symbol_Stack[i].val);
                                        break;
                                case LOCAL_VAR:
                                        printf("== LOCAL    %d   %s\n", Symbol_Stack[i].cal, Symbol_Stack[i].val);
                                        break;
                                case PROC_NAME:
                                        printf("== PROC         %s\n", Symbol_Stack[i].val);
                                        break;
                                case CONSTANT:
                                        printf("== CONSTANT %d  %s\n", Symbol_Stack[i].cal, Symbol_Stack[i].val);
                                        break;
                        }
                printf("======================\n");
                return;
                }
                
        }
        printf("No Member(This is Error)\n");
}

void delete(){
        printf("delete\n");
        while(1){
                if (Symbol_Stack[Stack_pointer-1].type == LOCAL_VAR && Stack_pointer != 0){
                        Stack_pointer--;
                        Last_Register--;
                } else {
                        break;
                }
                
        }
        lookall();
}