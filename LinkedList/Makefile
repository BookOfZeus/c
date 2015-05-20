# # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
# LinkedList Makefile
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Which compile t use
CC = gcc

# compiler flags:
# -I	Include path
# -O	slow compile but fast execution
# -g	adds debugging information to the executable file
# -Wall turns on most, but not all, compiler warnings
FLAGS = -I../. -O -g -Wall

# Program name
PROGRAM = LinkedList
UNITTEST = UnitTest
PROGRAM_TEST = $(PROGRAM)_$(UNITTEST)

# Source files
SOURCE = $(PROGRAM).c $(PROGRAM_TEST).c ../$(UNITTEST).c

default: unittest

unittest: $(PROGRAM).c ../$(UNITTEST).c
	$(CC) $(CFLAGS) -o $(PROGRAM_TEST) $(SOURCE)

clean:
	-rm -f $(PROGRAM) $(UNITTEST) $(PROGRAM_TEST)
