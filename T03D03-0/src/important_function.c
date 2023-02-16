#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double get_result(double x);

int main() {
    double x;
    if (scanf("%lf", &x) != 1) {
        puts("n/a");
        return -1;
    }
    printf("%.1lf\n", get_result(x));
}

double get_result(double x) {
    return 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1/3) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2 / x) - 1.01;
}