#include "print_module.h"

void print_char(char ch) { putchar(ch); }

void print_log(void (*print)(char), char* message) {
    time_t raw_time;
    struct tm* info;
    time(&raw_time);
    info = localtime(&raw_time);
    int len = strlen(Log_prefix);
    for (int i = 0; i < len; i++) {
        print(Log_prefix[i]);
    }
    print(' ');
    int hour = info->tm_hour;
    int min = info->tm_min;
    int sec = info->tm_sec;
    char tmp = 0;
    if (hour / 10 > 0) {
        tmp = (char)(hour / 10) + '0';
        print(tmp);
        tmp = (char)(hour % 10) + '0';
        print(tmp);
    } else {
        print('0');
        tmp = (char)(hour % 10) + '0';
        print(tmp);
    }
    print(':');
    if (min / 10 > 0) {
        tmp = (char)(min / 10) + '0';
        print(tmp);
        tmp = (char)(min % 10) + '0';
        print(tmp);
    } else {
        print('0');
        tmp = (char)(min % 10) + '0';
        print(tmp);
    }
    print(':');
    if (sec / 10 > 0) {
        tmp = (char)(sec / 10) + '0';
        print(tmp);
        tmp = (char)(sec % 10) + '0';
        print(tmp);
    } else {
        print('0');
        tmp = (char)(sec % 10) + '0';
        print(tmp);
    }
    print(' ');
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        print(message[i]);
    }
}