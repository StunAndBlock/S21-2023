#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, const int n, const int m);
void make_picture(int **picture, const int n, const int m);
void reset_picture(int **picture, const int n, const int m);
void output(int **matrix);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(*picture_data, picture, N, M);
    make_picture(picture, N, M);
    output(picture);
    return 0;
}

void make_picture(int **picture, const int n, const int m) {
    const int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int tree_trunk[] = {7, 7, 7, 7};
    const int tree_foliage[] = {3, 3, 3, 3};
    const int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                                {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    reset_picture(picture, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || i == n / 2) {
                for (int k = 0; k < m; k++) {
                    picture[i][k] = frame_w[k];
                }
            } else if (j == 0 || j == m - 1 || j == m / 2) {
                picture[i][j] = frame_h[i];
            } else if ((i == 2 || i == 5) && (j == 3 || j == 4)) {
                picture[i][j] = tree_foliage[i - 2];
            } else if ((i == 3 || i == 4) && (j > 1 && j < m / 2)) {
                picture[i][j] = tree_foliage[i - 2];
            } else if ((i == 6 || i == 8 || i == 9) && (j == 3 || j == 4)) {
                picture[i][j] = tree_trunk[j - 3];
            } else if ((i == 10) && (j > 1 && j < 6)) {
                picture[i][j] = tree_trunk[0];
            } else {
                picture[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[i + 1][j + m / 2 + 1] = sun_data[i][j];
        }
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void output(int **matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == M - 1) {
                if (i == N - 1) {
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