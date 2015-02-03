CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main1 

grade.o: grade.cpp median.h
	$(CXX) $(CXXFLAGS) -c grade.cpp

Student_info.o: Student_info.cpp Student_info.h median.h
	$(CXX) $(CXXFLAGS) -c Student_info.cpp

main1.o: main1.cpp Student_info.h grade.h median.h Handle.h
	$(CXX) $(CXXFLAGS) -c main1.cpp

main1: main1.o grade.o Student_info.o 
	$(CXX) $(CXXFLAGS) main1.o grade.o Student_info.o -o main1

main2.o: main2.cpp Student_info.h grade.h median.h Ref_handle.h
	$(CXX) $(CXXFLAGS) -c main2.cpp

main2: main2.o grade.o Student_info.o 
	$(CXX) $(CXXFLAGS) main1.o grade.o Student_info.o -o main2

main3.o: main3.cpp Student_info.h grade.h median.h Ptr.h
	$(CXX) $(CXXFLAGS) -c main3.cpp

main3: main3.o grade.o Student_info.o 
	$(CXX) $(CXXFLAGS) main1.o grade.o Student_info.o -o main3

clean:
	rm -f *.o main1

test1: main1
	./main1 < ./mixed_grades

test2: main2
	./main2 < ./mixed_grades

test3: main3
	./main3 < ./mixed_grades

