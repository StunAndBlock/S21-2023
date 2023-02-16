#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
void squaring(int *a, int n);
double variance(int *a, int n);
int check(int *a, int n, double mean, double variance);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) {
        printf("n/a");
        return 1;
    }
    double mean_v = mean(data, n);
    double variance_v = variance(data, n);
    printf("%d", check(data, n, mean_v, variance_v));
    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n < 1) {
        return -1;
    }
    for (int *p = a; p - a < *n - 1; p++) {
        if (scanf("%d", p) != 1) {
            return -1;
        }
    }
    if (scanf("%d", &(a[*n - 1])) == 1) {
        if (getchar() != '\n') {
            return -1;
        }
    }
    return 0;
}

double mean(int *a, int n) {
    double mean = 0.0;
    for (int i = 0; i < n; i++) {
        mean += a[i];
    }
    return mean / n;
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}

double variance(int *a, int n) {
    int b[NMAX];
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    squaring(b, n);
    return mean(b, n) - mean(a, n) * mean(a, n);
}

int check(int *a, int n, double mean, double variance) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean && a[i] <= mean + 3 * variance && a[i] != 0) {
            return a[i];
        }
    }
    return 0;
}