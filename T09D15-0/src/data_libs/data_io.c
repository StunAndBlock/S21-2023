#include "data_io.h"

#include <stdio.h>

int input(double *data, int n) {
    int error = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            error = 1;
            break;
        }
    }
    return error;
}

void output(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%.2lf ", data[i]);
    }
    printf("%.2lf", data[n - 1]);
}