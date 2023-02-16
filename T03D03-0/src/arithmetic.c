#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int mult(int a, int b);
int div(int a, int b);

int main()
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) {
        puts("n/a");
        return -1;
    }
    printf("%d ", sum(a, b));
    printf("%d ", diff(a, b));
    printf("%d ", mult(a, b));
    if (b != 0) {
        printf("%d\n", div(a, b));
    } else {
        printf("n/a\n");
    }
    return 0;
}

int sum(int a, int b){
    return a + b;
}

int diff(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}