#pragma once 
#include <map>
#include <functional>
#include <queue>
#include "tree.hh"
#include <memory>

// (b)
using HuffmanNode = BinaryTreeNode<char>;
using HuffmanPointer = std::shared_ptr<HuffmanNode>;
using WeightedHuffmanPointer = std::pair<int, HuffmanPointer>;
using BitVector = std::vector<bool>;
using CodeMap = std::map<BitVector, char>;
using HuffmanCompareFunction = std::function<bool(WeightedHuffmanPointer, WeightedHuffmanPointer)>;


class Huffman
{
private:
    // (d)
    HuffmanPointer _nodePointer;
    CodeMap _cm;

    std::map<char, int> characterFrequencies;
    //(e)
    HuffmanPointer buildHuffmanTree(std::string& s);
    // (f)
    void generateHuffmanCodes(CodeMap& cm);
public:
    Huffman(std::string& s);
    // (c)
    template<typename T>
    bool isWeightGreater(std::pair<int, T>& a, std::pair<int, T>& b);
    // (i)
    void printHuffmanCodes();
    // (j)
    void encode(const std::string& s, BitVector& bv);
    // (k)
    std::string decode(const BitVector& bv);
};