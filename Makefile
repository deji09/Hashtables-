CC=g++
CFLAGS=-Wall -pedantic -Werror -g  -o
MAIN=realMaxTester.cpp
TESTER=test.o

test:	realMaxTester.cpp
	$(CC) $(CFLAGS) $(TESTER) $(MAIN)
all: 

# g++ -Wall -pedantic -g  -Werror test.csteveJobsTest2();