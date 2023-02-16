#include <stdio.h>

int main() {
    int name = 0;
    if (scanf("%d", &name) != 1) {
        puts("n/a");
        return -1;
    }
    printf("Hello, %d!\n", name);
    return 0;
}