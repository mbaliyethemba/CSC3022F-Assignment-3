//Student Name: Mbaliyethemba Shangase
//Student Number: SHNMBA004
//Due Date: 16/03/2020
//Assignment 3

#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <queue>
#include <iomanip>
#include <fstream>

namespace SHNMBA004{
	
	//constructor
	HuffmanTree::HuffmanTree(){
		std::shared_ptr<HuffmanNode> root = nullptr;
	}
	
	//destructor
	HuffmanTree::~HuffmanTree(){
		root = nullptr;
	}
	
	void HuffmanTree::CreateTree(std::unordered_map<char,int> & map){
		using namespace std;
		for(auto iterator : map){
			HuffmanNode node;
			shared_ptr<HuffmanNode> nPtr = make_shared<HuffmanNode>(node);
			node.setCharacter(iterator.first);
			node.setFrequency(iterator.second);
			pQ.push(node);
		}
		
		while(pQ.size() > 1){
			HuffmanNode A = pQ.top();
			pQ.pop();
			HuffmanNode B = pQ.top();
			pQ.pop();
			HuffmanNode total;
			total.setCharacter(0);
			total.setFrequency(A.getFrequency() + B.getFrequency());
			total.setLeftChild(A);
			total.setRightChild(B);
			pQ.push(total);
		}
		root = make_shared<HuffmanNode> (pQ.top());
		traverse(root.get(),"");
	}
	
	void HuffmanTree::traverse(HuffmanNode * current,std::string bitString){
		using namespace std;
		if(current){
			traverse(current->getLeftChild(),bitString+"0");
			if(current->getCharacter() !=0){
				cout<< current -> getCharacter() << " the bitstream is " << bitString << endl;
				cTable[current->getCharacter()] = bitString;
			}
			traverse(current->getRightChild(),bitString+"1");
		}
	}
	
	void HuffmanTree::compression(std::string inputFile, std::string outputFile){
		using namespace std;
		int nChars;
		int nOneZero;
		ofstream output;
		ofstream outputa;
		output.open(outputFile + ".txt");
		outputa.open(outputFile + ".hdr");
		ifstream input(inputFile);
		char c;
		
		while(input.get(c)){
			nChars++;
			string bit = cTable[c].c_str();
			output << bit;
			nOneZero += bit.length();
			cout << bit << ": " << bit.length() << endl;
		}
		input.close();
		outputa << "Size: " << cTable.size() << endl;
		for(auto iterator : cTable){
			outputa << iterator.first << ": " << iterator.second << endl;
		}
		output.close();
		outputa.close();
		double compression = nOneZero / (nChars * 8);
		cout << "Compression ratio: " << compression << endl;
	}
	
	void HuffmanTree::Display(HuffmanNode * current,int indent){
		using namespace std;
		if(current != nullptr){
			Display(current->getRightChild(), indent + 4);
			if(indent > 0){
				cout<<setw(indent)<<" ";
			}
			cout << current->getFrequency() << "," << current->getCharacter() << endl;
			Display(current->getLeftChild(), indent + 4);
		}
	}
	
	// Generate and return a map of all the characters in the input file
	std::unordered_map<char, int> HuffmanTree::getCharMap(std::string inputFileName, std::vector<std::string> *inputStrings){
		std::unordered_map<char,int> charMap;
		std::ifstream infile(inputFileName);
		std::string line;
		
		//read in and count the frequency each character
		if(infile.is_open()){
			while(getline(infile, line)){
				inputStrings -> push_back(line);
				for(char character: line){
					if (charMap.find(character) != charMap.end()){
						charMap.at(character) += 1;
					}
					else{
						charMap.insert({character, 1});
					}
				}
			}
			infile.close();
		}
		else{
			std::cout << "Can't open file" << std::endl;
		}
		return charMap;
	}
}
