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
	
	char HuffmanNode::getCharacter(){
		return character;
	}
	
	int HuffmanNode::getFrequency(){
		return frequency;
	}
	
	HuffmanNode * HuffmanNode::getLeftChild(){
		return left.get();
	}
	
	HuffmanNode * HuffmanNode::getRightChild(){
		return right.get();
	}
	
	//copy constructor
	HuffmanNode::HuffmanNode (const HuffmanNode & rhs){
		character = rhs.character;
		frequency = rhs.frequency;
		left = rhs.left;
		right = rhs.right;
	}
	
	//move constructor
	HuffmanNode::HuffmanNode(HuffmanNode && rhs){
		character = rhs.character;
		this->frequency = rhs.frequency;
		left = rhs.left;
		right = rhs.right;
		rhs.left = nullptr;
		rhs.right = nullptr;
		rhs.frequency = -1;
	}
	
	//copy assignment
	HuffmanNode & HuffmanNode::operator = (const HuffmanNode & rhs){
		if(this != &rhs){
			character = rhs.character;
			frequency = rhs.frequency;
			left = rhs.left;
			right = rhs.right;
		}
		return * this;
	}
	
	//move assignment
	HuffmanNode & HuffmanNode::operator = (HuffmanNode && rhs){
		if(this != &rhs){
			character = std::move(rhs.character);
			frequency = rhs.frequency;
			left = rhs.left;
			right = rhs.right;
			rhs.left = nullptr;
			rhs.right = nullptr;
			rhs.frequency = -1;
		}
		return * this;
	}
	
	
}
