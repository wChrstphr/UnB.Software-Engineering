#include <stdio.h>
int main()
{
    int v[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }

    // aloca ção sequencial
    // 140730053083440
    // 140730053083440 140730053083444
    // 140730053083448 140730053083452
    printf("%ld %ld\n", (long)(v));
    printf("%ld %ld\n", (long)&v[0][0], (long)&v[0][1]);
    printf("%ld %ld\n", (long)&v[1][0], (long)&v[1][1]);
    printf("%ld %ld\n", (long)v[0][0], (long)v[0][1]);
    printf("%ld %ld\n", (long)v[0][2], (long)v[0][3]);
    printf("%ld %ld\n", (long)v[1][0], (long)v[1][1]);
    printf("%ld %ld\n", (long)v[1][2], (long)v[1][3]);

    return 0;
}
