CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.o llrec.o
	g++ -g -Wall --std=c++11 llrec-test.o llrec.o -o llrec-test
llrec-test.o: llrec-test.cpp llrec.cpp llrec.h
	g++ -g -c -Wall --std=c++11 llrec-test.cpp llrec.cpp
llrec.o: llrec.cpp llrec.h
	g++ -g -c -Wall --std=c++11 llrec.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 