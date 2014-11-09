all: mergeTest

mergeTest: main.o
	g++ main.o -o mergeTest

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm -rf *o mergeTest
