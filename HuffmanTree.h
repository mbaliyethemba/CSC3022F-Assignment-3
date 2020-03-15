#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_
#include "HuffmanNode.h"
#include <memory>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <string>

namespace SHNMBA004{
	class Compare{
		public:
			bool operator()(HuffmanNode a, HuffmanNode b){
				if(a.getFrequency()>= b.getFrequency()){
					return true;
				}
				else{
					return false;
				}
			}
	};
	class HuffmanTree{
		private:
			std::shared_ptr<HuffmanNode> root;
			std::priority_queue<HuffmanNode, std::vector<HuffmanNode>,Compare> pQ;
			std::unordered_map<char, std::string> cTable;
			
		public:
			HuffmanTree(); //constructor
			~HuffmanTree(); //destructor
			void CreateTree(std::unordered_map<char,int> & map);
			void Display(HuffmanNode * current, int indent);
			void traverse(HuffmanNode * current, std::string bitString);
			void compression(std::string inputFile, std::string outputFile);
			static std::unordered_map<char,int> getCharMap(std::string inputFilename, std::vector<std::string> *inputStrings);
	};
}

#endif /*HUFFMANTREE_H_ */
