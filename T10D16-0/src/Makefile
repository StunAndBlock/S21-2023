CFLAGS = -Wall -Werror -Wextra

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

main.o: s21_string_test.c s21_string.h
	gcc $(CFLAGS) -c s21_string_test.c -o s21_string_test.o

s21_string.o: s21_string.c s21_string.h
	gcc $(CFLAGS) -c s21_string.c -o s21_string.o

clean:
	rm -rf *.o ../build/*

rebuild: clean all

strlen_tests: s21_string.o
	gcc $(CFLAGS) -c s21_string_test.c -DSTRLEN -o s21_string_test.o
	gcc s21_string.o s21_string_test.o -o ../build/Quest_1

strcmp_tests: s21_string.o
	gcc $(CFLAGS) -c s21_string_test.c -DSTRCMP -o s21_string_test.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_2

strcpy_tests: s21_string.o
	gcc $(CFLAGS) -c s21_string_test.c -DSTRCPY -o s21_string_test.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_3

strcat_tests: s21_string.o
	gcc $(CFLAGS) -c s21_string_test.c -DSTRCAT -o s21_string_test.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_4

strchr_tests: s21_string.o
	gcc $(CFLAGS) -c s21_string_test.c -DSTRCHR -o s21_string_test.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_5

strstr_tests: s21_string.o
	gcc $(CFLAGS) -c s21_string_test.c -DSTRSTR -o s21_string_test.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_6

strtok_tests: s21_string.o
	gcc $(CFLAGS) -c s21_string_test.c -DSTRTOK -o s21_string_test.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_7