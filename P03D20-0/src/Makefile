CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD_PATH = ../build/

all: main

main: graph.c calculate.o draw.o dynamic.o parse.o
	$(CC) $(CFLAGS) graph.c calculate.o draw.o dynamic.o parse.o -o $(BUILD_PATH)graph

calculate.o: calculate.c calculate.h
	$(CC) $(CFLAGS) -c calculate.c

draw.o: draw.c draw.h
	$(CC) $(CFLAGS) -c draw.c

dynamic.o: dynamic.c dynamic.h
	$(CC) $(CFLAGS) -c dynamic.c

parse.o: parse.c parse.h
	$(CC) $(CFLAGS) -c parse.c

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so $(BUILD_PATH)graph