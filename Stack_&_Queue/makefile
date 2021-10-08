

compile:
	gcc -c stack.c -o stack.o
	gcc -c queue.c -o queue.o
	gcc -c main.c -o main.o
	gcc -o exe main.o stack.o queue.o


run:
	./exe

memcheck:
	valgrind ./exe


clean:
	rm -r stack.o queue.o main.o exe 
