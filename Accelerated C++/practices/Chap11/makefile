CXX = g++
CXXFLAGS = -Wall -std=c++11

default: all

testfile: testfile.cpp
	$(CXX) $(CXXFLAGS) -o testfile testfile.cpp

Student_info.o:	Student_info.cc Vec.h Student_info.h

grade.o:	grade.cc Vec.h Student_info.h median.h

main3.o: 	main3.cc grade.h median.h Student_info.h

main3:   	main3.o grade.o Student_info.o
	$(CXX) $(CXXFLAGS) -o main3 main3.o grade.o Student_info.o

all:        main3

test:       all
	./main3 < ../../data/grades
