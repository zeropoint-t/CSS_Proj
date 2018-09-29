//
//  LinkedList.hpp
//  SmartPointer
//
//  Created by Tetsuya Hayashi on 9/19/18.
//  Copyright © 2018 Tetsuya Hayashi. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include "memory"
#include "string"
#include <iostream>
#include "SmartPointer.hpp"

using namespace std;

template<class T>

class Node {
    
private:
    T item;
    SmartPointer<Node<T> > next;
    
public:
    Node() {}
    Node(const T& anItem) :item(anItem) {
        cout << "Node Constructed at " << this << endl;
    }
    Node(const T& anItem, SmartPointer<Node<T> > next) : item(anItem), next(next) {
        cout << "Node Constructed at " << this << endl;
    }
    ~Node() {
        std::cout << "Destructor called at " << this << std::endl;
    }
    
    SmartPointer<Node<T> >& getNext() {
        return next;
    }
    
    void setNext(SmartPointer<Node<T> > next) {
        this->next = next;
    }
    
    void setItem(const T& anItem) {
        this->item = anItem;
    }
    
    T getItem() const {
        return this->item;
    }
};

template<class T>

class LinkedList {
private:
    
    SmartPointer<Node<T> > headPtr;
    int32_t itemCount;
    SmartPointer<Node<T> > getNodeAt(int32_t p) {
        
        if (p >= 1 && p <= itemCount) {
            int count = 0;
            SmartPointer<Node<T> > curNode = headPtr;
            while (p != ++count) {
                curNode = curNode->getNext();
            }
            return curNode;
        }
        return NULL;
    }
    
public:
    
    LinkedList() :itemCount(0), headPtr(nullptr) {};
    
    bool Insert(int newPosition, const T& newEntry) {
        bool ableToInsert = (newPosition >= 1) && (newPosition) <= itemCount + 1;
        if (ableToInsert) {
            SmartPointer<Node<T> > newNodePtr(new Node<T>(newEntry)); //std::make_shared<Node<T>>(newEntry);
            if(newPosition == 1) {
                newNodePtr->setNext(headPtr);
                headPtr = newNodePtr;
            }
            else {
                SmartPointer<Node<T> > prevPtr = getNodeAt(newPosition - 1);
                newNodePtr->setNext(prevPtr->getNext());
                prevPtr->setNext(newNodePtr);
            }
        }
        itemCount++;
        return ableToInsert;
    }
    
    void Clear() {
        headPtr = NULL;
    }
};
#endif /* LinkedList_hpp */
