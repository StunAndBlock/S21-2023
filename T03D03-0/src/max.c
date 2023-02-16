#include <stdio.h>

int find_max(int a, int b);

int main() {
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) {
        puts("n/a");
        return -1;
    }
    printf("%d\n", find_max(a, b));
    return 0;
}

int find_max(int a, int b) {
    int max = (a >= b) ? a : b;
    return max;
}