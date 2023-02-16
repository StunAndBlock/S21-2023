#include <stdio.h>
#include <stdlib.h>

int input(int* arr, int n);
void bubble_sort(int* arr, int n);
void output(int* arr, int n);

int main() {
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 1;
    }
    int* data = (int*)malloc(sizeof(int) * n);
    if (input(data, n)) {
        printf("n/a");
        free(data);
        return 1;
    }
    bubble_sort(data, n);
    output(data, n);
    free(data);
    return 0;
}

int input(int* arr, int n) {
    int error = 0;
    for (int* p = arr; p < arr + n; ++p) {
        if (scanf("%d", p) != 1) {
            error = 1;
            break;
        }
    }
    if (getchar() != '\n') {
        error = 1;
    }
    return error;
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void output(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - 1]);
}