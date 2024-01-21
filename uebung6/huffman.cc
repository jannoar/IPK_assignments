#include "huffman.hh"
#include <map>
#include <functional>
#include <queue>
#include <iostream>

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

void Huffman::generateHuffmanCodes(CodeMap& cm) {

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

HuffmanPointer Huffman::buildHuffmanTree(std::string& s)
{
  this->characterFrequencies = countCharacterFrequencies(s);
  // std::priority_queue<std::pair<int, char>> queue;
  std::priority_queue<WeightedHuffmanPointer, std::vector<WeightedHuffmanPointer>, HuffmanCompareFunction> queue;
  std::map<int, HuffmanPointer>::iterator it;
  for (it = characterFrequencies.begin(); it != characterFrequencies.end(); it++)
  {
    // queue.push(std::make_pair(it->second, it->first));
    WeightedHuffmanPointer p;
    p.first = it->first;
    // queue.push();
    //queue.push(std::make_pair(it->first, it->second));
  }
  //auto f = queue.top().first;
  //auto g = queue.top().second;
  
  while (!queue.empty()) {
    std::cout << queue.top().first << std::endl;
    std::cout << queue.top().second << std::endl;
    queue.pop();
  }

  HuffmanPointer a;
  return a;
}