
#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <iostream>

template<class ItemType>
class Node
{
private:
    ItemType        item; // A data item
    Node<ItemType>* next; // Pointer to next node
    
public:
    Node() : next(nullptr)
    {
    } // end default constructor
    
    Node(const ItemType& anItem) : item(anItem), next(nullptr)
    {
    } // end constructor
    
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
    item(anItem), next(nextNodePtr)
    {
    } // end constructor
    
    void setItem(const ItemType& anItem)
    {
        item = anItem;
    } // end setItem
    
    void setNext(Node<ItemType>* nextNodePtr)
    {
        next = nextNodePtr;
    } // end setNext
    
    ItemType getItem() const
    {
        return item;
    } // end getItem
    
    Node<ItemType>* getNext() const
    {
        return next;
    } // end getNext
}; // end Node

#endif /* Node_hpp */
