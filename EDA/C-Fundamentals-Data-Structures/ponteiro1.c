#include <stdio.h>

int main()
{
    int x = 256;  // 2^8 = 00000000 00000000 00000001 0000000
    char y = 'a'; // 97 = 1100001
    int z = 0;    // 0 = 00000000 00000000 00000000 0000000

    printf("%d\n", x);         // saída?
    printf("%ld\n", (long)&z); // 140733520157276
    printf("%ld\n", (long)&x); // 140733520157272
    printf("%ld\n", (long)&y); // 140733520157271

    // memó ria
    // 00000000 00000000 00000000 0000000 -> ..76
    // 00000000 00000000 00000001 0000000 -> ..72
    // 1100001 -> ..71

    // desloca dois endere ços de tamanhos de char
    int *p = (int *)(&y);
    printf("%ld\n", (long)p); // 140733520157273

    printf("%d\n", *p); // saída?

    return 0;
}