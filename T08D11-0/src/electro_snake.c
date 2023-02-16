#include <stdio.h>
#include <stdlib.h>

int sort_vertical(const int n, const int m, int ***result_matrix,
                  const int *tmp);
int sort_horizontal(const int n, const int m, int ***result_matrix,
                    const int *tmp);
void quicksort(int *arr, int first, int last);
int input(int ***matr, int *n, int *m);
void output(int **matrix, const int n, const int m);
void delete (int **matrix, const int n);

int main() {
  int **matrix, **result;
  int n, m;
  if (input(&matrix, &n, &m)) {
    printf("n/a");
    delete (matrix, n);
    return 1;
  }
  int *tmp = (int *)malloc(n * m * sizeof(int));
  if (tmp == NULL) {
    printf("n/a");
    delete (matrix, n);
    return 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[i * m + j] = matrix[i][j];
    }
  }
  quicksort(tmp, 0, m * n - 1);
  if (sort_vertical(n, m, &result, tmp)) {
    printf("n/a");
    delete (matrix, n);
    free(tmp);
    return 1;
  }
  output(result, n, m);
  delete (result, n);
  printf("\n\n");
  if (sort_horizontal(n, m, &result, tmp)) {
    printf("n/a");
    delete (matrix, n);
    free(tmp);
    return 1;
  }
  output(result, n, m);
  delete (result, n);
  delete (matrix, n);
  free(tmp);
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
      if (matrix[i] == NULL) {
        error = 1;
        break;
      }
    }
  }
  if (!error) {
    for (int i = 0; i < *n; i++) {
      for (int j = 0; j < *m; j++) {
        if (scanf("%d", &(matrix[i][j])) != 1) {
          error = 1;
          break;
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

void quicksort(int *arr, int first, int last) {
  if (first < last) {
    int pivot = first;
    int i = first;
    int j = last;
    int temp = 0;
    while (i < j) {
      while (i < last && arr[i] <= arr[pivot])
        i++;
      while (arr[j] > arr[pivot])
        j--;
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

int sort_horizontal(const int n, const int m, int ***result_matrix,
                    const int *tmp) {
  int error = 0;
  int **res = (int **)malloc(n * sizeof(int *));
  if (res == NULL) {
    error = 1;
  }
  if (!error) {
    for (int i = 0; i < n; i++) {
      res[i] = (int *)malloc(m * sizeof(int));
      if (res[i] == NULL) {
        error = 1;
        free(res);
        break;
      }
    }
  }
  if (!error) {
    for (int i = 0; i < n; i++) {
      int j = 0;
      if (i % 2 == 0) {
        for (int k = i * m; k < i * m + m; k++) {
          res[i][j] = tmp[k];
          j++;
        }
      } else {
        for (int k = i * m + m - 1; k > i * m - 1; k--) {
          res[i][j] = tmp[k];
          j++;
        }
      }
    }
  }
  *result_matrix = res;
  return error;
}

int sort_vertical(int n, int m, int ***result_matrix, const int *tmp) {
  int error = 0;
  int **res = (int **)malloc(n * sizeof(int *));
  if (res == NULL) {
    error = 1;
  }
  if (!error) {
    for (int i = 0; i < n; i++) {
      res[i] = (int *)malloc(m * sizeof(int));
      if (res[i] == NULL) {
        error = 1;
        free(res);
        break;
      }
    }
  }
  if (!error) {
    for (int j = 0; j < m; j++) {
      int i = 0;
      if (j % 2 == 0) {
        for (int k = j * n; k < j * n + n; k++) {
          res[i][j] = tmp[k];
          i++;
        }
      } else {
        for (int k = j * n + n - 1; k > j * n - 1; k--) {
          res[i][j] = tmp[k];
          i++;
        }
      }
    }
  }
  *result_matrix = res;
  return error;
}