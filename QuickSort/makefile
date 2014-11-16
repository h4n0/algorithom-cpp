all: QuickTest

QuickTest: main.o
	g++ main.o -o QuickTest

# -g is debug symbol for gdb
main.o: main.cpp
	g++ -g -c main.cpp

clean: 
	rm -rf *o QuickTest
