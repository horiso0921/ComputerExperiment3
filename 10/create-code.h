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
int Calcode();
void Icmpcode();
void Callcode();
void Retcode();
void Sextcode();
void GetElemcode();
int i,f;
LLVMcode *Tmp;
Factor *Stack_tmp;
Factor f_tmp;



void create_llvmcode(LLVMcommand command){
    f = 0;
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
            f = Calcode(command);
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
        case Sext:
            Sextcode();
            break;
        case GetElem:
            GetElemcode();
            break;
        default:
            break;
    }
    if (f){
        return;
    }
    if (command != Global){
        add_llvmnode(tmp);
    } else {
        add_globalnode(tmp);
    }

}

void Arity_Alloca(){
    int r;
    Tmp = decltl->codes;
    Stack_tmp = Stack_tl;
    while (Tmp != NULL){
        (Tmp->args).alloca.retval.cal += decltl->arity ;
        Tmp = Tmp->next;
    }
    while (Stack_tmp->type != PROC_NAME){
        Stack_tmp->cal += decltl->arity ;
        Stack_tmp = Stack_tmp->before;
    }
    Tmp = decltl->codes;
    if (Func_Term) {
        Stack_tmp->ret = decltl->arity + 1;
        Tmp = Tmp->next;
    }
    for (i=0;i<decltl->arity;i++){
        f_tmp.type = LOCAL_VAR;
        f_tmp.cal = i;
        factorpush((Tmp->args).alloca.retval);
        factorpush(f_tmp);
        create_llvmcode(Store);
        Tmp = Tmp->next;
    }
    Last_Register += decltl->arity ;
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

int Calcode(LLVMcommand command){
    Factor arg1,arg2, retval;
    arg2 = factorpop();
    arg1 = factorpop();
    if (arg1.type == CONSTANT && arg2.type == CONSTANT){
        retval.type = CONSTANT;
        switch (command)
        {
        case Add:
            retval.cal = arg1.cal + arg2.cal;
            break;
        case Sub:
            retval.cal = arg1.cal - arg2.cal;
            break;
        case Mul:
            retval.cal = arg1.cal * arg2.cal; 
            break;
        case Div:
            retval.cal = arg1.cal / arg2.cal;
            break;
        default:
            break;
        }
        factorpush( retval );  /* 計算の結果をスタックにプッシュ */
        return 1;
    } else {    
        retval.type = LOCAL_VAR; /* 結果を格納するレジスタは局所 */
        retval.cal = Last_Register; /* 新規のレジスタ番号を取得 */
        Last_Register ++; /* カウンタをインクリメント */
        (tmp->args).add.arg2 = arg2; /* 命令の第 1 引数を指定 */
        (tmp->args).add.arg1 = arg1; /* 命令の第 2 引数を指定 */
        (tmp->args).add.retval = retval; /* 結果のレジスタを指定 */
    }
    factorpush( retval );  /* 計算の結果をスタックにプッシュ */
    return 0;
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

void Sextcode(){
    Factor arg1, retval; /* 型変換の引数・結果 */
    retval.type = LOCAL_VAR;
    retval.cal = Last_Register;
    Last_Register++;
    arg1 = factorpop();/*スタックから第1引数をポップ*/
    (tmp->args).sext.arg1 = arg1; /* 命令の第 1 引数を指定 */
    (tmp->args).sext.retval = retval; /* 命令の第 1 引数を指定 */
    factorpush(retval);
}

void GetElemcode(){
    Factor arg1, arg2, retval; /* 型変換の引数・結果 */
    retval.type = LOCAL_VAR;
    retval.cal = Last_Register;
    Last_Register++;
    arg2 = factorpop();
    arg1 = factorpop();/*スタックから第1引数をポップ*/
    (tmp->args).getelem.arg1 = arg1; /* 命令の第 1 引数を指定 */
    (tmp->args).getelem.arg2 = arg2; /* 命令の第 2 引数を指定 */
    (tmp->args).getelem.retval = retval; /* 結果のレジスタを指定 */
    factorpush(retval);
}