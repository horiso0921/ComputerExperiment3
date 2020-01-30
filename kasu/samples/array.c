int a[11], i, s;
int main(){
    i = 1;
    while (i <= 10){
        a[i] = i;
        i ++;
    }
    i = 1;
    while (i <= 10){
        s = a[i] + s;
        i = i + 1;
    }
    return 0;
}