#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
void squaring(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) {
        printf("n/a");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

void output(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
}

int max(int *a, int n) {
    int current_max = -2147483647 - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > current_max) {
            current_max = a[i];
        }
    }
    return current_max;
}

int min(int *a, int n) {
    int current_min = 2147483647;
    for (int i = 0; i < n; i++) {
        if (a[i] < current_min) {
            current_min = a[i];
        }
    }
    return current_min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}