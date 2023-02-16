#include <stdio.h>
#include <stdlib.h>

int invert(double **matrix, const int n, const int m, double ***result);
double det(double **matrix, const int n, const int m, int *error);
int transpose(double **matrix, const int n, const int m, double ***result);
int input(double ***matr, int *n, int *m);
void output(double **matrix, const int n, const int m);
void delete (double **matrix, const int n);

int main() {
  int n, m;
  double **matrix;
  if (input(&matrix, &n, &m)) {
    delete (matrix, n);
    printf("n/a");
    return 1;
  }
  double **res;
  if (invert(matrix, n, m, &res)) {
    delete (res, n);
    printf("n/a");
    return 1;
  }
  delete (matrix, n);
  output(res, n, m);
  delete (res, n);
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

void output(double **matrix, const int n, const int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j == m - 1) {
        if (i == n - 1) {
          printf("%lf", matrix[i][j]);
        } else {
          printf("%lf\n", matrix[i][j]);
        }
      } else {
        printf("%lf ", matrix[i][j]);
      }
    }
  }
}

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

int transpose(double **matrix, const int n, const int m, double ***result) {
  int error = 0;
  double **res = (double **)malloc(m * sizeof(double *));
  if (res == NULL) {
    error = 1;
  }
  if (!error) {
    for (int i = 0; i < m; i++) {
      res[i] = (double *)malloc(n * sizeof(double));
      if (res[i] == NULL) {
        error = 1;
        delete (res, n);
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

int invert(double **matrix, const int n, const int m, double ***result) {
  int error = 0;
  double determ = det(matrix, n, m, &error);
  if (determ == 0) {
    error = 1;
  }
  double **res;
  if (!error) {
    determ = 1 / determ;
    res = (double **)malloc(n * sizeof(double *));
    if (res == NULL) {
      error = 1;
    }
  }
  if (!error) {
    for (int i = 0; i < n; i++) {
      res[i] = (double *)malloc(m * sizeof(double));
      if (res[i] == NULL) {
        error = 1;
        delete (res, n);
        break;
      }
    }
  }
  if (!error) {
    int sign = 1;
    for (int i = 0; i < n; i++) {
      if (!error) {
        for (int j = 0; j < m; j++) {
          double **tmp = (double **)malloc((n - 1) * sizeof(double *));
          if (tmp == NULL) {
            error = 1;
            break;
          }
          if (!error) {
            for (int k = 0; k < n - 1; k++) {
              tmp[k] = (double *)malloc((m - 1) * sizeof(double));
              if (tmp[k] == NULL) {
                error = 1;
                delete (tmp, n - 1);
                break;
              }
            }
          }
          if (!error) {
            int i_tmp = 0;
            for (int k = 0; k < n; k++) {
              int j_tmp = 0;
              for (int l = 0; l < m; l++) {
                if (k != i && l != j) {
                  tmp[i_tmp][j_tmp] = matrix[k][l];
                  j_tmp++;
                }
              }
              if (k != i) {
                i_tmp++;
              }
            }
            res[i][j] = sign * det(tmp, n - 1, m - 1, &error);
            delete (tmp, n - 1);
          }
          sign *= -1;
        }
      }
    }
  }
  double **tmp = NULL;
  if (!error) {
    if (transpose(res, n, m, &tmp)) {
      error = 1;
    }
  }
  if (!error) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        tmp[i][j] *= determ;
      }
    }
  }
  *result = tmp;
  return error;
}