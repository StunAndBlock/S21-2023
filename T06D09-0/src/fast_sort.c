#include <stdio.h>

#define SIZE 10

int input(int *arr);
void copy(int *arr, int *res);
void quicksort(int *arr, int first, int last);
void merge(int *arr, int l, int m, int r);
void merge_sort(int *arr, int l, int r);
void output(int *res1, int *res2);

int main() {
    int data[SIZE] = {};
    if (input(data)) {
        printf("n/a");
        return 1;
    }
    int res1[SIZE] = {};
    copy(data, res1);
    int res2[SIZE] = {};
    copy(data, res2);
    quicksort(res1, 0, SIZE - 1);
    merge_sort(res2, 0, SIZE - 1);
    output(res1, res2);
    return 0;
}

int input(int *arr) {
    int error = 0;
    int count = 0;
    for (int *p = arr; p < arr + SIZE; ++p) {
        if (scanf("%d", p) != 1) {
            error = 1;
        }
        count++;
    }
    if (getchar() != '\n' || count != SIZE) {
        error = 1;
    }
    return error;
}

void copy(int *arr, int *res) {
    for (int i = 0; i < SIZE; i++) {
        res[i] = arr[i];
    }
}

void output(int *res1, int *res2) {
    for (int i = 0; i < SIZE - 1; i++) {
        printf("%d ", res1[i]);
    }
    printf("%d\n", res1[SIZE - 1]);
    for (int i = 0; i < SIZE - 1; i++) {
        printf("%d ", res2[i]);
    }
    printf("%d", res2[SIZE - 1]);
}

void quicksort(int *arr, int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (arr[i] <= arr[pivot] && i < last) i++;
            while (arr[j] > arr[pivot]) j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int s1 = mid - left + 1;
    int s2 = right - mid;
    int left_arr[s1], right_arr[s2];
    for (i = 0; i < s1; i++) left_arr[i] = arr[left + i];
    for (j = 0; j < s2; j++) right_arr[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < s1 && j < s2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < s1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < s2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}