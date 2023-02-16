CFLAGS = -c -Wall -Werror -Wextra

all: build build_with_static build_with_dynamic

build: main.o data_io.o data_stat.o data_process.o decision.o
	gcc main.o data_io.o data_stat.o data_process.o decision.o -o ../../build/Quest_3

main.o: main_executable_module.c  
	gcc $(CFLAGS) main_executable_module.c -o main.o

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	gcc $(CFLAGS) ../data_libs/data_io.c -o data_io.o

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	gcc $(CFLAGS) ../data_libs/data_stat.c -o data_stat.o

data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	gcc $(CFLAGS) ../data_module/data_process.c -o data_process.o

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	gcc $(CFLAGS) ../yet_another_decision_module/decision.c -o decision.o

clean:
	rm -rf *.o ../../build/* ./libdata_stat.a ./libdata_process.so

rebuild: clean all

data_stat.a: data_stat.o
	ar -cr libdata_stat.a data_stat.o
	ranlib libdata_stat.a

build_with_static: main.o data_io.o data_process.o decision.o data_stat.a
	gcc main.o data_io.o data_process.o decision.o -o ../../build/Quest_5 -L. -ldata_stat

data_process.so: ../data_module/data_process.c ../data_libs/data_stat.c
	gcc -fPIC -c ../data_module/data_process.c ../data_libs/data_stat.c
	gcc -shared data_process.o data_stat.o -o libdata_process.so

build_with_dynamic: main.o data_io.o data_stat.o decision.o data_process.so data_process.o
	gcc main.o data_io.o data_stat.o data_process.o decision.o -L. -ldata_process -Wl,-rpath,. -o ../../build/Quest_6
	cp libdata_process.so ../../build/libdata_process.so