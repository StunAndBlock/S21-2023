#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(const char *str);
int s21_strcmp(char *str1, char *str2);
int s21_strcpy(char *str1, char *str2);
int s21_strcat(char *str1, char *str2);
char *s21_strchr(char *str, char ch);
char *s21_strstr(char *str1, char *str2);
char *s21_strtok(char *str, char *sep);

#endif