#ifndef DATE_H
#define DATE_H

#include <stdio.h>

typedef struct Date {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int id;
    int code;
} date;

int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
date read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const date *record_to_write, int index);

#endif  // DATE_H