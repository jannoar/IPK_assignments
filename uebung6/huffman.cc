#include "huffman.hh"
#include <map>
#include <functional>
#include <queue>
#include <iostream>


Huffman::Huffman(const std::string& s)
{
  buildHuffmanTree(s);
}

std::map<char, int> Huffman::countCharacterFrequency(const std::string& s)
{
  std::map<char, int> freq;
  for (char ch: s)
	  freq[ch]++;
  return freq;
}

template<typename T>
bool Huffman::isWeightGreater(std::pair<int, T>& a, std::pair<int, T>& b)
{
  return a.first > b.first? true : false;
}

HuffmanPointer Huffman::buildHuffmanTree(const std::string& s)
{
  this->characterFrequency = countCharacterFrequency(s);
  std::priority_queue<std::pair<int, char>> queue;
  std::map<char, int>::iterator it;
  for (it = characterFrequency.begin(); it != characterFrequency.end(); it++)
  {
    queue.push(std::make_pair(it->second, it->first));
  }
  //auto f = queue.top().first;
  //auto g = queue.top().second;
  HuffmanPointer a;
  return a;
}