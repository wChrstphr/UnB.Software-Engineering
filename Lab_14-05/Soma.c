#include <stdio.h>

int recursiveSum(int n, int m){
    if ((n == 0) && (m == 0))
        return 0;
    else 
        return (n % 10) + (m % 10) + recursiveSum(n / 10, m / 10);
}

int main (){
    int n, m, sum;
    printf("Input (m, n) for the sum:\n");
    scanf("%d", &n);
    scanf("%d", &m);

    /*Testing
    a = m%10;
    printf("Value of the rest of m %% 10 is = %d", a);
    */

    sum = recursiveSum(m, n);
    printf("The sum of the algarisms of %d and %d is equal to %d", m, n, sum);
}

// Casos
// Sum(11, 10) = (1 + 0) + (1 + 1) = 3....
// Sum (0, 0) = 0
// Sum (1, 0) = 1