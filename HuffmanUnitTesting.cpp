#include "HuffmanTree.h"
#include "HuffmanNode.h"
#define CATCH_CONFIG_MAIN
#include <unordered_map>
#include <vector>
#include <string>
#include "catch.hpp"

using namespace std;
using namespace SHNMBA004;

//Test Cases
TEST_CASE("Huffman tree building and destroying - all methods","[HuffmanTree]"){
	SHNMBA004::HuffmanTree huffmanTree = SHNMBA004::HuffmanTree();
	std::string file = "test.txt";
	SECTION("Testing letter frequency table"){
		std::unordered_map<char,int> map;
		ifstream input(file);
		char c;
		if(input.is_open()){
			while(input.get(c)){
				map[c] += 1;
				}
			huffmanTree.CreateTree(map);
		}
		input.close();
		//Check if letter frequency table is correct
        REQUIRE( int(map.at('H')) == 1);
        REQUIRE( int(map.at('e')) == 2);
        REQUIRE( int(map.at('l')) == 3);
        REQUIRE( int(map.at('o')) == 2);
        REQUIRE( int(map.at('W')) == 1);
        REQUIRE( int(map.at('r')) == 1);
        REQUIRE( int(map.at('d')) == 1);
        REQUIRE( int(map.at('.')) == 1);
	}
	
	SECTION("NodeQueue correct, [node, queue]"){
		std::unordered_map<char,int> map;
		std::priority_queue<HuffmanNode, std::vector<HuffmanNode>,Compare> pQ;
		ifstream input(file);
		char c;
		if(input.is_open()){
			while(input.get(c)){
				map[c] += 1;
				}
			huffmanTree.CreateTree(map);
		}
		
		for(auto iterator : map){
			HuffmanNode node;
			shared_ptr<HuffmanNode> nPtr = make_shared<HuffmanNode>(node);
			node.setCharacter(iterator.first);
			node.setFrequency(iterator.second);
			pQ.push(node);
		}
		input.close();
		REQUIRE(!pQ.empty());
		REQUIRE(pQ.size() == 9);
		HuffmanNode A = pQ.top();
		REQUIRE(A.getFrequency() == 1);
	}
	
	SECTION("Node structure correct, [tree]"){;
		std::unordered_map<char,int> map;
		std::priority_queue<HuffmanNode, std::vector<HuffmanNode>,Compare> pQ;
		ifstream input(file);
		char c;
		if(input.is_open()){
			while(input.get(c)){
				map[c] += 1;
				}
			huffmanTree.CreateTree(map);
		}
		for(auto iterator : map){
			HuffmanNode node;
			shared_ptr<HuffmanNode> nPtr = make_shared<HuffmanNode>(node);
			node.setCharacter(iterator.first);
			node.setFrequency(iterator.second);
			pQ.push(node);
		}
		input.close();
		HuffmanNode root = pQ.top();
		REQUIRE(root.getFrequency() == 12);
		REQUIRE(root.getCharacter() == '$');
	}
	
	SECTION("map has correct size after reading file"){
		std::unordered_map<char,int> map;
		ifstream input(file);
		char c;
		if(input.is_open()){
			while(input.get(c)){
				map[c] += 1;
				}
			huffmanTree.CreateTree(map);
		}
		input.close();
		REQUIRE(map.size()==9);
	}
}
