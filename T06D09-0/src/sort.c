#include <stdio.h>

#define SIZE 10

int input(int* arr);
void bubble_sort(int* arr);
void output(int* arr);

int main() {
    int data[SIZE];
    if (input(data)) {
        printf("n/a");
        return 1;
    }
    bubble_sort(data);
    output(data);
    return 0;
}

int input(int* arr) {
    int error = 0;
    for (int* p = arr; p < arr + SIZE; ++p) {
        if (scanf("%d", p) != 1) {
            error = 1;
        }
    }
    if (getchar() != '\n') {
        error = 1;
    }
    return error;
}

void bubble_sort(int* arr) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void output(int* arr) {
    for (int i = 0; i < SIZE - 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[SIZE - 1]);
}