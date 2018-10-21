
#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include "Node.h"
#include <string>

class SinglyLinkedList{
    public:

        SinglyLinkedList();
        SinglyLinkedList(const SinglyLinkedList& list);
        ~SinglyLinkedList();

        bool insert(string d, int index);
        void insertFirst(string d);
        void insertLast(string d);
        
        bool remove(int index);

        void print() const;
        void printReverseIterative() const;
        void printReverseRecursive(Node* n = nullptr) const;
        void clear();

    private:
        Node* head;
        int size;
        Node* getNodeAt(int index);
};

#endif