#ifndef Node_h
#define Node_h

#include "string"

using namespace std;

class Node{
    public:
        Node():next(nullptr){};
        Node(string item):item(item){};
        Node(Node* next):next(next){};
        Node* getNext(){
            return next;
        }
        void setNext(Node* next){
            this->next = next;
        }
        string getItem(){
            return item;
        }
       
    private:
        Node* next;
        string item;
};

#endif