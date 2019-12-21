#include <stdio.h>
int n,x,i;
void prime(){
    int m;
    m = x / 2;
    while (x != (x / m)*m){
        m --;
    }
    if (m==1){
        printf("%d",x);
    }
}

int main(){
    scanf("%d",&n);
    for (i=2;i<=n;i++){
        x = i;
        prime();
    }
    return 0;
}