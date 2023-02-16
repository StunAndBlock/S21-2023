#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(char *test1, char *test2, char *test3);
void s21_strcmp_test(char *test1, char *test2, char *test3, char *test4, char *test5);
void s21_strcpy_test(char *test1, char *test2, char *test3, char *test4);
void s21_strcat_test(char *test1, char *test2, char *test3);
void s21_strchr_test(char *test1, char *test2, char *test3);
void s21_strstr_test(char *test1, char *test2, char *test3);
void s21_strtok_test(char *test1, char *test2, char *test3);

int main() {
#ifdef STRLEN
    char test1[5] = "aaaa";
    char test2[17] = "bbbbbb";
    char test3[2] = "c";
    s21_strlen_test(test1, test2, test3);
#endif
#ifdef STRCMP
    char test1[5] = "aaaa";
    char test2[7] = "bbbbbb";
    char test3[2] = "c";
    char test4[5] = "aaaa";
    char test5[7] = "bbbbbbz";
    s21_strcmp_test(test1, test2, test3, test4, test5);
#endif
#ifdef STRCPY
    char test1[5] = "aaaa";
    char test2[7] = "bbbbbb";
    char test3[100] = "ccc";
    char *test4 = NULL;
    s21_strcpy_test(test1, test2, test3, test4);
#endif
#ifdef STRCAT
    char test1[5] = "aaaa";
    char test2[7] = "bbbbbb";
    char test3[100] = "ccc";
    s21_strcat_test(test1, test2, test3);
#endif
#ifdef STRCHR
    char test1[5] = "aaaa";
    char test2[7] = "bbbbbb";
    char test3[4] = "ccbc";
    s21_strchr_test(test1, test2, test3);
#endif
#ifdef STRSTR
    char test1[11] = "aaaacccaaa";
    char test2[4] = "ccc";
    char test3[7] = "bbbbbb";
    s21_strstr_test(test1, test2, test3);
#endif
#ifdef STRTOK
    char test1[13] = "aaaa ccc aaa";
    char test2[5] = "ccc ";
    char test3[8] = "bbb/bbb";
    s21_strtok_test(test1, test2, test3);
#endif
    return 0;
}

void s21_strlen_test(char *test1, char *test2, char *test3) {
    printf("TEST-1 ... ");
    printf("%s ", test1);
    int res = s21_strlen(test1);
    printf("%d\n", res);
    if (res == 4) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... ");
    printf("%s ", test2);
    res = s21_strlen(test2);
    printf("%d\n", res);
    if (res == 6) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... ");
    printf("%s ", test3);
    res = s21_strlen(test3);
    printf("%d\n", res);
    if (res == 1) {
        printf("\tSUCCESS");
    } else {
        printf("\tFAIL");
    }
}

void s21_strcmp_test(char *test1, char *test2, char *test3, char *test4, char *test5) {
    printf("TEST-1 ... ");
    printf("%s %s ", test1, test2);
    int res = s21_strcmp(test1, test2);
    printf("%d\n", res);
    if (res == -1) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... ");
    printf("%s %s ", test1, test3);
    res = s21_strcmp(test1, test3);
    printf("%d\n", res);
    if (res == 1) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... ");
    printf("%s %s ", test1, test4);
    res = s21_strcmp(test1, test4);
    printf("%d\n", res);
    if (res == 0) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-4 ... ");
    printf("%s %s ", test2, test5);
    res = s21_strcmp(test2, test5);
    printf("%d\n", res);
    if (res == -1) {
        printf("\tSUCCESS");
    } else {
        printf("\tFAIL");
    }
}

void s21_strcpy_test(char *test1, char *test2, char *test3, char *test4) {
    printf("TEST-1 ... ");
    printf("%s %s ", test1, test2);
    int res = s21_strcpy(test1, test2);
    printf("%d %s\n", res, test2);
    if (s21_strcmp(test1, test2) == 0) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... ");
    printf("%s %s ", test2, test3);
    res = s21_strcpy(test2, test3);
    printf("%d %s\n", res, test3);
    if (res == 0) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... ");
    printf("%s ", test2);
    res = s21_strcpy(test2, test4);
    printf("%d\n", res);
    if (s21_strcpy(test2, test4) == 0) {
        printf("\tSUCCESS");
    } else {
        printf("\tFAIL");
    }
}

void s21_strcat_test(char *test1, char *test2, char *test3) {
    printf("TEST-1 ... ");
    printf("%s %s ", test1, test3);
    int res = s21_strcat(test1, test3);
    printf("%d %s\n", res, test3);
    if (s21_strcmp("cccaaaa", test3) == 0) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... ");
    printf("%s %s ", test1, test2);
    res = s21_strcat(test1, test2);
    printf("%d %s\n", res, test2);
    if (s21_strcat(test1, test2) == 0) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... ");
    printf("%s %s ", test2, test3);
    res = s21_strcat(test2, test3);
    printf("%d %s\n", res, test3);
    if (s21_strcmp("cccaaaabbbbbb", test3) == 0) {
        printf("\tSUCCESS");
    } else {
        printf("\tFAIL");
    }
}

void s21_strchr_test(char *test1, char *test2, char *test3) {
    printf("TEST-1 ... ");
    printf("%s %c ", test1, 'a');
    printf("%c\n", *s21_strchr(test1, 'a'));
    if (test1 == s21_strchr(test1, 'a')) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... ");
    printf("%s %c ", test2, 'z');
    printf("%p\n", s21_strchr(test1, 'z'));
    if (s21_strchr(test2, 'z') == NULL) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... ");
    printf("%s %c ", test3, 'b');
    printf("%c\n", *s21_strchr(test3, 'b'));
    if (test3 + 2 == s21_strchr(test3, 'b')) {
        printf("\tSUCCESS");
    } else {
        printf("\tFAIL");
    }
}

void s21_strstr_test(char *test1, char *test2, char *test3) {
    printf("TEST-1 ... ");
    printf("%s %s ", test1, test2);
    printf("%s\n", s21_strstr(test1, test2));
    if (s21_strcmp(s21_strstr(test1, test2), test1 + 4) == 0 && test1 + 4 == s21_strstr(test1, test2)) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... ");
    printf("%s %s ", test2, test1);
    printf("%s\n", s21_strstr(test2, test1));
    if (s21_strstr(test2, test1) == NULL) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... ");
    printf("%s %s ", test3, test2);
    printf("%s\n", s21_strstr(test3, test2));
    if (s21_strstr(test3, test2) == NULL) {
        printf("\tSUCCESS");
    } else {
        printf("\tFAIL");
    }
}

void s21_strtok_test(char *test1, char *test2, char *test3) {
    printf("TEST-1 ... ");
    printf("%s ", test1);
    printf("%s\n", s21_strtok(test1, " "));
    if (s21_strcmp(s21_strtok(test1, " "), "aaaa") == 0) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-2 ... ");
    printf("%s ", test2);
    printf("%s\n", s21_strtok(test2, " "));
    if (s21_strcmp(s21_strtok(test2, " "), "ccc") == 0) {
        printf("\tSUCCESS\n");
    } else {
        printf("\tFAIL\n");
    }
    printf("TEST-3 ... ");
    printf("%s ", test3);
    printf("%s\n", s21_strtok(test3, "/"));
    if (s21_strcmp(s21_strtok(test3, "/"), "bbb") == 0) {
        printf("\tSUCCESS");
    } else {
        printf("\tFAIL");
    }
}