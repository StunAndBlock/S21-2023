#include <stdio.h>

void code();
void decode();
int symbolCheck(char c);
void clear(int count);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("n/a");
        return 1;
    }
    if (argv[1][0] == '0' && argv[1][1] == '\0') {
        code();
    } else if (argv[1][0] == '1' && argv[1][1] == '\0') {
        decode();
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}

int symbolCheck(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    } else {
        return 0;
    }
}

void clear(int count) {
    putchar('\r');
    while (count > 0) {
        printf("   ");
        count--;
    }
    printf("\rn/a");
}

void code() {
    char c1 = 0;
    char c2 = 0;
    int count = 0;
    while (c2 != '\n') {
        if (scanf("%c", &c2) != 1) {
            clear(count);
            break;
        }
        if ((c1 == 0 || c1 == ' ') && symbolCheck(c2) == 1) {
            printf("%X", (int)c2);
            ++count;
            c1 = c2;
        } else if (symbolCheck(c1) == 1 && c2 == ' ') {
            putchar(c2);
            ++count;
            c1 = c2;
        } else if (c2 != '\n') {
            clear(count);
            break;
        }
    }
    if (c1 == ' ') {
        putchar('\b');
    }
}

void decode() {
    int c1 = 0;
    char c2 = 0;
    int count = 0;
    while (c2 != '\n' && c1 != '\n') {
        if (scanf("%X%c", &c1, &c2) != 2) {
            clear(count);
            break;
        }
        if (symbolCheck((char)c1) == 1 && (c2 == ' ' || c2 == '\n')) {
            printf("%c", (char)c1);
            if (c2 == ' ') {
                putchar(' ');
            }
            count += 3;
        } else if (!symbolCheck(c1)) {
            clear(count);
            break;
        }
    }
}