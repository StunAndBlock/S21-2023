#include "date.h"

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(date); }

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

date read_record_from_file(FILE *fp, int index) {
    int offset = index * sizeof(date);
    fseek(fp, offset, SEEK_SET);
    date record;
    fread(&record, sizeof(date), 1, fp);
    rewind(fp);
    return record;
}

void write_record_in_file(FILE *pfile, const date *record_to_write, int index) {
    int offset = index * sizeof(date);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(date), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}