CFLAGS = -Werror -Wextra -Wall -fsanitize=address
DIR = ../build/

all: state_sort state_search clear_state

clean:
	rm $(DIR)*

rebuild: clean all

state_sort: state_sort.c date.c date.h
	gcc $(CFLAGS) state_sort.c date.c -o $(DIR)Quest_1

state_search: state_search.c
	gcc $(CFLAGS) state_search.c date.c -o $(DIR)Quest_2

clear_state: clear_state.c date.c date.h
	gcc $(CFLAGS) clear_state.c date.c -o $(DIR)Quest_3