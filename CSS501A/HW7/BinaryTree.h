#ifndef BinaryTree_h
#define BinaryTree_h

#include <memory>
#include <queue>
#include <stack>
#include "BinaryNode.h"

using namespace std;

template<class K, class V>
class BinaryTree{
    private:
        void add(shared_ptr<BinaryNode<K,V>> ptr, const K& k, const V& v);
        void preorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&,V&)) const;
        void inorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&,V&)) const;
        void postorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&,V&)) const;
    protected:
        shared_ptr<BinaryNode<K,V>> root;

    public:
        BinaryTree();
        BinaryTree(shared_ptr<BinaryNode<K,V>> rt);
        BinaryTree(const K& k, const V& v);
        BinaryTree(const K& k, const V& v, shared_ptr<BinaryNode<K,V>> leftPrt, shared_ptr<BinaryNode<K,V>> rightPtr);
        ~BinaryTree();

        void add(const K& k, const V& v);
        void clear();
        void preorderTraversal(void visit(K&,V&)) const;
        void inorderTraversal(void visit(K&,V&)) const;
        void postorderTraversal(void visit(K&,V&)) const;
        void breadthFirstSearch(void visit(K&,V&)) const;
        void depthFirstSearch(void visit(K&,V&)) const;
};

template<class K, class V>
BinaryTree<K,V>::BinaryTree(){}

template<class K, class V>
BinaryTree<K,V>::BinaryTree(shared_ptr<BinaryNode<K,V>> rt){
    this->root = rt;
}

template<class K, class V>
BinaryTree<K,V>::BinaryTree(const K& k, const V& v){
    this->root = make_shared<BinaryNode<K,V>>(k,v);
}

template<class K, class V>
BinaryTree<K,V>::BinaryTree(const K& k, const V& v, shared_ptr<BinaryNode<K,V>> leftPrt, shared_ptr<BinaryNode<K,V>> rightPtr){
    this->root = make_shared<BinaryNode<K,V>>(k,v);
    this->root->setLeftChildPtr(leftPrt);
    this->root->setRightChildPtr(rightPtr);
}

template<class K, class V>
BinaryTree<K,V>::~BinaryTree(){}

template<class K, class V>
void BinaryTree<K,V>::add(const K& k, const V& v){
    if(this->root == nullptr){
        this->root = make_shared<BinaryNode<K,V>>(k,v);;
        return;
    }

    if(k < this->root->getKey()){
        if(this->root->getLeftChildPtr() == nullptr){
            auto newNode = make_shared<BinaryNode<K,V>>(k,v);
            this->root->setLeftChildPtr(newNode);
        }else{
            add(this->root->getLeftChildPtr(),k,v);
        }
    }else{
        if(this->root->getRightChildPtr() == nullptr){
            auto newNode = make_shared<BinaryNode<K,V>>(k,v);
            this->root->setRightChildPtr(newNode);
        }else{
            add(this->root->getRightChildPtr(),k,v);
        }
    }
}

template<class K, class V>
void BinaryTree<K,V>::add(shared_ptr<BinaryNode<K,V>> ptr, const K& k, const V& v){
    if(ptr == nullptr){
        ptr = make_shared<BinaryNode<K,V>>(k,v);
    }else if(k < ptr->getKey()){
        if(ptr->getLeftChildPtr() == nullptr){
            auto newNode = make_shared<BinaryNode<K,V>>(k,v);
            ptr->setLeftChildPtr(newNode);
        }else{
            add(ptr->getLeftChildPtr(),k,v);
        }
    }else{
        if(ptr->getRightChildPtr() == nullptr){
            auto newNode = make_shared<BinaryNode<K,V>>(k,v);
            ptr->setRightChildPtr(newNode);
        }else{
            add(ptr->getRightChildPtr(),k,v);
        }
    }
}

template<class K, class V>
void BinaryTree<K,V>::clear(){

}

template<class K, class V>
void BinaryTree<K,V>::preorderTraversal(void visit(K&, V&)) const{
    preorderTraversal(this->root, visit);
}

template<class K, class V>
void BinaryTree<K,V>::preorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&, V&)) const{
    if(ptr == nullptr)
        return;

    K k = ptr->getKey();
    V v = ptr->getValue();
    visit(k,v);

    preorderTraversal(ptr->getLeftChildPtr(),visit);

    preorderTraversal(ptr->getRightChildPtr(),visit);
}

template<class K, class V>
void BinaryTree<K,V>::inorderTraversal(void visit(K&, V&)) const{
    inorderTraversal(this->root, visit);
}

template<class K, class V>
void BinaryTree<K,V>::inorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&, V&)) const{
    if(ptr == nullptr)
        return;

    inorderTraversal(ptr->getLeftChildPtr(),visit);

    K k = ptr->getKey();
    V v = ptr->getValue();
    visit(k,v);

    inorderTraversal(ptr->getRightChildPtr(),visit);
}

template<class K, class V>
void BinaryTree<K,V>::postorderTraversal(void visit(K&, V&)) const{
    postorderTraversal(this->root,visit);
}

template<class K, class V>
void BinaryTree<K,V>::postorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&, V&)) const{
    if(ptr == nullptr)
        return;

    postorderTraversal(ptr->getLeftChildPtr(),visit);

    postorderTraversal(ptr->getRightChildPtr(),visit);

    K k = ptr->getKey();
    V v = ptr->getValue();
    visit(k,v);
}

template<class K, class V>
void BinaryTree<K,V>::breadthFirstSearch(void visit(K&, V&)) const{
    if(this->root == nullptr)
        return;

    queue<shared_ptr<BinaryNode<K,V>>> q;
    q.push(this->root);

    while(q.empty() == false){
        shared_ptr<BinaryNode<K,V>> ptr = q.front();
        q.pop();

        if(ptr->getLeftChildPtr() != nullptr)
            q.push(ptr->getLeftChildPtr());

        if(ptr->getRightChildPtr() != nullptr)
            q.push(ptr->getRightChildPtr());

        K k = ptr->getKey();
        V v = ptr->getValue();
        visit(k,v);
    }
}

template<class K, class V>
void BinaryTree<K,V>::depthFirstSearch(void visit(K&, V&)) const{
    if(this->root == nullptr)
        return;

    stack<shared_ptr<BinaryNode<K,V>>> s;
    s.push(this->root);

    while(s.empty() == false){
        shared_ptr<BinaryNode<K,V>> ptr = s.top();
        s.pop();

        if(ptr->getRightChildPtr() != nullptr)
            s.push(ptr->getRightChildPtr());
            
        if(ptr->getLeftChildPtr() != nullptr)
            s.push(ptr->getLeftChildPtr());

        K k = ptr->getKey();
        V v = ptr->getValue();
        visit(k,v);
    }
}

#endif