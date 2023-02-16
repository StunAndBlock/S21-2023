#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int menu(int *n, int *m);
int input(int **matrix, const int n, const int m);
int allocation_1(int n, int m);
int allocation_2(int n, int m);
int allocation_3(int n, int m);
int allocation_4(int n, int m);
void output(int **matrix, const int n, const int m, int *rowmax, int *colmin);
void row_max(int **matrix, const int n, const int m, int *res);
void col_min(int **matrix, const int n, const int m, int *res);

int main() {
    int n = 0;
    int m = 0;
    int choice = menu(&n, &m);
    switch (choice) {
        case 1:
            if (allocation_1(n, m)) {
                printf("n/a");
                return 1;
            }
            break;
        case 2:
            if (allocation_2(n, m)) {
                printf("n/a");
                return 1;
            }
            break;
        case 3:
            if (allocation_3(n, m)) {
                printf("n/a");
                return 1;
            }
            break;
        case 4:
            if (allocation_4(n, m)) {
                printf("n/a");
                return 1;
            }
            break;
        default:
            printf("n/a");
            return 1;
    }
    return 0;
}

int menu(int *n, int *m) {
    int choice = 0;
    if (scanf("%d", &choice) == 1) {
        if (choice > 4 || choice < 1) {
            choice = -1;
        }
    }
    if (choice != -1) {
        if (scanf("%d %d", n, m) == 2) {
            if (*n < 1 || *m < 1) {
                choice = -1;
            } else if (choice == 1) {
                if (*n > NMAX || *m > NMAX) {
                    choice = -1;
                }
            }
        }
    }
    return choice;
}

int input(int **matrix, const int n, const int m) {
    int error = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &(matrix[i][j])) != 1) {
                error = 1;
                break;
            }
        }
    }
    return error;
}

void output(int **matrix, const int n, const int m, int *rowmax, int *colmin) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d\n", matrix[i][j]);
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", rowmax[i]);
    }
    printf("%d\n", rowmax[n - 1]);
    for (int i = 0; i < m - 1; i++) {
        printf("%d ", colmin[i]);
    }
    printf("%d", colmin[m - 1]);
}

int allocation_1(const int n, const int m) {
    int error = 0;
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &(matrix[i][j])) != 1) {
                error = 1;
            }
        }
    }
    if (!error) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == m - 1) {
                    printf("%d\n", matrix[i][j]);
                } else {
                    printf("%d ", matrix[i][j]);
                }
            }
        }
    }
    int row[n];
    for (int i = 0; i < n; i++) {
        int max = -2147483648;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        row[i] = max;
    }
    int col[m];
    for (int i = 0; i < m; i++) {
        int min = 2147483647;
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] < min) {
                min = matrix[j][i];
            }
        }
        col[i] = min;
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", row[i]);
    }
    printf("%d\n", row[n - 1]);
    for (int i = 0; i < m - 1; i++) {
        printf("%d ", col[i]);
    }
    printf("%d", col[m - 1]);
    return error;
}

int allocation_2(const int n, const int m) {
    int error = 0;
    int **matrix = (int **)malloc(m * n * sizeof(int) + n * sizeof(int *));
    if (matrix == NULL) {
        error = 1;
    }
    int *ptr;
    if (!error) {
        ptr = (int *)(matrix + n);
        for (int i = 0; i < n; i++) {
            matrix[i] = ptr + m * i;
        }
        if (input(matrix, n, m)) {
            error = 1;
            free(matrix);
        }
    }
    if (!error) {
        int row[n];
        int col[m];
        row_max(matrix, n, m, row);
        col_min(matrix, n, m, col);
        output(matrix, n, m, row, col);
        free(matrix);
    }
    return error;
}

int allocation_3(const int n, const int m) {
    int error = 0;
    int **pointers = (int **)malloc(n * sizeof(int *));
    if (pointers == NULL) {
        error = 1;
    }
    if (!error) {
        for (int i = 0; i < n; i++) {
            pointers[i] = (int *)malloc(m * sizeof(int));
            if (pointers[i] == NULL) {
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        if (input(pointers, n, m)) {
            error = 1;
            for (int i = 0; i < n; i++) {
                free(pointers[i]);
            }
            free(pointers);
        }
    }
    if (!error) {
        int row[n];
        int col[m];
        row_max(pointers, n, m, row);
        col_min(pointers, n, m, col);
        output(pointers, n, m, row, col);
        for (int i = 0; i < n; i++) {
            free(pointers[i]);
        }
        free(pointers);
    }
    return error;
}

int allocation_4(const int n, const int m) {
    int error = 0;
    int **pointers = (int **)malloc(n * sizeof(int *));
    if (pointers == NULL) {
        error = 1;
    }
    int *values = (int *)malloc(m * n * sizeof(int));
    if (values == NULL) {
        error = 1;
    }
    for (int i = 0; i < m; i++) {
        pointers[i] = values + m * i;
    }
    if (!error) {
        if (input(pointers, n, m)) {
            error = 1;
            free(values);
            free(pointers);
        }
    }
    if (!error) {
        int row[n];
        int col[m];
        row_max(pointers, n, m, row);
        col_min(pointers, n, m, col);
        output(pointers, n, m, row, col);
        free(values);
        free(pointers);
    }
    return error;
}

void row_max(int **matrix, const int n, const int m, int *res) {
    for (int i = 0; i < n; i++) {
        int max = -2147483648;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        res[i] = max;
    }
}

void col_min(int **matrix, int n, int m, int *res) {
    for (int i = 0; i < m; i++) {
        int min = 2147483647;
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] < min) {
                min = matrix[j][i];
            }
        }
        res[i] = min;
    }
}