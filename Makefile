
CC = g++
CFLAGS  = -g -Wall

build: all
	
 all : bubblesort.o compare_arg.o findlargest.o mergesort.o
	$(CC) $(CFLAGS) bubblesort.o -o bubblesort
	$(CC) $(CFLAGS) compare_arg.o -o compare_arg
	$(CC) $(CFLAGS) findlargest.o -o findlargest
	$(CC) $(CFLAGS) mergesort.o -o mergesort

bubblesort.o : bubblesort.cpp
	$(CC) $(CFLAGS) bubblesort.cpp -c

compare_arg.o : compare_arg.o
	$(CC) $(CFLAGS) compare_arg.cpp -c

findlargest.o : findlargest.o
	$(CC) $(CFLAGS) findlargest.cpp -c

mergesort.o : mergesort.o
	$(CC) $(CFLAGS) mergesort.cpp -c
