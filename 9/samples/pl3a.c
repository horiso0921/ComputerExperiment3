#include <stdio.h>
int i,j,n,a[101];
void initialize(n){
    int i;
    for (i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
}

void swap(j){
    int tmp;
    tmp = a[j];
    a[j] = a[j+1];
    a[j+1] = tmp;
}

int main(){
    scanf("%d",&n);
    if(n<=100){
        initialize(n);
        i = n;
        while (1 <= i){
            j = 1;
            while (j < i){
                if (a[j] > a[j+1]){
                    swap(j);
                }
                j ++;
            }
            printf("%d\n",a[i]);
            i --;
        }
    }
    return 0;
}