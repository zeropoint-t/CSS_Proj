
#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

#include "ListInterface.hpp"
// #include "PrecondViolatedExcept.hpp"
#include "Node.hpp"

#include <iostream>

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 100; // Default capacity of the list
    Node<ItemType>* headPtr;    // Array of list items (ignore items[0]
    int itemCount;                           // Current count of list items

public:
    LinkedList() : headPtr(nullptr), itemCount(0)
    {
    } // end default constructor
    
    ~LinkedList()
    {
        clear();
    } // end destructor
    
    bool isEmpty() const override
    {
        return itemCount == 0;
    }  // end isEmpty
    
    int getLength() const override
    {
        return itemCount;
    }  // end getLength
    
    bool insert(int newPosition, const ItemType& newEntry) override
    {
        bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
        if (ableToInsert)
        {
            // Create a new node containing the new entry
            Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
            headPtr = insertNode(newPosition, newNodePtr, headPtr);
        } // end if
        return ableToInsert;
    } // end insert
    
    Node<ItemType>* insertNode(
        int position,
        Node<ItemType>* newNodePtr,
        Node<ItemType>* subChainPtr
    )
    {
        if (position == 1)
        {
            // Insert new node at beginning of subchain
            newNodePtr->setNext(subChainPtr);
            subChainPtr = newNodePtr;
            itemCount++;  // Increase count of entries
        }
        else
        {
            Node<ItemType>* afterPtr = insertNode(position - 1, newNodePtr, subChainPtr->getNext());
            subChainPtr->setNext(afterPtr);
        }  // end if
        
        return subChainPtr;
    }  // end insertNode

    
    bool remove(int position) override
    {
        bool ableToRemove = (position >= 1) && (position <= itemCount);
        if (ableToRemove)
        {
            Node<ItemType>* curPtr = nullptr;
            if (position == 1)
            {
                // Remove the first node in the chain
                curPtr = headPtr; // Save pointer to node
                headPtr = headPtr->getNext();
            }
            else
            {
                // Find node that is before the one to remove
                Node<ItemType>* prevPtr = getNodeAt(position - 1);
                
                // Point to node to remove
                curPtr = prevPtr->getNext();
                
                // Disconnect indicated node from chain by connecting the
                // prior node with the one after
                prevPtr->setNext(curPtr->getNext());
            } // end if
            
            // Return node to system
            curPtr->setNext(nullptr);
            delete curPtr;
            curPtr = nullptr;
            itemCount--; // Decrease count of entries
        } // end if
        
        return ableToRemove;
    } // end remove
    
    void clear() override
    {
        while (!isEmpty())
            remove(1);
    } // end clear
    
    
    ItemType getEntry(int position) const override
    {
        // Enforce precondition
        bool ableToGet = (position >= 1) && (position <= itemCount);
        if (ableToGet)
        {
            Node<ItemType>* nodePtr = getNodeAt(position);
            return nodePtr->getItem();
        }
        else
        {
            std::string message = "getEntry() called with an empty list or ";
            message = message + "invalid position.";
            return nullptr;
            // throw(PrecondViolatedExcept(message));
        } // end if
    } // end getEntry
    
    Node<ItemType>* getNodeAt(int position) const
    {
        // Debugging check of precondition
        assert( (position >= 1) && (position <= itemCount) );
        
        // Count from the beginning of the chain
        Node<ItemType>* curPtr = headPtr;
        for (int skip = 1; skip < position; skip++)
            curPtr = curPtr->getNext();
        
        return curPtr;
    }  // end getNodeAt
    
    ItemType replace(int position, const ItemType& newEntry) override
    {
        // Enforce precondition
        bool ableToSet = (position >= 1) && (position <= itemCount);
        if (ableToSet)
        {
//            ItemType oldEntry = items[position];
//            items[position] = newEntry;
//            return oldEntry;
            return nullptr;
        }
        else
        {
            std::string message = "replace() called with an empty list or ";
            message = message + "invalid position.";
            return nullptr;
            // throw(PrecondViolatedExcept(message));
        } // end if
    }  // end replace
    
    
}; // end ArrayList

#endif /* LinkedList_hpp */
