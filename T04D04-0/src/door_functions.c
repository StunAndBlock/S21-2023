#include <math.h>
#include <stdio.h>

void anezi(double x);
void bernulli(double x);
void hyperbola(double x);

int main() {
    double delta = (M_PI + M_PI) / 41.0;
    double x = -M_PI;
    while (x < M_PI - delta) {
        printf("%.7lf", x);
        printf(" | ");
        anezi(x);
        printf(" | ");
        bernulli(x);
        printf(" | ");
        hyperbola(x);
        putchar('\n');
        x += delta;
    }
    printf("%.7lf", x);
    printf(" | ");
    anezi(x);
    printf(" | ");
    bernulli(x);
    printf(" | ");
    hyperbola(x);
    return 0;
}

void anezi(double x) {
    if (1 + pow(x, 2) == 0) {
        putchar('-');
    } else {
        printf("%.7lf", 1 / (1 + pow(x, 2)));
    }
}

void bernulli(double x) {
    if (1 + 4 * pow(x, 2) < 0) {
        putchar('-');
    } else if (pow(1 + 4 * pow(x, 2), 0.5) - pow(x, 2) - 1 < 0) {
        putchar('-');
    } else {
        printf("%.7lf", pow(pow(1 + 4 * pow(x, 2), 0.5) - pow(x, 2) - 1, 0.5));
    }
}

void hyperbola(double x) {
    if (x == 0) {
        putchar('-');
    } else {
        printf("%.7lf", 1 / pow(x, 2));
    }
}