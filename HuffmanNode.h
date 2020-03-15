#ifndef HUFFMANNODE_H_
#define HUFFMANNODE_H_

#include <memory>

namespace SHNMBA004{
	class HuffmanNode{
		private:
			//stored in node
			char character; 
			//frequency of occurence
			int freq;
			//left node
			std::shared_ptr<HuffmanNode> left;
			//right node
			std::shared_ptr<HuffmanNode> right;
	}
}

#endif /* HUFFMANNODE_H_ */
