#include <stdio.h>

#define LEN 100

int input(int *num1, int *num2, int *n1, int *n2);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void output(int *sum_result, int *sub_result, int n1, int n2, int flag1, int flag2);

int main() {
    int number1[LEN] = {};
    int number2[LEN] = {};
    int n1 = 0;
    int n2 = 0;
    if (input(number1, number2, &n1, &n2)) {
        printf("n/a");
        return 1;
    }
    int flag1 = 0;
    int flag2 = 0;
    int sum_result[LEN] = {};
    int n3 = 0;
    sum(number1, n1, number2, n2, sum_result, &n3);
    if (n3 > n1 && n3 > n2) {
        flag1 = 1;
    }
    int sub_result[LEN] = {};
    int n4 = 0;
    sub(number1, n1, number2, n2, sub_result, &n4);
    if (n4 == 0) {
        flag2 = 1;
    }
    output(sum_result, sub_result, n3, n4, flag1, flag2);
    return 0;
}

int input(int *num1, int *num2, int *n1, int *n2) {
    int error = 0;
    char c;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < LEN; i++) {
        if (scanf("%d%c", &(num1[i]), &c) != 2 || num1[i] < 0 || num1[i] > 9) {
            error = 1;
            break;
        }
        count1++;
        if (c != ' ' && c != '\n') {
            error = 1;
            break;
        }
        if (c == '\n') {
            break;
        }
    }
    for (int i = 0; i < LEN; i++) {
        if (scanf("%d%c", &(num2[i]), &c) != 2 || num2[i] < 0 || num2[i] > 9) {
            error = 1;
            break;
        }
        count2++;
        if (c != ' ' && c != '\n') {
            error = 1;
            break;
        }
        if (c == '\n') {
            break;
        }
    }
    *n1 = count1;
    *n2 = count2;
    return error;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int count = 0;
    int tmp = 0;
    int ost = 0;
    if (len1 >= len2) {
        count = len1;
        for (int i = len1 - 1; i > -1; i--) {
            if (len2 > 0) {
                tmp = buff1[i] + buff2[len2 - 1] + ost;
                len2--;
            } else {
                tmp = buff1[i] + ost;
            }
            result[i] = tmp % 10;
            ost = (tmp / 10 == 1) ? 1 : 0;
        }
        if (ost == 1) {
            count += 1;
        }
    } else {
        count = len2;
        for (int i = len2 - 1; i > -1; i--) {
            if (len1 > 0) {
                tmp = buff2[i] + buff1[len1 - 1] + ost;
                len1--;
            } else {
                tmp = buff2[i] + ost;
            }
            result[i] = tmp % 10;
            ost = (tmp / 10 == 1) ? 1 : 0;
        }
        if (ost == 1) {
            count += 1;
        }
    }
    *result_length = count;
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (len2 > len1) {
        for (int i = 0; i < len2; i++) {
            if (buff2[i] != 0 && len2 - i > len1) {
                *result_length = 0;
                return;
            }
        }
    } else if (len2 == len1) {
        int flag = 1;
        for (int i = 0; i < len1; i++) {
            if (buff1[i] < buff2[i] && flag) {
                *result_length = 0;
                return;
            } else if (buff1[i] > buff2[i]) {
                flag = 0;
                break;
            }
        }
    }
    int count = 0;
    int tmp = 0;
    int ost = 0;
    for (int i = len1 - 1; i > -1; i--) {
        if (ost) {
            buff1[i] -= 1;
            ost = 0;
        }
        if (len2 > 0) {
            if (buff2[len2 - 1] > buff1[i]) {
                tmp = 10 + buff1[i] - buff2[len2 - 1];
                ost = 1;
            } else {
                tmp = buff1[i] - buff2[len2 - 1];
                ost = 0;
            }
            len2--;
        } else {
            if (buff1[i] < 0) {
                tmp = 9;
                ost = 1;
            } else {
                tmp = buff1[i];
            }
        }
        result[i] = tmp % 10;
        count++;
    }
    *result_length = count;
}

void output(int *sum_result, int *sub_result, int n1, int n2, int flag1, int flag2) {
    int count = 0;
    if (flag1) {
        printf("%d ", 1);
        count++;
        n1 -= 1;
    }
    for (int i = 0; i < n1 - 1; i++) {
        if (sum_result[i] == 0 && count == 0) {
            continue;
        } else {
            printf("%d ", sum_result[i]);
            count++;
        }
    }
    printf("%d\n", sum_result[n1 - 1]);
    if (flag2) {
        printf("n/a");
    } else {
        count = 0;
        for (int i = 0; i < n2 - 1; i++) {
            if (sub_result[i] == 0 && count == 0) {
                continue;
            } else {
                printf("%d ", sub_result[i]);
                count++;
            }
        }
        printf("%d", sub_result[n2 - 1]);
    }
}