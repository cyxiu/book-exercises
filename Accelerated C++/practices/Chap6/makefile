CC = g++
CFLAGS = -g -Wall -std=c++11

default: str

str: str.o 
	$(CC) $(CFLAGS) -o str str.o

str.o: str.cpp 
	$(CC) $(CFLAGS) -c str.cpp

test: test.cpp
	$(CC) $(CFLAGS) -o test test.cpp

p34: p34.cpp
	$(CC) $(CFLAGS) -o p34 p34.cpp

p69: p69.cpp
	$(CC) $(CFLAGS) -o p69 p69.cpp

main: main.o grade5.o Student_info.o median.o fail.o grade.o extract.o
	$(CC) $(CFLAGS) -o main main.o grade5.o Student_info.o median.o fail.o grade.o extract.o

grade.o: grade.cpp grade5.h Student_info.h median.h
	$(CC) $(CFLAGS) -c grade.cpp

main.o: main.cpp grade5.h Student_info.h fail.o grade.h
	$(CC) $(CFLAGS) -c main.cpp

fail.o: fail.cpp fail.h grade5.h Student_info.h
	$(CC) $(CFLAGS) -c fail.cpp

grade5.o: grade5.cpp grade5.h Student_info.h median.h
	$(CC) $(CFLAGS) -c grade5.cpp

Student_info.o: Student_info.cpp Student_info.h
	$(CC) $(CFLAGS) -c Student_info.cpp

median.o: median.cpp median.h 
	$(CC) $(CFLAGS) -c median.cpp

extract.o: extract.cpp extract.h fail.h
	$(CC) $(CFLAGS) -c extract.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) main *.o *~


