#pragma once 
#include <map>
#include <functional>
#include <queue>
#include "tree.hh"
#include <memory>

using HuffmanNode = BinaryTreeNode<char>;
using HuffmanPointer = std::shared_ptr<HuffmanNode>;
using WeightedHuffmanPointer = std::pair<int, HuffmanPointer>;
using BitVector = std::vector<bool>;
using CodeMap = std::map<BitVector, char>;
using HuffmanCompareFunction = std::function<bool(WeightedHuffmanPointer, WeightedHuffmanPointer)>;

class Huffman
{
private:
    std::map<char,int> characterFrequency;
    HuffmanPointer hp;
    HuffmanPointer buildHuffmanTree(const std::string& s);
public:
    Huffman(const std::string& s);
    std::map<char, int> countCharacterFrequency(const std::string& s);
    template<typename T>
    bool isWeightGreater(std::pair<int, T>& a, std::pair<int, T>& b);
};