# # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
# BinaryTree Makefile
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Which compile t use
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
FLAGS = -O -g -Wall

# Program name
PROGRAM = BinaryTree
UNITTEST = UnitTest

# Source files
SOURCE = $(PROGRAM).c UnitTest.c

default: unittest

unittest: $(PROGRAM).c $(UNITTEST).c
	$(CC) $(CFLAGS) -o $(UNITTEST) $(SOURCE)

clean:
	-rm -f $(PROGRAM) $(UNITTEST)
