CFLAGS = -Werror -Wall -Wextra
DIR = ../build/

all: cipher logging_cipher

clean:
	rm -rf *.o $(DIR)* *.txt

rebuild: clean all

cipher: cipher.c
	gcc $(CFLAGS) cipher.c logger.c -o $(DIR)cipher

logging_cipher: cipher.c logger.c logger.h
	gcc $(CFLAGS) cipher.c logger.c -o $(DIR)logging_cipher