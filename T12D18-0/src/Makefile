CFLAGS = -Werror -Wextra -Wall

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test;

clean:
	rm -rf *.o ../build/*

rebuild: clean all

print_module: print_module.o
	gcc $(CFLAGS) -c main_module_entry_point.c -DPRINT -o main_module_entry_point.o
	gcc $(CFLAGS) main_module_entry_point.o print_module.o -o ../build/Quest_1

print_module.o: print_module.c print_module.h
	gcc $(CFLAGS) -c print_module.c -o print_module.o
	
documentation_module: documentation_module.o
	gcc $(CFLAGS) -c main_module_entry_point.c -DCHECK -o main_module_entry_point.o
	gcc $(CFLAGS) main_module_entry_point.o documentation_module.o -o ../build/Quest_2

documentation_module.o: documentation_module.c documentation_module.h
	gcc $(CFLAGS) -c documentation_module.c -o documentation_module.o

bst_create_test: bst_create_test.o bst.o
	gcc $(CFLAGS) bst_create_test.o bst.o -o ../build/Quest_3

bst.o: bst.c bst.h
	gcc $(CFLAGS) -c bst.c -o bst.o

bst_create_test.o: bst_create_test.c bst.h
	gcc $(CFLAGS) -c bst_create_test.c -o bst_create_test.o

bst_insert_test: bst_insert_test.o bst.o
	gcc $(CFLAGS) bst_insert_test.o bst.o -o ../build/Quest_4

bst_insert_test.o: bst_insert_test.c bst.h
	gcc $(CFLAGS) -c bst_insert_test.c -o bst_insert_test.o

bst_traverse_test: bst_traverse_test.o bst.o
	gcc $(CFLAGS) bst_traverse_test.o bst.o -o ../build/Quest_5

bst_traverse_test.o: bst_traverse_test.c bst.h
	gcc $(CFLAGS) -c bst_traverse_test.c -o bst_traverse_test.o