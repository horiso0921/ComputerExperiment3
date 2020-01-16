#include <stdio.h>
int n,a[101],b[101];
void init(n){
    int i;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
}

void output(n){
    int i;
    for (i=1;i<=n;i++){
        printf("%d\n",a[i]);
    }
}

void merge(p,n){
    int i,j,k,mid;
    mid = n / 2;
    i = p;
    j = p + mid;
    for (k = p; k<=p+n-1;k++){
        if(j==p+n){
            b[k] = a[i];
            i++;
        }else{
            if (i < p + mid){
                if (a[i] <= a[j]){
                    b[k] = a[i];
                    i++;
                } else {
                    b[k] = a[j];
                    j++;
                }
            } else {
                b[k] = a[j];
                j++;
            }
        }
    }
    for (k=p;k<=p+n-1;k++){
        a[k] = b[k];
    }
}

void msort(p,n){
    int mid;
    if (n > 1){
        mid = n / 2;
        msort(p,mid);
        msort(p+mid,n-mid);
        merge(p,n);
    }
}

int main(){
    scanf("%d",&n);
    if(n<=100){
        init(n);
        msort(1,n);
        output(n);
    }
    return 0;
}