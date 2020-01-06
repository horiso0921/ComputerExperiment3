#include <stdio.h>
int n;
int fact(int n){
    int tmp;
    if (n <= 0){
        return 1;
    } else{
        tmp = fact(n-1) * n;
    }
    return tmp;
}
int main(){
    scanf("%d",&n);
    printf("%d\n",fact(n));
}