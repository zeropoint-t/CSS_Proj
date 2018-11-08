
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
        Node(int data):data(data){
        }
        Node* getNext(){
            return this->next;
        }
        void setNext(Node* n){
            this->next = n;
        }
        Node* getPrev(){
            return this->prev;
        }
        void setPrev(Node* n){
            this->prev = n;
        }
        int getData(){
            return data;
        }
    protected:
        int data;
        Node* next = nullptr;
        Node* prev = nullptr;
};

class Queue{
    public:
        Queue(){
        }
        int IsEmpty(){
            return this->size == 0;
        }
        void Enqueue(int data){
            Node* n = new Node(data);
            if(IsEmpty()){
                head = n;
                tail = n;
            }else{
                n->setNext(head);
                head->setPrev(n);
                head = n;
            }
            size++;
        }
        int Dequeue(){
            if(IsEmpty())
                return 0;

            Node* nodeToDequeue = tail;

            if(size == 1){
                head = nullptr;
                tail = nullptr;
            }else{
                tail->getPrev()->setNext(nullptr);
                tail = tail->getPrev();
            }

            int data = nodeToDequeue->getData();
            delete nodeToDequeue;
            size--;
            return data;
        }

    protected:
        int size = 0;
        Node* head = nullptr;
        Node* tail = nullptr;

};

class Stack : protected Queue{
    public:
        void Push(int data){
            Enqueue(data);
        }
        int Pop(){
            Node* tmp = head;
            head = head->getNext();
            int data = tmp->getData();
            delete tmp;
            return data;
        }
    private:
};

int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;

    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;

    // cout << q.Dequeue() << endl;
}