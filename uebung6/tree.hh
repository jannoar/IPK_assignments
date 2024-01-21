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
    BinaryTreeNode(BinaryTreeNode l, BinaryTreeNode r, T value);
    BinaryTreeNode();
    ~BinaryTreeNode();
    T const getValue();
    T const getLeft();
    T const getRight();
    bool isLeaf();
};
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(): left(nullptr), right(nullptr) {}
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(BinaryTreeNode<T> l, BinaryTreeNode<T> r, T v): left(l), right(r), value(v){}

template<typename T>
T const BinaryTreeNode<T>::getLeft(){return this->left;}
template<typename T>
T const BinaryTreeNode<T>::getRight(){return this->right;}
template<typename T>
T const BinaryTreeNode<T>::getValue(){return this->value;}

template<typename T>
bool BinaryTreeNode<T>::isLeaf()
{
    if(this->left == nullptr && this->right == nullptr)
        return true; 
    return false;
}