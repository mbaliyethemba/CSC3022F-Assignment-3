//Student Name: Mbaliyethemba Shangase
//Student Number: SHNMBA004
//Due Date: 16/03/2020
//Assignment 3

#include "HuffmanNode.h"
#include <memory>

namespace SHNMBA004{
	//Node Constructor
	HuffmanNode::HuffmanNode(){
		character = 0;
		frequency = 0;
		std::shared_ptr<HuffmanNode> left = nullptr;
		std::shared_ptr<HuffmanNode> right = nullptr;
	}
	
	//Destructor
	HuffmanNode::~HuffmanNode(){
		left = nullptr;
		right = nullptr;
		frequency = -1;
	}
	
	void HuffmanNode::setCharacter(char c){
		character = c;
	}
	
	void HuffmanNode::setFrequency(int f){
		frequency = f;
	}
	
	void HuffmanNode::setLeftChild(HuffmanNode lc){
		left = std::make_shared<HuffmanNode>(lc);
	}
	
	void HuffmanNode::setRightChild(HuffmanNode rc){
		right = std::make_shared<HuffmanNode>(rc);
	}
}
