#include <stdio.h>
int n, sum;
void result(n){
    sum += n;
    return ;
}

void result(){
    printf("%d",sum);
    return ;
}

int main(){
    n = 10;
    sum = 0;
    while ( n > 0)
    {
        result(n);
        n --;
    }
    result();
    return 0;
}