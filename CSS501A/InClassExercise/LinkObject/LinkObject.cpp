#ifndef LinkObject_h
#define LinkObject_h

#include "Node.cpp"
#include <iostream>
#include <string>
using namespace std;

class LinkedList{
    public:
        LinkedList():head(nullptr){}
        LinkedList(Node* head):head(head){}
        void insert(Node* item){//insert at the beginning
            if(head == nullptr){
                head = item;
            }else{
                item->setNext(head);
                head = item;
            }
            ++count;
        }
        bool insert(Node* item, int index){
            if(index == 0){
                insert(item);
                ++count;
                return true;
            }
            else if(index > 0 && index <= count){
                int c = 1;
                Node* prev = head;
                Node* current = prev->getNext();
                while(c++ < index){
                    prev = prev->getNext();
                    current = prev->getNext();
                }
                item->setNext(current);
                prev->setNext(item);

                ++count;
                return true;
            }
            ++count;
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

                delete nodeToRemove;
                nodeToRemove = nullptr;
                return true;
            }else if(index>0 && index < count){
                int c = 1;
                Node* prev = head;
                Node* nodeToRemove = prev->getNext();
                while(c++ < index){
                    prev = prev->getNext();
                    nodeToRemove = prev->getNext();
                }
                prev->setNext(nodeToRemove->getNext());
                delete nodeToRemove;
                nodeToRemove = nullptr;
                return true;
            }
            return false;
        }
        string get(int index){
            return "";
        }
        void clear(){
            while(!isEmpty()){
                remove(1);
            }
        }
        bool isEmpty(){
            return count == 0;
        }
        void display(){
            Node* n = head;
            while(n != nullptr){
                cout << n->getItem() << endl;
                n = n->getNext();
            }
        }
    private:
        Node* head;
        int count;
};

#endif