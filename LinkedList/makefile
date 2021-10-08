PGM=program5
LIST=list
CC=gcc

all : compile

compile:
	$(CC) -c $(LIST).c -o $(LIST).o
	$(CC) -c $(PGM).c -o $(PGM).o
	$(CC) $(PGM).o $(LIST).o -o $(PGM)

run:compile
	./$(PGM)

clean:
	rm *.o $(PGM)	

