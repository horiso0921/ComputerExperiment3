#include <stdio.h>


int x;
int main(void)
{
    x = 1;
    x = x++ - x--;
    printf("%d",x);
    return 0;
}
