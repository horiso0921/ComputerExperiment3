#include <stdio.h>
int m,n;
int power(m,n){
    if (n<=0){
        return 1;
    } else {
        return power(m,n-1)*m;
    }
}
int main(){
    scanf("%d",&m);
    scanf("%d",&n);
    printf("%d",power(m,n));
    return 0;
}