#include <stdio.h>
#include <string.h>

int search(char *path, const int *date);
int check(const char *date, int *int_date);

int main() {
    int error = 0;
    char tmp[100];
    if (scanf("%99s", tmp) != 1) {
        printf("n/a");
        error = 1;
    }
    char path[104] = "../";
    strcat(path, tmp);
    char date[11];
    if (!error) {
        if (scanf("%10s", date) != 1) {
            error = 1;
        }
    }
    int int_date[3];
    if (!error && !check(date, int_date)) {
        if (!search(path, int_date)) {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int search(char *path, const int *date) {
    int flag = 0;
    FILE *fp = fopen(path, "rb");
    if (fp == NULL) {
        printf("n/a");
    } else {
        while (!feof(fp)) {
            int year, month, day, hour, min, sec, id, code;
            fread(&year, sizeof(int), 1, fp);
            fread(&month, sizeof(int), 1, fp);
            fread(&day, sizeof(int), 1, fp);
            fread(&hour, sizeof(int), 1, fp);
            fread(&min, sizeof(int), 1, fp);
            fread(&sec, sizeof(int), 1, fp);
            fread(&id, sizeof(int), 1, fp);
            fread(&code, sizeof(int), 1, fp);
            if (date[0] == day && date[1] == month && date[2] == year) {
                printf("%d", code);
                flag = 1;
                break;
            }
        }
    }
    return flag;
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