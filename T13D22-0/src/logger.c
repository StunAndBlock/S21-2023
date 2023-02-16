#include "logger.h"

FILE *log_init(char *filename) {
    FILE *log_file = fopen(filename, "a");
    return log_file;
}

void logcat(FILE *log_file, char *message, log_level level) {
    level_parse(log_file, level);
    time_t raw_time;
    struct tm *info;
    time(&raw_time);
    info = localtime(&raw_time);
    int hour = info->tm_hour;
    int min = info->tm_min;
    int sec = info->tm_sec;
    fprintf(log_file, "%d:%d:%d %s\n", hour, min, sec, message);
}

void log_close(FILE *log_file) { fclose(log_file); }

void level_parse(FILE *log_file, log_level level) {
    switch (level) {
        case 0:
            fprintf(log_file, "%s ", "DEBUG");
            break;
        case 1:
            fprintf(log_file, "%s ", "TRACE");
            break;
        case 2:
            fprintf(log_file, "%s ", "INFO");
            break;
        case 3:
            fprintf(log_file, "%s ", "WARNING");
            break;
        case 4:
            fprintf(log_file, "%s ", "ERROR");
            break;
        default:
            break;
    }
}

void open_log(FILE *log_file, char *path, int flag) {
    char buf[BUFSIZE];
    strcpy(buf, "File ");
    strcat(buf, path);
    if (flag == info) {
        strcat(buf, " opened");
    } else if (flag == error) {
        strcat(buf, " empty");
    } else if (flag == warning) {
        strcat(buf, " not opened");
    }
    logcat(log_file, buf, flag);
}

void close_log(FILE *log_file, char *path, int flag) {
    char buf[BUFSIZE];
    strcpy(buf, "File ");
    strcat(buf, path);
    strcat(buf, " closed");
    logcat(log_file, buf, flag);
}

void read_log(FILE *log_file, char *path, int flag) {
    char buf[BUFSIZE];
    strcpy(buf, "File ");
    strcat(buf, path);
    strcat(buf, " read");
    logcat(log_file, buf, flag);
}

void write_log(FILE *log_file, char *path, int flag) {
    char buf[BUFSIZE];
    strcpy(buf, "File ");
    strcat(buf, path);
    if (flag == trace) {
        strcat(buf, " updated");
    } else if (flag == warning) {
        strcat(buf, " cleared");
    }
    logcat(log_file, buf, flag);
}

void encrypt_log(FILE *log_file, char *path, int flag) {
    char buf[BUFSIZE];
    strcpy(buf, "File ");
    strcat(buf, path);
    strcat(buf, " encrypted");
    logcat(log_file, buf, flag);
}