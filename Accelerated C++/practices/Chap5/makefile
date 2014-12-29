#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: main

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
main: main.o grade.o Student_info.o median.o fail.o
	$(CC) $(CFLAGS) -o main main.o grade.o Student_info.o median.o fail.o

main.o: main.cpp grade.h Student_info.h fail.o
	$(CC) $(CFLAGS) -c main.cpp

fail.o: fail.cpp fail.h grade.h Student_info.h
	$(CC) $(CFLAGS) -c fail.cpp

grade.o: grade.cpp grade.h Student_info.h median.h
	$(CC) $(CFLAGS) -c grade.cpp

Student_info.o: Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) -c Student_info.cpp

median.o: median.cpp median.h 
	$(CC) $(CFLAGS) -c median.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) main *.o *~


