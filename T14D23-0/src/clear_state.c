#include <stdio.h>
#include <string.h>

#include "date.h"

void output(char *path);
int remove_record(char *path, int *date1, int *date2);
int sort(char *path);
int check(const char *date, int *int_date);
int check_date(date *tmp, const int *date1, const int *date2);
int cmp(date *tmp1, date *tmp2);
int date_cmp(const int *date1, const int *date2);

int main() {
    int error = 0;
    char tmp[100];
    if (scanf("%99s", tmp) != 1) {
        printf("n/a");
        error = 1;
    }
    char path[104] = "../";
    strcat(path, tmp);
    char date1[11];
    char date2[11];
    char del;
    if (!error) {
        if (scanf("%10s%c%10s", date1, &del, date2) != 3) {
            error = 1;
            printf("n/a");
        }
    }
    int int_date1[3];
    int int_date2[3];
    if (!error && !check(date1, int_date1) && !check(date2, int_date2)) {
        if (!date_cmp(int_date1, int_date2)) {
            if (!sort(path)) {
                if (!remove_record(path, int_date1, int_date2)) {
                    output(path);
                } else {
                    printf("n/a");
                }
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int check(const char *date, int *int_date) {
    int error = 0;
    if (date[0] < '0' || date[0] > '9' || date[1] < '0' || date[1] > '9') {
        error = 1;
    }
    if (!error) {
        if (date[3] < '0' || date[3] > '9' || date[4] < '0' || date[4] > '9') {
            error = 1;
        }
    }
    if (!error) {
        if (date[2] != '.' || date[5] != '.') {
            error = 1;
        }
    }
    for (int i = 6; i < 10; i++) {
        if (date[i] < '0' || date[i] > '9') {
            error = 1;
            break;
        }
    }
    if (!error) {
        if (date[0] == '0') {
            int_date[0] = (int)(date[1] - '0');
        } else {
            int_date[0] = 10 * (int)(date[0] - '0') + (int)(date[1] - '0');
        }
        if (date[3] == '0') {
            int_date[1] = (int)(date[4] - '0');
        } else {
            int_date[1] = 10 * (int)(date[3] - '0') + (int)(date[4] - '0');
        }
        int_date[2] = 1000 * (int)(date[6] - '0') + 100 * (int)(date[7] - '0') + 10 * (int)(date[8] - '0') +
                      (int)(date[9] - '0');
    }
    return error;
}

void output(char *path) {
    FILE *fp = fopen(path, "rb");
    if (fp == NULL) {
        printf("n/a");
    } else {
        int count = get_records_count_in_file(fp);
        for (int i = 0; i < count; i++) {
            date tmp = read_record_from_file(fp, i);
            printf("%d %d %d %d %d %d %d %d\n", tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min, tmp.sec,
                   tmp.id, tmp.code);
        }
        fclose(fp);
    }
}

int remove_record(char *path, int *date1, int *date2) {
    int error = 0;
    FILE *fp = fopen(path, "rb");
    if (fp == NULL) {
        error = 1;
        printf("n/a");
    }
    FILE *fpt;
    char tmp_path[100] = "tmp";
    if (!error) {
        fpt = fopen(tmp_path, "wb");
        if (fpt == NULL) {
            fclose(fp);
            printf("n/a");
            error = 1;
        }
    }
    if (!error) {
        int j = 0;
        int count = get_records_count_in_file(fp);
        for (int i = 0; i < count; i++) {
            date tmp = read_record_from_file(fp, i);
            if (check_date(&tmp, date1, date2)) {
                write_record_in_file(fpt, &tmp, j);
                j++;
            }
        }
        fclose(fp);
        fclose(fpt);
        rename(tmp_path, path);
    }
    return error;
}

int check_date(date *tmp, const int *date1, const int *date2) {
    int result = 0;
    if (tmp->year < date1[2] || tmp->year > date2[2]) {
        result = 1;
    } else if (tmp->year == date1[2] || tmp->year == date2[2]) {
        if (tmp->month < date1[1] || tmp->month > date2[1]) {
            result = 1;
        } else if (tmp->month == date1[1] || tmp->month == date2[1]) {
            if (tmp->day < date1[0] || tmp->day > date2[0]) {
                result = 1;
            }
        }
    }
    return result;
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

int date_cmp(const int *date1, const int *date2) {
    int error = 0;
    if (date1[2] > date2[2]) {
        error = 1;
    } else if (date1[2] == date2[2]) {
        if (date1[1] > date2[2]) {
            error = 1;
        } else if (date1[1] == date2[1]) {
            if (date1[0] > date2[0]) {
                error = 1;
            }
        }
    }
    return error;
}