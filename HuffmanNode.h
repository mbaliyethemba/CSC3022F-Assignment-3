#ifndef HUFFMANNODE_H_
#define HUFFMANNODE_H_

#include <memory>

namespace SHNMBA004{
	class HuffmanNode{
		private:
			//stored in node
			char character; 
			//frequency of occurence
			int frequency;
			//left node
			std::shared_ptr<HuffmanNode> left;
			//right node
			std::shared_ptr<HuffmanNode> right;
		
		public:
			HuffmanNode(); //constructor
			~HuffmanNode(); //destructor
			void setCharacter(char c);
			void setFrequency(int f);
			void setLeftChild(HuffmanNode lc);
			void setRightChild(HuffmanNode rc);
			char getCharacter();
			int getFrequency();
			HuffmanNode * getLeftChild();
			HuffmanNode * getRightChild();
			HuffmanNode (const HuffmanNode & rhs); //copy constructor
			HuffmanNode (HuffmanNode && rhs); //move constructor
			HuffmanNode & operator = (const HuffmanNode & rhs); //copy assignment
			HuffmanNode & operatoe = (HuffmanNode && rhs); //move assignment operator
	};
}

#endif /* HUFFMANNODE_H_ */
