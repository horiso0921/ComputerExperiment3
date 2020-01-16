#include <stdio.h>
int sum,n;
void proc2();
void proc1(){
    sum += n;
    proc2();
}
void proc2(){
    n --;
    if (n > 0){
        proc1();
    } else {
        printf("%d",sum);
    }
}

int main(){
    sum = 0;
    scanf("%d",&n);
    proc1();
}