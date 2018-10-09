#ifndef Node_h
#define Node_h

#include "string"

using namespace std;

class Node{
    public:
        Node():next(nullptr){};
        Node(string item):item(item),next(nullptr),prev(nullptr){};
        Node(string item, Node* next, Node* prev):item(item),next(next),prev(prev){}
        
        Node* getNext(){
            return next;
        }
        void setNext(Node* next){
            this->next = next;
        }

        Node* getPrev(){
            return prev;
        }
        void setPrev(Node* prev){
            this->prev = prev;
        }

        string getItem(){
            return item;
        }
       
    private:
        Node* next;
        Node* prev;
        string item;
};

#endif