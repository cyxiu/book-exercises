CXX = g++
CXXFLAGS = -Wall -std=c++11 #-I../../chapter04

all: Student_info

Student_info: Student_info.o
	$(CXX) $(CXXFLAGS) -o Student_info Student_info.o grade.o

Student_info.o: Student_info.cpp Student_info.h grade.h grade.cpp grade.o
	$(CXX) $(CXXFLAGS) -c Student_info.cpp

grade.o:	grade.cpp ../../chapter08/median.h Student_info.h
	$(CXX) $(CXXFLAGS) -c grade.cpp

