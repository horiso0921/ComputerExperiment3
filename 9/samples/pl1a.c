#include<stdio.h>
int n, temp;
void fact(n){
    if (n <= 1){
        temp = 1;
    } else {
        fact(n-1);
        temp = temp * n;
    }
}

int main(){
    scanf("%d",&n);
    fact(n);
    printf("%d\n",temp);
    return 0;
}