#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int menu(int *n, int *m);
int input(int **matrix, const int n, const int m);
int allocation_1(int n, int m);
int allocation_2(int n, int m);
int allocation_3(int n, int m);
int allocation_4(int n, int m);
void output(int **matrix, const int n, const int m);

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

void output(int **matrix, const int n, const int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                if (i == n - 1) {
                    printf("%d", matrix[i][j]);
                } else {
                    printf("%d\n", matrix[i][j]);
                }
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
    }
}

int allocation_1(const int n, const int m) {
    int error = 0;
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &(matrix[i][j])) != 1) {
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == m - 1) {
                    if (i == n - 1) {
                        printf("%d", matrix[i][j]);
                    } else {
                        printf("%d\n", matrix[i][j]);
                    }
                } else {
                    printf("%d ", matrix[i][j]);
                }
            }
        }
    }
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
        output(matrix, n, m);
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
        output(pointers, n, m);
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
        output(pointers, n, m);
        free(values);
        free(pointers);
    }
    return error;
}