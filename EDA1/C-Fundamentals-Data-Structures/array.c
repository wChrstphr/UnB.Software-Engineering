#include <stdio.h>

int main()
{
    int v[2] = {3, 7};

    printf("%d %d\n", v[0], v[1]); // 3 7

    // 140730478951952
    printf("%ld\n", (long)v);

    // 140730478951952 140730478951956
    printf("%ld %ld\n", (long)&v[0], (long)&v[1]);

    return 0;
}