# First rule is to make everything.
all: test

# Makes for specific data structures.
test: Build/test.o make-test

.PHONY: all test

# Data Structure compilers
Build/test.o: test.cpp Bag/Bag.h Bag/Bag.hxx
	g++ -Wall -g -IBag -c test.cpp -o Build/test.o

# Test Compiler
make-test: Build/test.o
	g++ -o test Build/test.o