#include <stdio.h>

int main()
{
    int v[2] = {1, 2};
    int m[2][2] = {1, 2, 3, 4};

    int *p;
    p = v;
    p[0] = 5;

    printf("%d %d\n", p[0], p[1]);

    p = m[0]; //( int *)m
    printf("%d %d %d %d\n", p[0], p[1], p[2], p[4]);

    return 0;
}