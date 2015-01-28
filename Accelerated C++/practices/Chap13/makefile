CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main0 13-1 13-2

grade.o: grade.cpp median.h
	$(CXX) $(CXXFLAGS) -c grade.cpp

Student_info.o: Student_info.cpp Student_info.h median.h
	$(CXX) $(CXXFLAGS) -c Student_info.cpp

main0.o: main0.cpp Student_info.h grade.h median.h
	$(CXX) $(CXXFLAGS) -c main0.cpp

main0: main0.o grade.o Student_info.o 
	$(CXX) $(CXXFLAGS) main0.o grade.o Student_info.o -o main0

13-1.o: 13-1.cpp Student_info.h grade.h median.h
	$(CXX) $(CXXFLAGS) -c 13-1.cpp

13-1: 13-1.o grade.o Student_info.o 
	$(CXX) $(CXXFLAGS) 13-1.o grade.o Student_info.o -o 13-1

13-2.o: 13-2.cpp Student_info.h grade.h median.h
	$(CXX) $(CXXFLAGS) -c 13-2.cpp

13-2: 13-2.o grade.o Student_info.o 
	$(CXX) $(CXXFLAGS) 13-2.o grade.o Student_info.o -o 13-2

clean:
	rm -f *.o main0

test: all
	./main0 < ./mixed_grades

test1: 13-1
	./13-1 < ./1grades

test2: all
	./main0 < ./mixed_grades_4
