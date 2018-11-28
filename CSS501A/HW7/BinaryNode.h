#ifndef BinaryNode_h
#define BinaryNode_h

#include <memory>

using namespace std;

template<class T>
class BinaryNode{
    private:
        T data;
        shared_ptr<BinaryNode<T>> leftChildPtr;
        shared_ptr<BinaryNode<T>> rightChildPtr;

    public:
        BinaryNode();
        BinaryNode(const T& data);
        BinaryNode(const T& data, shared_ptr<BinaryNode<T>> leftPtr, shared_ptr<BinaryNode<T>> rightPtr);

        void setItem(const T& data);
        T getItem() const;

        shared_ptr<BinaryNode<T>> getLeftChildPtr() const;
        shared_ptr<BinaryNode<T>> getRightChildPtr() const;

        void setLeftChildPtr(shared_ptr<BinaryNode<T>> leftPtr);
        void setRightChildPtr(shared_ptr<BinaryNode<T>> rightPtr);
};

#include "BinaryNode.cpp"

#endif