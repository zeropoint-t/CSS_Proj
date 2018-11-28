

#include "BinaryNode.h"

template<class T>
BinaryNode<T>::BinaryNode(){}

template<class T>
BinaryNode<T>::BinaryNode(const T& data):data(data){}

template<class T>
BinaryNode<T>::BinaryNode(const T& data, shared_ptr<BinaryNode<T>> leftPtr, shared_ptr<BinaryNode<T>> rightPtr)
    :data(data),leftChildPtr(leftPtr),rightChildPtr(rightPtr){}

template<class T>
void BinaryNode<T>::setItem(const T& data){
    this->data = data;
}

template<class T>
T BinaryNode<T>::getItem() const{
    return this->data;
}

template<class T>
shared_ptr<BinaryNode<T>> BinaryNode<T>::getLeftChildPtr() const{
    return this->leftChildPtr;
}

template<class T>
shared_ptr<BinaryNode<T>> BinaryNode<T>::getRightChildPtr() const{
    return this->rightChildPtr;
}

template<class T>
void BinaryNode<T>::setLeftChildPtr(shared_ptr<BinaryNode<T>> leftPtr){
    this->leftChildPtr = leftPtr;
}

template<class T>
void BinaryNode<T>::setRightChildPtr(shared_ptr<BinaryNode<T>> rightPtr){
    this->rightChildPtr = rightPtr;
}