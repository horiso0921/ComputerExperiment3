#include <stdio.h>
int n, sum;
void result(n){
    sum += n;
    return 0;
}

void result(){
    printf("%d",sum);
    return 0;
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