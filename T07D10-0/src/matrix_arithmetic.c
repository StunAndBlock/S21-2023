#include <stdio.h>
#include <stdlib.h>

int input(int ***matr, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m, int ***result);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result);
void delete (int **matrix, const int n);

int main() {
    int type = 0;
    if (scanf("%d", &type) != 1 || type < 1 || type > 3) {
        printf("n/a");
        return 1;
    }
    int **matrix1;
    int **matrix2;
    int **result;
    int n1, m1, n2, m2, n, m;
    n1 = m1 = n2 = m2 = n = m = 0;
    switch (type) {
        case 1:
            if (input(&matrix1, &n1, &m1)) {
                delete (matrix1, n1);
                printf("n/a");
                return 1;
            }
            if (input(&matrix2, &n2, &m2)) {
                delete (matrix1, n1);
                delete (matrix2, n2);
                printf("n/a");
                return 1;
            }
            if (sum(matrix1, n1, m1, matrix2, n2, m2, &result, &n, &m)) {
                printf("n/a");
                return 1;
            }
            output(result, n, m);
            delete (result, n);
            break;
        case 2:
            if (input(&matrix1, &n1, &m1)) {
                delete (matrix1, n1);
                printf("n/a");
                return 1;
            }
            if (input(&matrix2, &n2, &m2)) {
                delete (matrix1, n1);
                delete (matrix2, n2);
                printf("n/a");
                return 1;
            }
            if (mul(matrix1, n1, m1, matrix2, n2, m2, &result, &n, &m)) {
                printf("n/a");
                return 1;
            }
            output(result, n, m);
            delete (result, n);
            break;
        case 3:
            if (input(&matrix1, &n1, &m1)) {
                delete (matrix1, n1);
                printf("n/a");
                return 1;
            }
            if (transpose(matrix1, n1, m1, &result)) {
                printf("n/a");
                return 1;
            }
            n = m1;
            m = n1;
            output(result, n, m);
            delete (result, m);
            break;
        default:
            printf("n/a");
            return 1;
    }
    return 0;
}

int input(int ***matr, int *n, int *m) {
    int error = 0;
    if (scanf("%d%d", n, m) != 2 || *n < 1 || *m < 1) {
        error = 1;
    }
    int **matrix = NULL;
    if (!error) {
        matrix = (int **)malloc(*n * sizeof(int *));
        if (matrix == NULL) {
            error = 1;
        }
    }
    if (!error) {
        for (int i = 0; i < *n; i++) {
            matrix[i] = (int *)malloc(*m * sizeof(int));
        }
        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                if (scanf("%d", &(matrix[i][j])) != 1) {
                    error = 1;
                }
            }
        }
    }
    *matr = matrix;
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

void delete (int **matrix, const int n) {
    if (matrix == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int transpose(int **matrix, int n, int m, int ***result) {
    int error = 0;
    int **res = (int **)malloc(m * sizeof(int *));
    if (res == NULL) {
        error = 1;
    }
    if (!error) {
        for (int i = 0; i < m; i++) {
            res[i] = (int *)malloc(n * sizeof(int));
            if (res[i] == NULL) {
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = matrix[j][i];
            }
        }
    }
    delete (matrix, n);
    *result = res;
    return error;
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    int error = 0;
    if (n_first != n_second || m_first != m_second) {
        error = 1;
    }
    *n_result = n_first;
    *m_result = m_first;
    int **res = (int **)malloc(*n_result * sizeof(int *));
    if (res == NULL) {
        error = 1;
    }
    if (!error) {
        for (int i = 0; i < *n_result; i++) {
            res[i] = (int *)malloc(*m_result * sizeof(int));
            if (res[i] == NULL) {
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        for (int i = 0; i < *n_result; i++) {
            for (int j = 0; j < *m_result; j++) {
                res[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }
    delete (matrix_first, n_first);
    delete (matrix_second, n_second);
    *matrix_result = res;
    return error;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int ***matrix_result, int *n_result, int *m_result) {
    int error = 0;
    if (m_first != n_second) {
        error = 1;
    }
    *n_result = n_first;
    *m_result = m_second;
    int **res = (int **)malloc(*n_result * sizeof(int *));
    if (res == NULL) {
        error = 1;
    }
    if (!error) {
        for (int i = 0; i < *n_result; i++) {
            res[i] = (int *)malloc(*m_result * sizeof(int));
            if (res[i] == NULL) {
                error = 1;
                break;
            }
        }
    }
    if (!error) {
        for (int i = 0; i < *n_result; i++) {
            for (int j = 0; j < *m_result; j++) {
                int summ = 0;
                for (int k = 0; k < m_first; k++) {
                    summ += matrix_first[i][k] * matrix_second[k][j];
                }
                res[i][j] = summ;
            }
        }
    }
    *matrix_result = res;
    delete (matrix_first, n_first);
    delete (matrix_second, n_second);
    return error;
}