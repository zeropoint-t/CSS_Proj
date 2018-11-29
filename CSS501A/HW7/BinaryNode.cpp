

#include "BinaryNode.h"

template<class K, class V>
BinaryNode<K,V>::BinaryNode(){}

template<class K, class V>
BinaryNode<K,V>::BinaryNode(const K& k, const V& v):key(k),value(v){}

template<class K, class V>
BinaryNode<K,V>::BinaryNode(const K& k, const V& v, shared_ptr<BinaryNode<K,V>> leftPtr, shared_ptr<BinaryNode<K,V>> rightPtr)
    :key(k),value(v),leftChildPtr(leftPtr),rightChildPtr(rightPtr){}

template<class K, class V>
void BinaryNode<K,V>::setKey(const K& k){
    this->key = k;
}

template<class K, class V>
void BinaryNode<K,V>::setValue(const V& v){
    this->value = v;
}

template<class K, class V>
K BinaryNode<K,V>::getKey() const{
    return this->key;
}

template<class K, class V>
V BinaryNode<K,V>::getValue() const{
    return this->value;
}

template<class K, class V>
shared_ptr<BinaryNode<K,V>> BinaryNode<K,V>::getLeftChildPtr() const{
    return this->leftChildPtr;
}

template<class K, class V>
shared_ptr<BinaryNode<K,V>> BinaryNode<K,V>::getRightChildPtr() const{
    return this->rightChildPtr;
}

template<class K, class V>
void BinaryNode<K,V>::setLeftChildPtr(shared_ptr<BinaryNode<K,V>> leftPtr){
    this->leftChildPtr = leftPtr;
}

template<class K, class V>
void BinaryNode<K,V>::setRightChildPtr(shared_ptr<BinaryNode<K,V>> rightPtr){
    this->rightChildPtr = rightPtr;
}