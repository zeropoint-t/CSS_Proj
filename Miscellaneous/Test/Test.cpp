#include <stdio.h>
#include "memory"
#include "string"
#include <iostream>

using namespace std;

template<class T>
class Node {

private:
    T item;
    Node<T>* pNext;
    
public:
    Node() {}
    Node(const T& anItem) :item(anItem) {
        cout << "Node Constructed at " << this << endl;
    }
    Node(const T& anItem, Node<T>* pNext) : item(anItem), pNext(pNext) {
        cout << "Node Constructed at " << this << endl;
    }
    ~Node() {
        std::cout << "Destructor called at " << this << std::endl;
    }
    
    Node<T>* getNext() const {
        return pNext;
    }
    
    void setNext(Node<T>* pNext) {
        this->pNext = pNext;
    }
    
    void setItem(const T& anItem) {
        this->item = anItem;
    }
    
    T getItem() const {
        return this->item;
    }
};

int main(){
    string str = "Hello World";

    Node<string> n1(str);

    cout << n1.getItem() << endl;

    return 0;
}