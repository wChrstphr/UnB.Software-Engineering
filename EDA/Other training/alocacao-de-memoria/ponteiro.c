#include <stdio.h>

int main (){
    int i = 1234;
    int *p;

    printf("\n%d", i);
    printf("\n%d", &i);

    p = &i;
    printf("\n%d", *p);
    *p = 4222;
    printf("\n%d", *p);
    printf("\n%d", p);


    return 0;
}