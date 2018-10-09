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
            if(index == 0){
                insert(item);
                return true;
            }
            else if(index > 0 && index <= size){
                int c = 0;
                Node* current = head;
                while(c++ < index){
                    current = current->getNext();
                }
                Node* prev = current->getPrev();
                item->setNext(current);
                current->setPrev(item);
                prev->setNext(item);
                item->setPrev(prev);

                ++size;
                return true;
            }
            return false;
        }
        void insert(string item, int index){
            Node* newItem = new Node(item);
            insert(newItem, index);
        }

        bool remove(int index){
            if(index == 0){
                Node* nodeToRemove = head;
                Node* next = head->getNext();
                head = next;
                if(head != nullptr){
                    head->setPrev(nullptr);
                    //no more element left so tail should point to null
                    tail = nullptr;
                }

                nodeToRemove->setNext(nullptr);
                nodeToRemove->setPrev(nullptr);
                delete nodeToRemove;
                nodeToRemove = nullptr;

                --size;
                return true;
            }else if(index>0 && index < size){
                int c = 0;
                Node* nodeToRemove = head;
                while(c++ < index){
                   nodeToRemove = nodeToRemove->getNext();
                }
                
                Node* prev = nodeToRemove->getPrev();
                prev->setNext(nodeToRemove->getNext());
                nodeToRemove->getNext()->setPrev(prev);

                nodeToRemove->setNext(nullptr);
                nodeToRemove->setPrev(nullptr);
                delete nodeToRemove;
                nodeToRemove = nullptr;

                --size;
                return true;
            }
            return false;
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