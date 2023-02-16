#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "log_levels.h"
#include "logger.h"

#define BUFSIZE 200

void output(FILE *fp);
void readf(FILE *fp, char *path, FILE *log_file);
void appendf(FILE *fp, char *path, FILE *log_file);
void encrypt_sesar(FILE *log_file);
void rewrite(char *path1, char *path2, int shift, FILE *log_file);
void copy(FILE *fp1, FILE *fp2);
void copy_shift(FILE *fp1, FILE *fp2, int shift);
void des(FILE *log_file);
void clear();

int main() {
    int input = 0;
    int prev_input = 0;
    char path[BUFSIZE];
    FILE *fp = fopen("logs.txt", "w");
    fclose(fp);
    fp = NULL;
    FILE *log_file = log_init("logs.txt");
    while (input != -1) {
        if (fscanf(stdin, "%d", &input) != 1) {
            logcat(log_file, "Invalid input", error);
            printf("n/a\n");
            input = 0;
            prev_input = 0;
        }
        switch (input) {
            case 1:
                readf(fp, path, log_file);
                prev_input = input;
                input = 0;
                break;
            case 2:
                if (prev_input == 1) {
                    appendf(fp, path, log_file);
                }
                prev_input = input;
                input = 0;
                break;
            case 3:
                encrypt_sesar(log_file);
                prev_input = input;
                input = 0;
                break;
            case 4:
                des(log_file);
                prev_input = input;
                input = 0;
            default:
                break;
        }
        clear();
    }
    log_close(log_file);
    return 0;
}

void output(FILE *fp) {
    char ch;
    fscanf(fp, "%c", &ch);
    while (!feof(fp)) {
        printf("%c", ch);
        fscanf(fp, "%c", &ch);
    }
    putchar('\n');
    fclose(fp);
}

void readf(FILE *fp, char *path, FILE *log_file) {
    fscanf(stdin, "%199s", path);
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("n/a\n");
        open_log(log_file, path, error);
    } else if (fgetc(fp) == EOF) {
        printf("n/a\n");
        open_log(log_file, path, warning);
    } else {
        open_log(log_file, path, info);
        read_log(log_file, path, info);
        fseek(fp, 0, 0);
        output(fp);
        close_log(log_file, path, info);
    }
}

void appendf(FILE *fp, char *path, FILE *log_file) {
    fp = fopen(path, "a");
    if (fp == NULL) {
        printf("n/a\n");
        open_log(log_file, path, error);
    } else {
        char tmp[BUFSIZE];
        tmp[0] = '\0';
        getchar();
        char c;
        int i = 0;
        while ((c = getchar()) != '\n' && i < 200) {
            tmp[i] = c;
            i++;
        }
        fprintf(fp, "%s", tmp);
        write_log(log_file, path, trace);
        fclose(fp);
        close_log(log_file, path, info);
        fp = fopen(path, "r");
        open_log(log_file, path, info);
        read_log(log_file, path, info);
        output(fp);
        close_log(log_file, path, info);
    }
}

void encrypt_sesar(FILE *log_file) {
    int shift = 0;
    if (scanf("%d", &shift) == 1) {
        char path1[16] = "ai_modules/m1.c";
        char path2[16] = "ai_modules/m1.h";
        rewrite(path1, path2, shift, log_file);
        char path3[16] = "ai_modules/m2.c";
        char path4[16] = "ai_modules/m2.h";
        rewrite(path3, path4, shift, log_file);
    } else {
        printf("n/a\n");
    }
}

void rewrite(char *path1, char *path2, int shift, FILE *log_file) {
    FILE *fp1, *fp2;
    fp1 = fopen(path1, "r");
    open_log(log_file, path1, info);
    fp2 = fopen(path2, "w");
    open_log(log_file, path2, info);
    copy(fp1, fp2);
    read_log(log_file, path1, trace);
    write_log(log_file, path2, trace);
    fclose(fp1);
    close_log(log_file, path1, info);
    fclose(fp2);
    close_log(log_file, path2, info);
    fp1 = fopen(path2, "r");
    open_log(log_file, path1, info);
    fp2 = fopen(path1, "w");
    open_log(log_file, path2, info);
    copy_shift(fp1, fp2, shift);
    read_log(log_file, path2, trace);
    encrypt_log(log_file, path1, debug);
    write_log(log_file, path1, trace);
    fclose(fp1);
    close_log(log_file, path1, info);
    fclose(fp2);
    close_log(log_file, path2, info);
    fp1 = fopen(path2, "w");
    open_log(log_file, path2, info);
    fclose(fp1);
    write_log(log_file, path2, warning);
    close_log(log_file, path1, info);
}

void copy(FILE *fp1, FILE *fp2) {
    char ch;
    fscanf(fp1, "%c", &ch);
    while (!feof(fp1)) {
        fputc(ch, fp2);
        fscanf(fp1, "%c", &ch);
    }
}

void copy_shift(FILE *fp1, FILE *fp2, int shift) {
    char ch;
    fscanf(fp1, "%c", &ch);
    while (!feof(fp1)) {
        fputc(ch + shift, fp2);
        fscanf(fp1, "%c", &ch);
    }
}

void des(FILE *log_file) {
    char tmp_path[100] = "ai_modules/tmp";
    char path1[100] = "ai_modules/m1.c";
    char path2[100] = "ai_modules/m2.c";
    FILE *fp1 = fopen(path1, "r");
    FILE *fp2 = fopen(path2, "r");
    if (fp1 == NULL) {
        printf("n/a\n");
        open_log(log_file, path1, error);
    } else if (fp2 == NULL) {
        printf("n/a\n");
        open_log(log_file, path2, error);
        fclose(fp1);
        close_log(log_file, path1, info);
    } else {
        char tmp[65];
        FILE *ftmp = fopen(tmp_path, "w");
        while (!feof(fp1)) {
            fgets(tmp, 64, fp1);
            fputs(crypt(tmp, "mega_key"), ftmp);
        }
        read_log(log_file, path1, trace);
        write_log(log_file, tmp_path, trace);
        encrypt_log(log_file, path1, debug);
        fclose(fp1);
        close_log(log_file, path1, info);
        remove(path1);
        write_log(log_file, path1, warning);
        fclose(ftmp);
        close_log(log_file, tmp_path, info);
        rename(tmp_path, path1);
        write_log(log_file, path1, trace);
        write_log(log_file, tmp_path, warning);
        ftmp = fopen(tmp_path, "w");
        while (!feof(fp2)) {
            fgets(tmp, 64, fp2);
            fputs(crypt(tmp, "ultre_key"), ftmp);
        }
        read_log(log_file, path2, trace);
        write_log(log_file, tmp_path, trace);
        encrypt_log(log_file, path2, debug);
        fclose(fp2);
        close_log(log_file, path2, info);
        remove(path2);
        write_log(log_file, path2, warning);
        fclose(ftmp);
        close_log(log_file, tmp_path, info);
        rename(tmp_path, path2);
        write_log(log_file, path2, trace);
        write_log(log_file, tmp_path, warning);
    }
}

void clear() {
    char c = getchar();
    while (c != '\n') {
        c = getchar();
    }
}