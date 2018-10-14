
#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
        Node(string item):item(item){}

        string getData() const {
            return item;
        }
        void setItem(string item){
            this->item = item;
        }
        void setNext(Node* next){
            this->next = next;
        }
        void setPrev(Node* prev){
            this->prev = prev;
        }
        Node* getNext(){
            return new Node("");
        }
        Node* getPrev(){
            return new Node("");
        }

    private:
        string item;
        Node* next;
        Node* prev;
};

class LinkedList{
    public:
        LinkedList(){}
        LinkedList(Node* item){
            this->head = item;
            this->tail = item;
        }

        //pushes a node to the back of the list
        void push_back(Node* n){
            if(size > 1){
                tail->setNext(n);
                n->setPrev(tail);
                tail = n;
            }else{
                head = n;
                tail = n;
            }
        }

        string pop(){
            if(size > 0){
                tail = tail->getPrev();
                // string item = 
                // Node* nodeToPop = tail->getPrev();
                // nodeToPop->getPrev()->setNext(nullptr);
                // tail = nodeToPop->getPrev();
                // string item = nodeToPop->getData();
                // delete nodeToPop;
                // return item;
            }
        }

        bool insert(Node* item, int index){
            return true;
        }

        bool remove(int index){
            return true;
        }

        Node* find(int index){
            return new Node("");
        }

        bool isEmpty(){
            return true;
        }

        void clear(){

        }
    private:
        Node* head;
        Node* tail;
        int size;
};

int main(int argc, char* argv[]){
    Node n("Hello WOrld");
    cout << n.getData() << endl;



}