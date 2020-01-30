#include <stdio.h>
#include <stdlib.h>

int main() {
    int *x;
    int y = 10;
    x = &y;
    printf("x:%d y:%d\n", *x, y);
}