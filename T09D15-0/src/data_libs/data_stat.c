#include "data_stat.h"

#include <stdlib.h>

double max(double *data, int n) {
    double current_max = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > current_max) {
            current_max = data[i];
        }
    }
    return current_max;
}

double min(double *data, int n) {
    double current_min = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < current_min) {
            current_min = data[i];
        }
    }
    return current_min;
}

double mean(double *data, int n) {
    double mean = 0.0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    return mean / n;
}

void squaring(double *data, int n) {
    for (int i = 0; i < n; i++) {
        data[i] = data[i] * data[i];
    }
}

double variance(double *data, int n) {
    double *data_square = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        data_square[i] = data[i];
    }
    squaring(data_square, n);
    double answ = mean(data_square, n) - mean(data, n) * mean(data, n);
    free(data_square);
    return answ;
}