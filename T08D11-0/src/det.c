#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, const int n, const int m, int *error);
int input(double ***matr, int *n, int *m);
void output(double res);
void delete (double **matrix, const int n);

int main() {
  int n, m;
  double **matrix;
  if (input(&matrix, &n, &m)) {
    delete (matrix, n);
    printf("n/a");
    return 1;
  }
  int error = 0;
  double result = det(matrix, n, m, &error);
  if (error) {
    delete (matrix, n);
    printf("n/a");
    return 1;
  } else {
    output(result);
    delete (matrix, n);
  }
  return 0;
}

int input(double ***matr, int *n, int *m) {
  int error = 0;
  if (scanf("%d%d", n, m) != 2 || *n < 1 || *m < 1 || *n != *m) {
    error = 1;
  }
  double **matrix = NULL;
  if (!error) {
    matrix = (double **)malloc(*n * sizeof(double *));
    if (matrix == NULL) {
      error = 1;
    }
  }
  if (!error) {
    for (int i = 0; i < *n; i++) {
      matrix[i] = (double *)malloc(*m * sizeof(double));
      if (matrix[i] == NULL) {
        error = 1;
        break;
      }
    }
  }
  if (!error) {
    for (int i = 0; i < *n; i++) {
      for (int j = 0; j < *m; j++) {
        if (scanf("%lf", &(matrix[i][j])) != 1) {
          error = 1;
          break;
        }
      }
    }
  }
  *matr = matrix;
  return error;
}

void delete (double **matrix, const int n) {
  if (matrix == NULL) {
    return;
  } else {
    for (int i = 0; i < n; i++) {
      free(matrix[i]);
    }
    free(matrix);
  }
}

void output(double res) { printf("%.6lf", res); }

double det(double **matrix, const int n, const int m, int *error) {
  double result = 0;
  if (n == 1) {
    result = matrix[0][0];
    return result;
  } else if (n == 2) {
    result = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return result;
  }
  int sign = 1;
  for (int i = 0; i < m; i++) {
    double **tmp = (double **)malloc((n - 1) * sizeof(double *));
    if (tmp == NULL) {
      *error = 1;
      break;
    }
    if (!(*error)) {
      for (int j = 0; j < n - 1; j++) {
        tmp[j] = (double *)malloc((m - 1) * sizeof(double));
        if (tmp[j] == NULL) {
          *error = 1;
          break;
        }
      }
    }
    if (!(*error)) {
      int i_minor = 0;
      for (int i_global = 1; i_global < n; i_global++) {
        int j_minor = 0;
        for (int j_global = 0; j_global < m; j_global++) {
          if (j_global != i) {
            tmp[i_minor][j_minor] = matrix[i_global][j_global];
            j_minor++;
          }
        }
        i_minor++;
      }
      int error1 = 0;
      double minor = det(tmp, n - 1, m - 1, &error1);
      if (!error1) {
        result += sign * matrix[0][i] * minor;
        sign *= -1;
      } else {
        *error = 1;
        break;
      }
    }
    delete (tmp, n - 1);
  }
  return result;
}