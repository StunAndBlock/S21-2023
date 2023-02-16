#include <stdio.h>

unsigned long long fib(unsigned long long n);

int main() {
    int num = 0;
    if (scanf("%d", &num) != 1 || num == 0) {
        printf("n/a");
        return 1;
    }
    printf("%lld", fib(num));
    return 0;
}

unsigned long long fib(unsigned long long n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}