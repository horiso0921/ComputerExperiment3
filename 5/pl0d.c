#include <stdio.h>
int n,tmp;
void fact(){
    int m;
    if (n <= 1){
        tmp = 1;
    }else{
        m = n;
        n = n - 1;
        fact();
        tmp = tmp*m;
    }
}

int main(){
    scanf("%d",&n);
    fact();
    printf("%d",tmp);
    return 0;
}