#pragma once
#include <memory>

template<typename T>
class BinaryTreeNode
{
private:
    T value; 
    std::shared_ptr<BinaryTreeNode<T>> left; 
    std::shared_ptr<BinaryTreeNode<T>> right;
public:
    BinaryTreeNode(std::shared_ptr<BinaryTreeNode<T>> l, std::shared_ptr<BinaryTreeNode<T>> r, T value);
    BinaryTreeNode(T value);
    T const getValue();
    std::shared_ptr<BinaryTreeNode<T>> const getLeft();
    std::shared_ptr<BinaryTreeNode<T>> const getRight();
    bool isLeaf();
};
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T v): left(nullptr), right(nullptr), value(v) {}
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(std::shared_ptr<BinaryTreeNode<T>> l, std::shared_ptr<BinaryTreeNode<T>> r, T v): left(l), right(r), value(v){}

template<typename T>
std::shared_ptr<BinaryTreeNode<T>> const BinaryTreeNode<T>::getLeft(){return this->left;}
template<typename T>
std::shared_ptr<BinaryTreeNode<T>> const BinaryTreeNode<T>::getRight(){return this->right;}
template<typename T>
T const BinaryTreeNode<T>::getValue(){return this->value;}

template<typename T>
bool BinaryTreeNode<T>::isLeaf()
{
    if(this->left == nullptr && this->right == nullptr)
        return true; 
    return false;
}