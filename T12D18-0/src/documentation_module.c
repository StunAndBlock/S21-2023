#include "documentation_module.h"

int validate(char *data) { return strcmp(data, Available_document); }

int *check_available_documentation_module(int (*validate)(char *), int document_count, ...) {
    va_list args;
    va_start(args, document_count);
    int *result = (int *)malloc(sizeof(document_count));
    for (int i = 0; i < document_count; i++) {
        result[i] = (validate(va_arg(args, char *))) ? 0 : 1;
    }
    va_end(args);
    return result;
}

void output(int *mask, int n, ...) {
    va_list args;
    va_start(args, n);
    char res[12];
    for (int i = 0; i < n; i++) {
        char *doc = va_arg(args, char *);
        if (mask[i]) {
            strcpy(res, "available");
        } else {
            strcpy(res, "unavailable");
        }
        printf("[%-15s : %s]\n", doc, res);
    }
    va_end(args);
}