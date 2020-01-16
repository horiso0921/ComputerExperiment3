
/* 記号表の管理 + 変数・定数の区別用 */
typedef enum { 
  GLOBAL_VAR, /* 大域変数 */
  LOCAL_VAR,  /* 局所変数 */
  PROC_NAME,  /* 手続き   */
  CONSTANT,   /* 定数     */
} Scope;

/* LLVM命令名の定義 */
typedef enum { 
  Alloca,   /* alloca */
  Global,   /* global */
  Store,    /* store  */
  Load,     /* load   */
  BrUncond, /* br     */
  BrCond,   /* brc    */
  Label,    /* label  */
  Add,      /* add    */
  Sub,      /* sub    */
  Mul,      /* mul    */
  Div,      /* div    */
  Icmp,     /* icmp   */
  Call,      /* call   */
  Ret,       /* ret    */
  Sext,      /* sext   */
  GetElem      /* getelem  */
} LLVMcommand;

/* 比較演算子の種類 */
typedef enum { 
  EQUAL, /* eq （==）*/
  NE,    /* ne （!=）*/
  SGT,   /* sgt （>，符号付き） */
  SGE,   /* sge （>=，符号付き）*/
  SLT,   /* slt （<，符号付き） */
  SLE    /* sle （<=，符号付き）*/
} Cmptype;

typedef struct factor{
  Scope type; /* 変数, 手続きの区別 */
  char val[MAXLENGTH+1]; /* 変数や手続きの場合の名前 */ 
  int cal; /* 変数の場合割り当てたレジスタ番号 */
  int ret; /* 関数の場合返り値に割り当てたレジスタ番号 */
  int range; /* 配列の場合その配列の確保したindexの最大値を保持する*/
  struct factor *before;
  struct factor *next;
} Factor;

/* 変数もしくは定数のためのスタック */
typedef struct {
  Factor element[100];  /* スタック（最大要素数は100まで） */
  unsigned int top;     /* スタックのトップの位置         */
} Factorstack;

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */
Factorstack global_fstack;

typedef enum {
  I32,
  vo
} rtype;


typedef struct llvmcode {
  LLVMcommand command; /* 命令名 */
  union { /* 命令の引数 */
    struct { /* alloca */
      Factor retval;
    } alloca;
    struct { /* global */
      Factor retval;
    } global;
    struct { /* store  */
      Factor arg1;  Factor arg2;
    } store;
    struct { /* load   */
      Factor arg1;  Factor retval;
    } load;
    struct { /* br     */
      int *arg1;
    } bruncond;
    struct { /* brc    */
      Factor arg1;  int *arg2;  int *arg3;
    } brcond;
    struct { /* label  */
      int l;
    } label;
    struct { /* add    */
      Factor arg1;  Factor arg2;  Factor retval;
    } add;
    struct { /* sub    */
      Factor arg1;  Factor arg2;  Factor retval;
    } sub;
    struct { /* mul    */
      Factor arg1;  Factor arg2;  Factor retval;
    } mul;
    struct { /* div    */
      Factor arg1;  Factor arg2;  Factor retval;
    } div;
    struct { /* icmp   */
      Cmptype type;  Factor arg1;  Factor arg2;  Factor retval;
    } icmp;
    struct{ /* call */
      rtype rettype; Factor proc; Factor args[10]; Factor retval;  int arity;
    } call;
    struct { /* ret    */
      Factor arg1;
    } ret;
    struct { /* sext    */
      Factor arg1; Factor retval;
    } sext;
    struct { /* getelem    */
      Factor arg1; Factor arg2; Factor retval;
    } getelem;
  } args;
  /* 次の命令へのポインタ */
  struct llvmcode *next;
} LLVMcode;

LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */
LLVMcode *global_codehd = NULL;
LLVMcode *global_codetl = NULL;

void init_fstack(){ /* fstackの初期化 */
  fstack.top = 0;
  return;
}

Factor factorpop(){
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void factorpush(Factor x) {
  fstack.top ++;
  fstack.element[fstack.top] = x;
  return;
}

/* LLVMの関数定義 */
typedef struct fundecl {
  char fname[256];      /* 関数名                      */
  rtype rettype;        /* 関数か手続きかの別           */
  unsigned int arity;   /* 引数個数                    */ 
  Factor args[10];      /* 引数名                      */
  LLVMcode *codes;      /* 命令列の線形リストへのポインタ */
  struct fundecl *next; /* 次の関数定義へのポインタ      */
} Fundecl;
 
/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
Fundecl *declhd = NULL;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
Fundecl *decltl = NULL;
Fundecl *global_decl = NULL;

/* 分岐命令のラベル番号の定義 */
typedef struct brdecl{
  int cond; int coll; int uncoll; int inc; int eluncoll;
  struct brdecl *next;
  struct brdecl *before;
} Brdecl;

Brdecl *br_decl = NULL;


