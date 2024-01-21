#pragma once
#include <memory>

template<typename T>
class BinaryTreeNode
{
private:
    T value; 
    std::shared_ptr<T> left; 
    std::shared_ptr<T> right;
public:
    BinaryTreeNode(std::shared_ptr<T> l, std::shared_ptr<T> r, T value);
    BinaryTreeNode(T value);
    T const getValue();
    T const getLeft();
    T const getReight();
    bool isLeaf();
};
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T v): left(nullptr), right(nullptr), value(v) {}
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(std::shared_ptr<T> l, std::shared_ptr<T> r, T v): left(l), right(r), value(v){}

template<typename T>
T const BinaryTreeNode<T>::getLeft(){return this->left;}
template<typename T>
T const BinaryTreeNode<T>::getReight(){return this->right;}
template<typename T>
T const BinaryTreeNode<T>::getValue(){return this->value;}

template<typename T>
bool BinaryTreeNode<T>::isLeaf()
{
    if(this->left == nullptr && this->reight == nullptr)
        return true; 
    return false;
}