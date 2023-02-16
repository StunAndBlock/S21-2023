#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

void sort(double *arr, int first, int last);
void copy(double *data, int n, double *res);

int main() {
    int error = 0;
    int n = 0;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        error = 1;
    }
    double *data = NULL;
    if (!error) {
        data = (double *)malloc(n * sizeof(double));
        if (data == NULL) {
            printf("n/a");
            error = 1;
        }
    }
    if (!error) {
        printf("LOAD DATA...\n");
        if (input(data, n)) {
            printf("n/a");
            error = 1;
        }
    }
    if (!error) {
        printf("RAW DATA:\n\t");
        output(data, n);
        printf("\nNORMALIZED DATA:\n\t");
        if (normalization(data, n)) {
            output(data, n);
        } else {
            printf("ERROR");
        }
        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, 0, n - 1);
        output(data, n);
        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n)) {
            printf("YES");
        } else {
            printf("NO");
        }
    }
    if (data != NULL) {
        free(data);
    }
    return 0;
}

void sort(double *arr, int first, int last) {
    if (first < last) {
        int pivot = first;
        int i = first;
        int j = last;
        double temp = 0;
        while (i < j) {
            while (i < last && arr[i] <= arr[pivot]) i++;
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
        sort(arr, first, j - 1);
        sort(arr, j + 1, last);
    }
}