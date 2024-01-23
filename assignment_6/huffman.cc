#include "huffman.hh"
#include <map>
#include <functional>
#include <queue>
#include <iostream>
#include <memory>

// (h)
bool sortByCode(const std::pair<char, BitVector>& p1, const std::pair<char, BitVector>& p2) {
  if (p1.second.size() < p2.second.size()) {
    return true;
  } else if (p1.second.size() > p2.second.size()) {
    return false;
  } else {
    return p1.second < p2.second; 
  }
}

// (i)
std::string boolVectorToString(const BitVector& bv) {
  std::string s; 
  for (auto v : bv) 
    v == false ? (s += "0") : (s += "1");
  return s;
}

void Huffman::printHuffmanCodes() {
}

// (j)
void Huffman::encode(const std::string& s, BitVector& bv) {
}

// (k)
std::string Huffman::decode(const BitVector& bv) {
  return "Hello";
}

// (g)
Huffman::Huffman(std::string& s)
{
  _nodePointer = buildHuffmanTree(s);
  generateHuffmanCodes(_cm);
}

std::map<char, int> countCharacterFrequencies(std::string& s)
{
  std::map<char, int> freq;
  for (char ch: s)
	  freq[ch]++;
  return freq;
}

// (e)
template<typename T>
bool Huffman::isWeightGreater(std::pair<int, T>& a, std::pair<int, T>& b)
{
  return a.first > b.first ? true : false;
}

void gHMC(HuffmanPointer aktuellerKnoten, BitVector aktStelleVector, CodeMap& cm)
{
    if(aktuellerKnoten->isLeaf()){ //Ende/Blatt erreicht
        cm.insert({aktStelleVector, aktuellerKnoten->getValue()});

    }else{//es geht weiter

        //links = 0/false
        aktStelleVector.push_back(false);
        gHMC(aktuellerKnoten->getLeft(), aktStelleVector, cm);

        aktStelleVector.pop_back();//

        //rechts = 1/true
        aktStelleVector.push_back(true);
        gHMC(aktuellerKnoten->getRight(), aktStelleVector, cm);
    }
}

void Huffman::generateHuffmanCodes(CodeMap& cm)
{
    BitVector emptyVec; //leerer Bitvector
    gHMC(this->_nodePointer, emptyVec, cm);
    CodeMap::iterator it;
    for (it = cm.begin(); it != cm.end(); it++)
    {
      auto x = it->first;
    }
}

HuffmanPointer Huffman::buildHuffmanTree(std::string& s)
{
  this->characterFrequencies = countCharacterFrequencies(s);
  std::priority_queue<WeightedHuffmanPointer, std::vector<WeightedHuffmanPointer>, std::greater<WeightedHuffmanPointer>> queue;
  std::map<char, int>::iterator it;
  for (it = characterFrequencies.begin(); it != characterFrequencies.end(); it++)
  {
    queue.push(std::make_pair(it->second, std::make_shared<HuffmanNode>(HuffmanNode(it->first))));
  }
  while (queue.size() != 1)
  {
    WeightedHuffmanPointer a = queue.top();
    queue.pop();
    WeightedHuffmanPointer b = queue.top();
    queue.pop();
    queue.push(std::make_pair(a.first+b.first, std::make_shared<HuffmanNode>(HuffmanNode(a.second, b.second, ' '))));
  }
  HuffmanPointer a = queue.top().second;
  return a;
}