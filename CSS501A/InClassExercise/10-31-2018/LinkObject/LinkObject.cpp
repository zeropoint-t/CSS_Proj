#ifndef LinkObject_h
#define LinkObject_h

#include "Node.cpp"
#include <iostream>
#include <string>
using namespace std;

class LinkedList{
    public:
        LinkedList():head(nullptr),size(0){}
        LinkedList(Node* head):head(head),size(1){}
        void insert(Node* item){//insert at the beginning
            if(head == nullptr){
                head = item;
                tail = item;
            }else{
                item->setNext(head);
                head->setPrev(item);
                head = item;
            }
            ++size;
        }
        bool insert(Node* item, int index){
            bool canInsert = (index >= 0 && index <= size);
            if(canInsert){
                if(index == 0){
                    //insert at the beginning
                    insert(item);
                }
                else {
                    int c = 0;
                    Node* current = head;
                    while(c++ < index){
                        current = current->getNext();
                    }

                    if(current == nullptr){
                        //insert at the end
                        tail->setNext(item);
                        item->setPrev(tail);
                        tail = item;
                    }else{
                        Node* prev = current->getPrev();
                        item->setNext(current);
                        current->setPrev(item);
                        prev->setNext(item);
                        item->setPrev(prev);
                    }
                }
                ++size;
            }
            return canInsert;
        }
        void insert(string item, int index){
            Node* newItem = new Node(item);
            insert(newItem, index);
        }

        bool remove(int index){

            bool canRemove = (index >= 0 && index < size);
            if(canRemove){
                if(size == 1){
                    //only node is removed
                    Node* nodeToRemove = head;
                    delete nodeToRemove;
                    head = nullptr;
                    tail = nullptr;
                }else{
                    //find node to remove
                    int c = 0;
                    Node* nodeToRemove = head;
                    while(c++ < index){
                        nodeToRemove = nodeToRemove->getNext();
                    }

                    //get previous node
                    Node* prev = nodeToRemove->getPrev();
                    Node* next = nodeToRemove->getNext();

                    //first node to be removed
                    if(prev == nullptr){
                        head = next;
                    }

                    //last node to be removed
                    if(next == nullptr){
                        tail = prev;
                    }

                    //hook up prevous to next
                    if(prev != nullptr){
                        prev->setNext(next);
                    }

                    //hook up next to previous
                    if(next != nullptr){
                        next->setPrev(prev);
                    }

                    nodeToRemove->setNext(nullptr);
                    nodeToRemove->setPrev(nullptr);
                    delete nodeToRemove;
                }
            }

            if(canRemove)
                --size;

            return canRemove;
        }

        string get(int index){
            return "";
        }

        void clear(){
            while(!isEmpty()){
                remove(0);
            }
        }
        bool isEmpty(){
            return this->size == 0;
        }
        void displayForward(){
            Node* n = head;
            while(n != nullptr){
                cout << n->getItem() << endl;
                n = n->getNext();
            }
        }
        void displayBackward(){
            Node* n = tail;
            while(n != nullptr){
                cout << n->getItem() << endl;
                n = n->getPrev();
            }
        }
    private:
        Node* head;
        Node* tail;
        int size;
};

#endif