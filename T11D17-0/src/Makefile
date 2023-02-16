CFLAGS = -Werror -Wall -Wextra

all: door_struct list_test stack_test

door_struct: dmanager_module.c door_struct.h
	gcc $(CFLAGS) dmanager_module.c -o ../build/Quest_1

clean:
	rm -rf *.o ../build/*

rebuild: clean all

list_test: list_test.o list.o
	gcc list_test.o list.o -o ../build/Quest_2

list.o: list.c list.h door_struct.h
	gcc $(CFLAGS) -c list.c -o list.o

list_test.o: list_test.c list.h door_struct.h
	gcc $(CFLAGS) -c list_test.c -o list_test.o

stack_test: stack_test.o stack.o 
	gcc $(CFLAGS) stack_test.o stack.o -o ../build/Quest_3

stack_test.o: stack_test.c stack.h
	gcc $(CFLAGS) -c stack_test.c -o stack_test.o

stack.o: stack.c stack.h
	gcc $(CFLAGS) -c stack.c -o stack.o