#include <stdio.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n, k;

        scanf("%d %d", &n, &k);

       long long result = factorial(k + n - 1) / (factorial(n - 1) * factorial(k));

       printf("%lld\n", result);

    return 0;
}
