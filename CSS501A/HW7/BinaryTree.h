#ifndef BinaryTree_h
#define BinaryTree_h

#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include "BinaryNode.h"

using namespace std;

template<class K, class V>
class BinaryTree{
    private:
        void add(shared_ptr<BinaryNode<K,V>> ptr, const K& k, const V& v);
        void clear(shared_ptr<BinaryNode<K,V>> ptr);
        void preorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&,V&)) const;
        void inorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&,V&)) const;
        void postorderTraversal(shared_ptr<BinaryNode<K,V>> ptr, void visit(K&,V&)) const;
        // void getHoffmanCode(K& k, shared_ptr<BinaryNode<K,V>> n, stack<char>& s) const;
    protected:
        shared_ptr<BinaryNode<K,V>> root;

    public:
        BinaryTree();
        BinaryTree(shared_ptr<BinaryNode<K,V>> rt);
        BinaryTree(const K& k, const V& v);
        BinaryTree(const K& k, const V& v, shared_ptr<BinaryNode<K,V>> leftPrt, shared_ptr<BinaryNode<K,V>> rightPtr);
        ~BinaryTree();

        string getHoffmanCode(K& k) const;
        void add(const K& k, const V& v);
        void clear();
        void preorderTraversal(void visit(K&,V&)) const;
        void inorderTraversal(void visit(K&,V&)) const;
        void postorderTraversal(void visit(K&,V&)) const;
        void breadthFirstSearch(void visit(K&,V&)) const;
        void depthFirstSearch(void visit(K&,V&)) const;

        void displayRoot() const{
            cout << this->root->getKey() << " " << this->root->getValue() << " at " << &(*this->root) << endl;
        }
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
BinaryTree<K,V>::~BinaryTree(){
    cout << "Tree being destroyed" << endl;
}

template<class K, class V>
string BinaryTree<K,V>::getHoffmanCode(K& k) const{

    displayRoot();

    if(this->root == nullptr)
        return "";

    stack<char> hoffmanStack;
    stack<shared_ptr<BinaryNode<K,V>>> nodeStack;

    shared_ptr<BinaryNode<K,V>> curNode = this->root;
    nodeStack.push(curNode);

    while(curNode->getLeftChildPtr() != nullptr){
        curNode = curNode->getLeftChildPtr();
        cout << curNode->getKey() << " " << curNode->getValue() << endl;
        nodeStack.push(curNode);
        hoffmanStack.push('0');
    }

    while(nodeStack.empty() == false){
        curNode = nodeStack.top();
        nodeStack.pop();
        
        //leaf node
        if(curNode->getLeftChildPtr() == nullptr && curNode->getRightChildPtr() == nullptr){
            //key is found?
            if(curNode->getKey() == k){
                break;
            }
        }else{
            //not a leaf node. Need to go back to parent so pop offman stack
            hoffmanStack.pop();
        }

        //go to next right
        if(curNode->getRightChildPtr() != nullptr){
            curNode = curNode->getRightChildPtr();
            nodeStack.push(curNode);
            hoffmanStack.push('1');

            while(curNode->getLeftChildPtr() != nullptr){
                curNode = curNode->getLeftChildPtr();
                nodeStack.push(curNode);
                hoffmanStack.push('0');
            }
        }
    }

    //insert hoffman code into another stack to rearrange order
    stack<char> hoffmanFinalStack;
    while(hoffmanStack.empty() == false){
        hoffmanFinalStack.push(hoffmanStack.top());
        hoffmanStack.pop();
    }

    string hoffmanCode;
    while(hoffmanFinalStack.empty() == false){
        // cout << hoffmanFinalStack.top() << endl;
        hoffmanCode += string(1,hoffmanFinalStack.top());
        hoffmanFinalStack.pop();
    }

    return hoffmanCode;
}

// template<class K, class V>
// void BinaryTree<K,V>::getHoffmanCode(K& k, shared_ptr<BinaryNode<K,V>> n, stack<char>& hoffmanStack) const{
//     if(n == nullptr)
//         return;

//     stack<shared_ptr<BinaryNode<K,V>>> s;
//     s.push(this->root);

//     while(s.empty() == false){
//         shared_ptr<BinaryNode<K,V>> bn = s.top();
//         s.pop();

//         cout << bn->getKey() << " " << bn->getValue() << endl;
        
//         // if(bn == nullptr){
//         //     s.pop();
//         //     return;
//         // }

//         if(bn->getKey() == k)
//             break;

//         if(bn->getRightChildPtr() != nullptr){
//             hoffmanStack.push('1');
//             s.push(bn->getRightChildPtr());
//         }

//         if(bn->getLeftChildPtr() != nullptr){
//             hoffmanStack.push('0');
//             s.push(bn->getLeftChildPtr());
//         }
//     }

// }

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
    if(this->root == nullptr)
        return;
    
    clear(this->root);
    this->root = nullptr;
}

template<class K, class V>
void BinaryTree<K,V>::clear(shared_ptr<BinaryNode<K,V>> ptr){
    if(ptr == nullptr)
        return;

    clear(ptr->getLeftChildPtr());
    ptr->setLeftChildPtr(nullptr);
    clear(ptr->getRightChildPtr());
    ptr->setRightChildPtr(nullptr);
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