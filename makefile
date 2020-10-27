# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field -g

BINARIES=project1.out

all: ${BINARIES}

project1.out: project1-test.o project1.o
		${CXX} $^ -o $@

tests: ${BINARIES}
		./project1.out "insert jacob, insert andrea, insert jazzy, insert missipppi, insert gum, insert chapstick, insert paper, insert zebra, insert computer, insert goooooooblle, insert bigbooooty, delete jazzy, delete jacob, lookup bigbooooty, range_search computer to zebra"

clean:
		/bin/rm -f ${BINARIES} *.o