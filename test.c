#include <stdio.h>

int main(void)
{
    int x = 10;
    int *px = &x;
    *px = 50;

    printf("%i\n", x);
}