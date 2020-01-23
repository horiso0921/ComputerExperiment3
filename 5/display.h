extern FILE *fp;

void displayFactor(Factor factor) {
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
}


void displayCmptype( Cmptype cmptype) {
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

void displayLlvmcodes( LLVMcode *code){
        if( code == NULL ) return;
        if( code->command  != Global && code->command != Label)fprintf(fp,"  ");
        switch( code->command ){
                case Alloca:
                        displayFactor( (code->args).alloca.retval);
                        fprintf(fp," = alloca i32, align 4\n");
                        break;
                case Global:
                        displayFactor( (code->args).global.retval);
                        fprintf(fp," = common global i32 0, align 4\n");
                        break;
                case Store:
                        fprintf(fp,"store i32 ");
                        displayFactor( (code->args).store.arg1);
                        fprintf(fp,", i32* ");
                        displayFactor( (code->args).store.arg2);
                        fprintf(fp,", align 4\n");
                        break;
                case Load:
                        displayFactor( (code->args).load.retval);
                        fprintf(fp," = load i32, i32* ");
                        displayFactor( (code->args).load.arg1 );
                        fprintf(fp,", align 4\n");
                        break;
                case BrUncond:
                        fprintf(fp, "br label %%%d\n\n",*(code->args).bruncond.arg1);
                        break;
                case BrCond:
                        fprintf(fp, "br i1 ");
                        displayFactor((code->args).brcond.arg1);
                        fprintf(fp, ", label %%%d, label %%%d\n\n", *(code->args).brcond.arg2, *(code->args).brcond.arg3);
                        break;
                case Label:
                        fprintf(fp, "%d:\n",(code->args).label.l);
                        break;
                case Add:
                        displayFactor( (code->args).calc.retval );
                        fprintf(fp," = add nsw i32 ");
                        displayFactor( (code->args).calc.arg1);
                        fprintf(fp,", ");
                        displayFactor( (code->args).calc.arg2);
                        fprintf(fp,"\n");
                        break;
                case Sub:
                        displayFactor( (code->args).calc.retval);
                        fprintf(fp," = sub nsw i32 ");
                        displayFactor( (code->args).calc.arg1);
                        fprintf(fp,", ");
                        displayFactor( (code->args).calc.arg2);
                        fprintf(fp,"\n");
                        break;
                case Mul:
                        displayFactor( (code->args).calc.retval);
                        fprintf(fp," = mul nsw i32 ");
                        displayFactor( (code->args).calc.arg1);
                        fprintf(fp,", ");
                        displayFactor( (code->args).calc.arg2);
                        fprintf(fp,"\n");
                        break;
                case Div:
                        displayFactor( (code->args).calc.retval);
                        fprintf(fp," = sdiv i32 ");
                        displayFactor( (code->args).calc.arg1);
                        fprintf(fp,", ");
                        displayFactor( (code->args).calc.arg2);
                        fprintf(fp,"\n");
                        break;
                case Call:
                        if  (!strcmp((code->args).call.funcname, "write")){
                                displayFactor( (code->args).call.retval);
                                fprintf(fp," = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 ");
                                displayFactor( (code->args).call.arg1);
                        } else if (!strcmp((code->args).call.funcname, "read")){
                                displayFactor( (code->args).call.retval);
                                fprintf(fp," = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* ");
                                displayFactor( (code->args).call.arg1);
                        } else{
                                if ((code->args).call.rettype == I32){
                                        displayFactor( (code->args).call.retval);
                                        fprintf(fp," = call i32 @%s", (code->args).call.funcname);
                                } else {
                                        fprintf(fp,"call void @%s", (code->args).call.funcname);
                                }
                                if (!strcmp((code->args).call.arg1.val, "void")){
                                        fprintf(fp,"(");
                                } else {
                                        fprintf(fp,"( i32");
                                        displayFactor( (code->args).call.arg1);
                                }
                        }
                        fprintf(fp,")\n");
                        break;
                case Ret:
                        if (strcmp((code->args).ret.arg1.val, "void")) {
                                fprintf(fp,"ret i32 "); 
                                displayFactor( (code->args).ret.arg1);
                        } else {
                                fprintf(fp,"ret void"); 
                        }
                        fprintf(fp,"\n");
                        break;
                case Icmp:
                        displayFactor((code->args).icmp.retval);
                        fprintf(fp," = icmp ");
                        displayCmptype((code->args).icmp.type);
                        fprintf(fp," i32 ");
                        displayFactor((code->args).icmp.arg1);
                        fprintf(fp,", ");
                        displayFactor((code->args).icmp.arg2);
                        fprintf(fp,"\n");
                        break;
                default:
                        fprintf(fp,"This is error\n");
                        break;
        }
        displayLlvmcodes( code->next);
}

void displayLlvmfundecl( Fundecl *decl ){
        if( decl == NULL ) return;
        if (strcmp(decl->fname, "main")){
                fprintf(fp, "define void @%s() {\n", decl->fname );
        } else {
                fprintf(fp, "define i32 @%s() {\n", decl->fname );
        }
        displayLlvmcodes( decl->codes);
        fprintf(fp,"}\n");
        if( decl->next != NULL ) {
                fprintf(fp,"\n");
                displayLlvmfundecl(decl->next);
        }
        return;
}