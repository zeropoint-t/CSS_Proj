#ifndef BinaryTree_h
#define BinaryTree_h

#include <memory>
#include <queue>
#include <stack>
#include "BinaryNode.h"

using namespace std;

template<class T>
class BinaryTree{
    private:
        void preorderTraversal(shared_ptr<BinaryNode<T>> ptr, void visit(T&)) const;
        void inorderTraversal(shared_ptr<BinaryNode<T>> ptr, void visit(T&)) const;
        void postorderTraversal(shared_ptr<BinaryNode<T>> ptr, void visit(T&)) const;
    protected:
        shared_ptr<BinaryNode<T>> root;

    public:
        BinaryTree();
        BinaryTree(shared_ptr<BinaryNode<T>> rt);
        BinaryTree(const T& rootItem);
        BinaryTree(const T& rootItem, shared_ptr<BinaryNode<T>> leftPrt, shared_ptr<BinaryNode<T>> rightPtr);
        ~BinaryTree();

        void add(const T& data);
        void preorderTraversal(void visit(T&)) const;
        void inorderTraversal(void visit(T&)) const;
        void postorderTraversal(void visit(T&)) const;
        void breadthFirstSearch(void visit(T&)) const;
        void depthFirstSearch(void visit(T&)) const;
};

template<class T>
BinaryTree<T>::BinaryTree(){}

template<class T>
BinaryTree<T>::BinaryTree(shared_ptr<BinaryNode<T>> rt){
    this->root = rt;
}

template<class T>
BinaryTree<T>::BinaryTree(const T& rootItem){
    this->root = make_shared<BinaryNode<T>>(rootItem);
}

template<class T>
BinaryTree<T>::BinaryTree(const T& rootItem, shared_ptr<BinaryNode<T>> leftPrt, shared_ptr<BinaryNode<T>> rightPtr){
    this->root = make_shared<BinaryNode<T>>(rootItem);
    this->root->setLeftChildPtr(leftPrt);
    this->root->setRightChildPtr(rightPtr);
}

template<class T>
BinaryTree<T>::~BinaryTree(){}

template<class T>
void add(const T& data){

}

template<class T>
void BinaryTree<T>::preorderTraversal(void visit(T&)) const{
    preorderTraversal(this->root, visit);
}

template<class T>
void BinaryTree<T>::preorderTraversal(shared_ptr<BinaryNode<T>> ptr, void visit(T&)) const{
    if(ptr == nullptr)
        return;

    T item = ptr->getItem();
    visit(item);

    preorderTraversal(ptr->getLeftChildPtr(),visit);

    preorderTraversal(ptr->getRightChildPtr(),visit);
}

template<class T>
void BinaryTree<T>::inorderTraversal(void visit(T&)) const{
    inorderTraversal(this->root, visit);
}

template<class T>
void BinaryTree<T>::inorderTraversal(shared_ptr<BinaryNode<T>> ptr, void visit(T&)) const{
    if(ptr == nullptr)
        return;

    inorderTraversal(ptr->getLeftChildPtr(),visit);

    T item = ptr->getItem();
    visit(item);

    inorderTraversal(ptr->getRightChildPtr(),visit);
}

template<class T>
void BinaryTree<T>::postorderTraversal(void visit(T&)) const{
    postorderTraversal(this->root,visit);
}

template<class T>
void BinaryTree<T>::postorderTraversal(shared_ptr<BinaryNode<T>> ptr, void visit(T&)) const{
    if(ptr == nullptr)
        return;

    postorderTraversal(ptr->getLeftChildPtr(),visit);

    postorderTraversal(ptr->getRightChildPtr(),visit);

    T item = ptr->getItem();
    visit(item);
}

template<class T>
void BinaryTree<T>::breadthFirstSearch(void visit(T&)) const{
    if(this->root == nullptr)
        return;

    queue<shared_ptr<BinaryNode<T>>> q;
    q.push(this->root);

    while(q.empty() == false){
        shared_ptr<BinaryNode<T>> ptr = q.front();
        q.pop();

        if(ptr->getLeftChildPtr() != nullptr)
            q.push(ptr->getLeftChildPtr());

        if(ptr->getRightChildPtr() != nullptr)
            q.push(ptr->getRightChildPtr());

        T item = ptr->getItem();
        visit(item);
    }
}

template<class T>
void BinaryTree<T>::depthFirstSearch(void visit(T&)) const{
    if(this->root == nullptr)
        return;

    stack<shared_ptr<BinaryNode<T>>> s;
    s.push(this->root);

    while(s.empty() == false){
        shared_ptr<BinaryNode<T>> ptr = s.top();
        s.pop();

        if(ptr->getRightChildPtr() != nullptr)
            s.push(ptr->getRightChildPtr());
            
        if(ptr->getLeftChildPtr() != nullptr)
            s.push(ptr->getLeftChildPtr());

        T item = ptr->getItem();
        visit(item);
    }
}

#endif