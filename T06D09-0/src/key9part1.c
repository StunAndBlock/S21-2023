#include <stdio.h>

#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int n = 0;
    int data[NMAX] = {};
    input(data, &n);
    if (n == 0) {
        printf("n/a");
        return 1;
    }
    int sum = sum_numbers(data, n);
    if (sum == -1) {
        printf("n/a");
        return 1;
    }
    printf("%d", sum);
    if (sum != 0) {
        int arr[NMAX] = {};
        int count = find_numbers(data, n, sum, arr);
        if (count != 0) {
            output(arr, count);
        }
    }
    return 0;
}

int sum_numbers(int *buffer, int length) {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
            count++;
        }
    }
    if (count == 0) {
        sum = -1;
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if ((buffer[i]) == 0) {
            continue;
        }
        if (number % buffer[i] == 0) {
            numbers[j] = buffer[i];
            j++;
        }
    }
    return j;
}

void input(int *arr, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n > NMAX) {
        *n = 0;
        return;
    }
    for (int *p = arr; p - arr < *n - 1; p++) {
        if (scanf("%d", p) != 1) {
            *n = 0;
            return;
        }
    }
    if (scanf("%d%c", &(arr[*n - 1]), &c) != 2 || c != '\n') {
        *n = 0;
    }
}

void output(int *arr, int n) {
    putchar('\n');
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - 1]);
}