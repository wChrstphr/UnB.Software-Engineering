#include <stdio.h>

int main()
{
    int x = 256; // 2^8 = 00000000 00000000 00000001 0000000
    char y = 'a';
    int z = 0;

    printf("%d\n", &x);         // saída?
    printf("%ld\n", (long)&z); // 140733520157276
    printf("%ld\n", (long)&x); // 140733520157272
    printf("%ld\n", (long)&y); // 140733520157271

    // desloca dois endere ços de tamanhos de char
    printf("%ld\n", (long)(&y + 2)); // 140733520157273

    return 0;
}
