
#include <stdio.h>

int ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    else if ((n == 0) & (m > 0))
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main () {
    int m, n, acker;
    printf("Enter the Ackermann number (m, n):\n");
    scanf("%d", &m);
    scanf("%d", &n);

    acker = ackermann(m, n);
    printf("The value for Ackermann's function for (m, n) = (%d, %d) is %d.", m, n, acker);
}