CC=gcc
AR=ar
FLAGS= -Wall -g
MS=mySort.o
MF=myFind.o

all: isort txtfind
isort: $(MS)
	$(CC) $(FLAGS) -o isort $(MS) 
txtfind: $(MF)
	$(CC) $(FLAGS) -o txtfind $(MF) 
mySort.o: mySort.c
	$(CC) $(FLAGS) -c mySort.c
myFind.o: myFind.c
	$(CC) $(FLAGS) -c myFind.c

.PHONY: clean all
clean:
	rm -f *.o *.so isort txtfind


