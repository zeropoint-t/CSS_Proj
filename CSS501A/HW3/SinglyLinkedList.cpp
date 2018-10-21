#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList():head(nullptr),size(0){

}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& list):head(nullptr),size(0){
    Node* origChain = list.head;
    if(origChain != nullptr){
        Node* newChain = new Node(origChain->getData());
        head = newChain;
        size++;
        while(origChain->getNext() != nullptr){
            origChain = origChain->getNext();
            Node* newNode = new Node(origChain->getData());
            newChain->setNext(newNode);
            newChain = newChain->getNext();
            size++;
        }
    }
}

SinglyLinkedList::~SinglyLinkedList(){
    clear();
}

bool SinglyLinkedList::insert(string d, int index){
    if(index < 0 || index > size)
        return false;

    if(index == 0){
        insertFirst(d);
    }else if(index == size){
        insertLast(d);
    }else{
        Node* nodeBefore = getNodeAt(index-1);
        Node* newNode = new Node(d);
        newNode->setNext(nodeBefore->getNext());
        nodeBefore->setNext(newNode);
    }
    return true;
}

void SinglyLinkedList::insertFirst(string d){
    Node* newNode = new Node(d);
    if(head == nullptr){
        head = newNode;
    }else{
        newNode->setNext(head);
        head = newNode;
    }
    ++size;
}

void SinglyLinkedList::insertLast(string d){
    Node* newNode = new Node(d);
    if(head == nullptr){
        head = newNode;
    }else{
        Node* lastNode = getNodeAt(size-1);
        lastNode->setNext(newNode);
    }
    ++size;
}

bool SinglyLinkedList::remove(int index){
    if(index < 0 || index >= size || size == 0)
        return false;

    if(index==0){
        Node* nodeToRemove = head;
        head = head->getNext();
        delete nodeToRemove;
    }else {
        Node* nodeToRemoveBefore = getNodeAt(index-1);
        Node* nodeToRemove = nodeToRemoveBefore->getNext();
        nodeToRemoveBefore->setNext(nodeToRemoveBefore->getNext()->getNext());
        delete nodeToRemove;
    }

    --size;
    return true;
}

void SinglyLinkedList::print() const{
    Node* curNode = head;
    while(curNode != nullptr){
        cout << curNode << ": " << curNode->getData() << endl;
        curNode = curNode->getNext();
    }
}

/*
    Prints items stored in a list in a reverse order using iterative technique
    This does not affect the order of items in the original list.
    Big-O analysis:
    Each original node is traversed through creating a new object on a heap
    and reversing the pointer direction at O(n) complexity
    And each reverse node is printed at O(n).
    At the end, it has roughly O(2n), dropping 2 makes the final time complexity of this function O(n)
*/
void SinglyLinkedList::printReverseIterative() const{
    //create 3 pointers to keep track of previous, current and next nodes
    Node* curNode = head;
    if(curNode != nullptr){
        Node* pTmpCur = new Node(curNode->getData());

        Node* prev = nullptr;
        Node* pTmpPrev = nullptr;

        Node* next = nullptr;
        Node* pTmpNext = nullptr;

        while(curNode != nullptr){
            next = curNode->getNext();
            if(next != nullptr){
                pTmpNext = new Node(next->getData());
            }else{
                pTmpNext = nullptr;
            }

            //flip direction
            pTmpCur->setNext(pTmpPrev);

            prev = curNode;
            pTmpPrev = pTmpCur;

            curNode = next;
            pTmpCur = pTmpNext;
        }
        //last value in prev is the new head
        Node* nodeToPrint = pTmpPrev;
        while(nodeToPrint != nullptr){
            //print data
            cout << nodeToPrint << ": " << nodeToPrint->getData() << endl;
            //save a pointer to the node to be removed
            Node* nodeToRemove = nodeToPrint;
            //point to the next node
            nodeToPrint = nodeToPrint->getNext();
            //release memory after printed
            delete nodeToRemove;
        }
    }
}

/*
    Print items stored in a list in a reverse order using recrusive technique
    This does not affect the order of items in the original list
    Big O analysis:
    each node is called recursively until the node.next is null before each data is printed
    Therefore, time complexity of this function is O(n);
*/
void SinglyLinkedList::printReverseRecursive(Node* n) const{
    if(n == nullptr){
        n = head;
    }
    if(n != nullptr){
        Node* first = n;
        Node* next = first->getNext();

        if(next == nullptr){
            cout << first << ": " << first->getData() << endl;
            return;
        }
        printReverseRecursive(next);
        cout << first << ": " << first->getData() << endl;
        return;
    }
    return;
}

Node* SinglyLinkedList::getNodeAt(int index){
    if(index < 0 || index >= size)
        return nullptr;

    Node* curNode = head;
    int cnt = 0;
    while(cnt++ < index){
        curNode = curNode->getNext();
    }
    return curNode;
}

void SinglyLinkedList::clear(){
    while(head != nullptr){
        remove(0);
    }
}