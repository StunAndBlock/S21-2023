#include <stdio.h>
#include <string.h>

#include "date.h"

void output(char *path);
int sort(char *path);
int cmp(date *tmp1, date *tmp2);
int add(char *path);

int main() {
    int error = 0;
    int input = -1;
    char tmp[100];
    if (scanf("%99s", tmp) != 1) {
        printf("n/a");
        error = 1;
    }
    char path[104] = "../";
    strcat(path, tmp);
    if (!error) {
        if (scanf("%d", &input) != 1) {
            printf("n/a");
            error = 1;
        }
    }
    if (!error) {
        switch (input) {
            case 0:
                output(path);
                break;
            case 1:
                if (!sort(path)) {
                    output(path);
                }
                break;
            case 2:
                if (!add(path)) {
                    if (!sort(path)) {
                        output(path);
                    }
                } else {
                    printf("n/a");
                }
                break;
            default:
                printf("n/a");
                break;
        }
    }
    return 0;
}

void output(char *path) {
    int error = 0;
    FILE *fp = fopen(path, "rb");
    if (fp == NULL || getc(fp) == EOF) {
        printf("n/a");
        error = 1;
    }
    if (!error) {
        rewind(fp);
        int count = get_records_count_in_file(fp);
        for (int i = 0; i < count; i++) {
            date tmp = read_record_from_file(fp, i);
            printf("%d %d %d %d %d %d %d %d\n", tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min, tmp.sec,
                   tmp.id, tmp.code);
        }
    }
    if (fp != NULL) {
        fclose(fp);
    }
}

int sort(char *path) {
    int error = 0;
    FILE *fp = fopen(path, "rb+");
    if (fp == NULL) {
        printf("n/a");
        error = 1;
    } else {
        int count = get_records_count_in_file(fp);
        for (int i = 0; i < count - 1; i++) {
            for (int j = i; j < count; j++) {
                date tmp = read_record_from_file(fp, i);
                date tmptmp = read_record_from_file(fp, j);
                if (cmp(&tmp, &tmptmp)) {
                    write_record_in_file(fp, &tmp, j);
                    write_record_in_file(fp, &tmptmp, i);
                }
            }
        }
        fclose(fp);
    }
    return error;
}

int cmp(date *tmp1, date *tmp2) {
    int result = 0;
    if (tmp1->year > tmp2->year) {
        result = 1;
    } else if (tmp1->year == tmp2->year) {
        if (tmp1->month > tmp2->month) {
            result = 1;
        } else if (tmp1->month == tmp2->month) {
            if (tmp1->day > tmp2->day) {
                result = 1;
            } else if (tmp1->day == tmp2->day) {
                if (tmp1->hour > tmp2->hour) {
                    result = 1;
                } else if (tmp1->hour == tmp2->hour) {
                    if (tmp1->min > tmp2->min) {
                        result = 1;
                    } else if (tmp1->min == tmp2->min) {
                        if (tmp1->sec > tmp2->sec) {
                            result = 1;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int add(char *path) {
    int error = 0;
    FILE *fp = fopen(path, "rb");
    if (fp == NULL || getc(fp) == EOF) {
        error = 1;
    }
    if (!error) {
        fclose(fp);
        fp = fopen(path, "ab");
        if (fp == NULL) {
            error = 1;
        }
    }
    if (!error) {
        int count = get_records_count_in_file(fp);
        date tmp;
        if (scanf("%d%d%d%d%d%d%d%d", &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min, &tmp.sec, &tmp.id,
                  &tmp.code) != 8) {
            error = 1;
        }
        if (!error) {
            write_record_in_file(fp, &tmp, count + 1);
        }
    }
    if (!error) {
        fclose(fp);
    }
    return error;
}