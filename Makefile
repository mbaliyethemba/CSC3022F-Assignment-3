.SUFFIXES:
.SUFFIXES: .cpp .o
CC=g++
CCFLAGS=-std=c++11
LIBS=-lm
SOURCES=HuffmanNode.cpp HuffmanTree.cpp

huffencode: HuffmanTree.o HuffmanNode.o driver.o
		$(CC) $(CCFLAGS) HuffmanTree.o HuffmanNode.o driver.o -o huffencode $(LIBS)
		
HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
				$(CC) $(CCFLAGS) HuffmanTree.cpp -c

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
				$(CC) $(CCFLAGS) HuffmanNode.cpp -c

				
driver.o: driver.cpp
		$(CC) $(CCFLAGS) driver.cpp -c

test: HuffmanTree.o HuffmanNode.o driver.o HuffmanUnitTesting.o
		$(CC) $(CCFLAGS) HuffmanTree.o HuffmanNode.o HuffmanUnitTesting.cpp -o huffenTest

clean: 
		@rm -f *.o
		@rm -f huffencode
