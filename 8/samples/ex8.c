int a[10], i, s;
int main(){
    i = 1;
    while (i <= 10){
        a[i] = i;
        i ++;
    }
    i = 1;
    while (i <= 10){
        s += a[i];
        i ++ ;
    }
    return 0;
}