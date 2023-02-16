#include <stdio.h>

#define NMAX 10

int input(int *arr, int *n, int *count);
void shift(int *arr, int n, int count);
void output(int *arr, int n);

int main() {
    int n, c;
    int data[NMAX] = {};
    if (input(data, &n, &c)) {
        printf("n/a");
        return 1;
    }
    if (c != 0) {
        shift(data, n, c);
    }
    output(data, n);
    return 0;
}

int input(int *arr, int *n, int *count) {
    int error = 0;
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX || *n == 0) {
        error = 1;
    }
    for (int *p = arr; p - arr < *n; p++) {
        if (scanf("%d", p) != 1) {
            error = 1;
            break;
        }
    }
    if (scanf("%d", count) != 1) {
        error = 1;
    }
    if (getchar() != '\n') {
        error = 1;
    }
    return error;
}

void shift(int *arr, int n, int count) {
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            int tmp = arr[0];
            for (int i = 1; i < n; i++) {
                arr[i - 1] = arr[i];
            }
            arr[n - 1] = tmp;
        }
    } else {
        count = -count;
        for (int i = 0; i < count; i++) {
            int tmp = arr[n - 1];
            for (int i = n - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = tmp;
        }
    }
}

void output(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - 1]);
}