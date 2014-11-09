all: mergeTest

mergeTest: main.o mergeSort.o
	g++ main.o mergeSort.o -o mergeTest

main.o: main.cpp
	g++ -c main.cpp

mergeSort.o: mergeSort.h
	g++ -c mergeSort.h mergeSort.cpp

clean: 
	rm -rf *o mergeTest
