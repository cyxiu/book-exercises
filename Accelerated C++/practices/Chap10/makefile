CXX = g++
CXXFLAGS = -Wall -std=c++11 #-I../../chapter04

all: test

test: test.cpp letter_grade.o
	$(CXX) $(CXXFLAGS) -o test test.cpp letter_grade.o

#letter_grade: letter_grade.o
	#$(CXX) $(CXXFLAGS) -o letter_grade letter_grade.o

letter_grade.o: letter_grade.cpp letter_grade.h
	$(CXX) $(CXXFLAGS) -c letter_grade.cpp letter_grade.h
