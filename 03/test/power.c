#include <stdio.h>

int power(int a, int n) {
    if (n < 0) return 1 / power(a, -n);
    else if (n == 0) return 1;
    else return a * power(a, n - 1);
}

int main() {
    printf("3^2 = %.2f\n", power(3, 2));
}