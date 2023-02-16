#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "log_levels.h"

#define BUFSIZE 200

FILE *log_init(char *filename);
void logcat(FILE *log_file, char *message, log_level level);
void log_close(FILE *log_file);
void level_parse(FILE *log_file, log_level level);
void open_log(FILE *log_file, char *path, int flag);
void close_log(FILE *log_file, char *path, int flag);
void read_log(FILE *log_file, char *path, int flag);
void write_log(FILE *log_file, char *path, int flag);
void encrypt_log(FILE *log_file, char *path, int flag);

#endif