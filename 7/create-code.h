extern LLVMcode *tmp;
extern void add_llvmnode();
extern Cmptype icmptype;
extern int Last_Register;
extern int arity_decl;
extern unsigned int arity;
extern Fundecl *decltl;
extern Factor *Stack_tl;
extern int Func_Term;
extern Factor lookup();
void Allocacode();
void Globalcode();
void Storecode();
void Loadcode();
void BrUncondcode();
void BrCondcode();
void Labelcode();
void Calcode();
void Icmpcode();
void Callcode();
void Retcode();
int i;
LLVMcode *Tmp;
Factor *Stack_tmp;
Factor f_tmp;



void create_llvmcode(LLVMcommand command){
    tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
    tmp->command = command;
    tmp->next = NULL;
    switch(command){
        case Alloca:   /* alloca */
            Allocacode();
            break;
        case Global:   /* global */
            Globalcode();
            break;
        case Store:    /* store  */
            Storecode();
            break;
        case Load:     /* load   */
            Loadcode();
            break;
        case BrUncond: /* br     */
            BrUncondcode();
            break;
        case BrCond:   /* brc    */
            BrCondcode();
            break;
        case Label:    /* label  */
            Labelcode();
            break;
        case Add:     /* add    */
        case Sub:      /* sub    */
        case Mul:      /* mul    */
        case Div:      /* div    */
            Calcode();
            break;
        case Icmp:     /* icmp   */
            Icmpcode();
            break;
        case Call:      /* call   */
            Callcode();
            break;
        case Ret:       /* ret   */
            Retcode();
            break;
        default:
            break;
    }
    if (command != Global){
        add_llvmnode(tmp);
    } else {
        add_globalnode(tmp);
    }

}

void Arity_Alloca(){
    Tmp = decltl->codes;
    Stack_tmp = Stack_tl;
    while (Tmp != NULL){
        (Tmp->args).alloca.retval.cal += decltl->arity;
        Stack_tmp->cal += decltl->arity;
        Tmp = Tmp->next;
        Stack_tmp = Stack_tmp->before;
    }
    Tmp = decltl->codes;
    if (Func_Term) {
        Tmp = Tmp->next;
        Stack_tmp->ret = decltl->arity + 1;
    }
    for (i=0;i<decltl->arity;i++){
        f_tmp.type = LOCAL_VAR;
        f_tmp.cal = i;
        factorpush((Tmp->args).alloca.retval);
        factorpush(f_tmp);
        create_llvmcode(Store);
        Tmp = Tmp->next;
    }
    Last_Register += decltl->arity;
    Factor *fact;
    fact = Stack_tl;
    while (strcmp(fact->val, decltl->fname)){
        fact = fact->before;
    }
    fact->cal = decltl->arity;
}


void Allocacode(){
    (tmp->args).alloca.retval = factorpop();
}

void Globalcode(){
    (tmp->args).global.retval = factorpop(); /* 命令の第 2 引数を指定 */
}

void Storecode(){
    (tmp->args).store.arg1 = factorpop(); /* 命令の第 1 引数を指定 */
    (tmp->args).store.arg2 = factorpop(); /* 命令の第 2 引数を指定 */
}

void Loadcode(){
    Factor retval;
    retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
    retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
    Last_Register++;
    (tmp->args).load.arg1 = factorpop(); /* 命令の第 1 引数を指定 */
    (tmp->args).load.retval = retval;
    factorpush(retval);
}

void BrUncondcode(){
    int *x;
    *x = Last_Register;
    (tmp->args).bruncond.arg1 = x;
}

void BrCondcode(){
    (tmp->args).brcond.arg1 = factorpop();
    (tmp->args).brcond.arg2 = &br_decl->coll;
    (tmp->args).brcond.arg3 = &br_decl->uncoll;
    br_decl->coll = Last_Register;
}

void Labelcode(){
    (tmp->args).label.l = Last_Register;
}

void Calcode(){
    Factor retval;
    retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
    retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
    Last_Register ++; /* カウンタをインクリメント */
    (tmp->args).add.arg2 = factorpop(); /* 命令の第 1 引数を指定 */
    (tmp->args).add.arg1 = factorpop(); /* 命令の第 2 引数を指定 */
    (tmp->args).add.retval = retval; /* 結果のレジスタを指定 */
    factorpush( retval );  /* 計算の結果をスタックにプッシュ */
}

void Icmpcode(){
    Factor arg1, arg2, retval; /* 加算の引数・結果 */
    retval.type = LOCAL_VAR;
    retval.cal = Last_Register;
    Last_Register++;
    arg2 = factorpop();/*スタックから第2引数をポップ*/
    arg1 = factorpop();/*スタックから第1引数をポップ*/
    (tmp->args).icmp.arg1 = arg1; /* 命令の第 1 引数を指定 */
    (tmp->args).icmp.arg2 = arg2; /* 命令の第 2 引数を指定 */
    (tmp->args).icmp.retval = retval; /* 命令の第 1 引数を指定 */
    (tmp->args).icmp.type = icmptype;
    factorpush(retval);
}

void Callcode(){
    
}
void Retcode(){
    (tmp->args).ret.arg1 = factorpop();
}