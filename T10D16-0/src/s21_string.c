#include "s21_string.h"

#include <stdlib.h>

int s21_strlen(const char *str) {
    int n = 0;
    if (str) {
        char c = str[n];
        while (c != '\0') {
            n++;
            c = str[n];
        }
    }
    return n;
}

int s21_strcmp(char *str1, char *str2) {
    int result = 0;
    int l1 = s21_strlen(str1);
    int l2 = s21_strlen(str2);
    if (l1 > l2) {
        result = 1;
    } else if (l2 > l1) {
        result = -1;
    } else {
        for (int i = 0; i < l1; i++) {
            if (str1[i] > str2[i]) {
                result = 1;
                break;
            } else if (str1[i] < str2[i]) {
                result = -1;
                break;
            }
        }
    }
    return result;
}

int s21_strcpy(char *str1, char *str2) {
    int result = 0;
    if (!str1 || !str2 || *(&str2 + 1) - str2 < s21_strlen(str1)) {
        result = 0;
    } else {
        int l1 = s21_strlen(str1);
        for (int i = 0; i < l1; i++) {
            str2[i] = str1[i];
        }
        str2[l1] = '\0';
        result = 1;
    }
    return result;
}

int s21_strcat(char *str1, char *str2) {
    int result = 0;
    int l1 = s21_strlen(str1);
    int l2 = s21_strlen(str2);
    if (!str1 || !str2 || l1 + l2 + 1 > *(&str2 + 1) - str2) {
        result = 0;
    } else {
        for (int i = 0; i < l1; i++) {
            str2[l2 + i] = str1[i];
        }
        str2[l1 + l2] = '\0';
        result = 1;
    }
    return result;
}

char *s21_strchr(char *str, char ch) {
    char *ptr = NULL;
    int l = s21_strlen(str);
    if (l != 0) {
        for (int i = 0; i < l; i++) {
            if (str[i] == ch) {
                ptr = &str[i];
                break;
            }
        }
    }
    return ptr;
}

char *s21_strstr(char *str1, char *str2) {
    char *ptr = NULL;
    if (str1 && str2) {
        int l1 = s21_strlen(str1);
        int l2 = s21_strlen(str2);
        if (l1 >= l2) {
            for (int i = 0; i < l1; i++) {
                if (str1[i] == str2[0] && l1 - i >= l2) {
                    ptr = &str1[i];
                    int count = 1;
                    for (int j = 1; j < l2; j++) {
                        if (str1[i + j] == str2[j]) {
                            count++;
                        }
                    }
                    if (count == l2) {
                        break;
                    } else {
                        ptr = NULL;
                    }
                }
            }
        }
    }
    return ptr;
}

char *s21_strtok(char *str, char *sep) {
    static char *next;
    if (str) {
        next = str;
        while (next != NULL && s21_strchr(sep, *next) != NULL) {
            if (++next) {
                next++;
                *next = '\0';
            }
        }
    }
    if (!next) return NULL;
    str = next;
    while (*next && !s21_strchr(sep, *next)) ++next;
    while (*next && s21_strchr(sep, *next)) {
        *next = '\0';
    }
    return str;
}