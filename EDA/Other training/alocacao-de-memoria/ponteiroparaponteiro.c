#include <stdio.h>

int main() {
    int i = 1234;
    int *p;
    int **r;
    int ***q;

    p = &i;
    r = &p;
    q = &r;

    printf ("%d\n", ***q);
    printf ("%d\n", **r);
    printf ("%d\n", *p);
}