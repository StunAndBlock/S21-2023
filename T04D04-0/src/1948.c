#include <math.h>
#include <stdio.h>

int largest_prime_divisor(int x);
int is_prime(int x);

int main() {
    int num = 0;
    if (scanf("%d", &num) != 1) {
        printf("n/a");
        return 1;
    }
    printf("%d", largest_prime_divisor(num));
    return 0;
}

int largest_prime_divisor(int x) {
    if (x == 0) return 0;
    if (x < 0) x = -x;
    int del1, del2;
    for (del1 = x; del1 > 1; --del1) {
        for (del2 = 1; del2 < x; ++del2) {
            if (del1 * del2 == x && is_prime(del1)) {
                return del1;
            }
        }
    }
    return 1;
}

int is_prime(int x) {
    for (int del1 = 2; del1 <= pow(x, 0.5); ++del1) {
        for (int del2 = x; del2 >= pow(x, 0.5); --del2) {
            if (del1 * del2 == x) {
                return 0;
            }
        }
    }
    return 1;
}