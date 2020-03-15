//Student Name: Mbaliyethemba Shangase
//Student Number: SHNMBA004
//Due Date: 16/03/2020
//Assignment 3

#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "HuffmanTree.h"

int main(int argc, char* argv[]){
	using namespace std;
	SHNMBA004::HuffmanTree huffmanTree = SHNMBA004::HuffmanTree();
	std::unordered_map<char,int> map;
	string inputFilePath = string(argv[1]);
	string outputFilePath = string(argv[2]);
	ifstream input(inputFilePath);
	char c;
	if(input.is_open()){
		while(input.get(c)){
			map[c] += 1;
		}
		
		huffmanTree.CreateTree(map);
		cout << inputFilePath << " " << string(argv[2]) << endl;
		huffmanTree.compression(inputFilePath, outputFilePath);
	}
	input.close();
}
