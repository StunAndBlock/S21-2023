#include <stdio.h>

void check_inside(float x, float y);

int main() {
    float x, y;
    if (scanf("%f%f", &x, &y) != 2) {
        puts("n/a");
        return -1;
    }
    check_inside(x, y);
    return 0;
}

void check_inside(float x, float y) {
    if (x * x + y * y < 25) {
        puts("GOTCHA");
    } else {
        puts("MISS");
    }
}