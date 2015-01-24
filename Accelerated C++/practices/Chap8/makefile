CXX = g++
CXXFLAGS = -Wall -std=c++11 #-I../../chapter04

all: median split 8-1

median: median.o
	$(CXX) $(CXXFLAGS) -o median median.o

median.o: median.cpp
	$(CXX) $(CXXFLAGS) -c median.cpp

split: split.o
	$(CXX) $(CXXFLAGS) -o split split.o

split.o: split.cpp
	$(CXX) $(CXXFLAGS) -c split.cpp

Student_info.o: ../../chapter04/Student_info.cc ../../chapter04/Student_info.h
	$(CXX) $(CXXFLAGS) -c ../../chapter04/Student_info.cc

median-old.o: ../../chapter04/median.cc ../../chapter04/median.h
	$(CXX) $(CXXFLAGS) -o median-old.o -c ../../chapter04/median.cc

grade_check.o: ../../chapter06/grade_check.cc
	$(CXX) $(CXXFLAGS) -c ../../chapter06/grade_check.cc

8-1: 8-1-grade-analysis.o Student_info.o 8-1-analysis.o grade.o median-old.o grade_check.o
	$(CXX) $(CXXFLAGS) -o 8-1 8-1-analysis.o Student_info.o median-old.o 8-1-grade-analysis.o grade.o grade_check.o

8-1-grade-analysis.o: 8-1-grade-analysis.cpp
	$(CXX) $(CXXFLAGS) -c 8-1-grade-analysis.cpp

8-1-analysis.o: 8-1-analysis.cpp 8-1-analysis.h
	$(CXX) $(CXXFLAGS) -c 8-1-analysis.cpp

8-2: 8-2.o
	$(CXX) $(CXXFLAGS) -o 8-2 8-2.o

8-2.o: 8-2.cpp 8-2.h
	$(CXX) $(CXXFLAGS) -c 8-2.cpp

8-4: 8-4.o
	$(CXX) $(CXXFLAGS) -o 8-4 8-4.o

8-4.o: 8-4.cpp 8-4.h
	$(CXX) $(CXXFLAGS) -c 8-4.cpp

8-6: 8-6.o
	$(CXX) $(CXXFLAGS) -o 8-6 8-6.o

8-6.o: 8-6.cpp 
	$(CXX) $(CXXFLAGS) -c 8-6.cpp

grade.o: ../../chapter04/grade.cc
	$(CXX) $(CXXFLAGS) -c ../../chapter04/grade.cc

test: all
	./median < median.txt
	./split < split.txt
	./8-1 <../../data/grades


clobber:
	rm -f *.o *.exe core split_main main3 analysis 8-1
    
