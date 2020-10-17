# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES= projectTest, tests

all: ${BINARIES}

projectTest: project1.o #projectTest.o project1.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./projectTest
	

clean:
	/bin/rm -f ${BINARIES} *.o