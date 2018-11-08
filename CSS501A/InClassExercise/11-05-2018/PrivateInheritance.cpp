

#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        Node(int data):data(data){
        }
        Node* getNext(){
            return next;
        }
        void setNext(Node* n){
            this->next = next;
        }
        int getData(){
            return data;
        }
    protected:
        int data;
        Node* next;
};

class SinglyLinkedList{
    public:
        SinglyLinkedList(){
            SinglyLinkedList(nullptr);
        }
        SinglyLinkedList(Node* head){
            this->head = head;
        }
        void Push_Front(int data){
            Node* n = new Node(data);
            if(head == nullptr){
                head = n;
                tail = n;
            }else{
                Node* newNode = new Node(data);
                head->setNext(newNode);
                head = newNode;
            }
        }
        void Push_End(int data){
            Node* n = new Node(data);
            if(tail == nullptr){
                head = n;
                tail = n;
            }else{
                tail->setNext(n);
                tail = n;
            }
        }

        int Get_Front(){
            
        }

        int Get_Back(){

        }
    protected:
        Node* head;
        Node* tail;
};

class Queue : public SinglyLinkedList{
    public:
        Node* tail;
        Queue():SinglyLinkedList(){
        }
        Queue(Node* head):SinglyLinkedList(head){
        }
        void Add(Node* n){
            cout << "SortedList Adding" << endl;
        }
        int Enqueue(){
            if(head != nullptr){
                Node* tmp = head;
                head = head->getNext();
                return tmp->getData();
            }else{
                return 0;
            }
        }
        void Dequeue(){
            if(head != nullptr){
                
            }
        }
};

class Animal{
    public:
        string name;
        Animal(){
            // cout << "Animal is created" << endl;
            this->name = "I am just an animal";
        }
        Animal(string name){
            // cout << "Animal is created" << endl;
            this->name = name;
        }
        virtual ~Animal(){
            // cout << "Animal is destroyed" << endl;
        }
        virtual string getName(){
            return this->name;
        }
};

class Cat: public Animal{
    friend void ShowName(const Cat* c);

    public:
        Cat(string name){
            // cout << "Cat is created" << endl;
            this->name = name;
        };
        virtual ~Cat() override{
            // cout << "Cat is destroyed" << endl;
        };
        string getName() override{
            return this->name;
        };

    private:
        string name;
};

void ShowName(const Cat* c){
    cout << c->name << endl;
}

int main(){
    Cat* cat = new Cat("MyCat");
    Animal* animal = cat;
    cout << cat->getName() << endl;
    cout << animal->getName() << endl;

    ShowName(cat);

    delete cat;

    Queue q;
    
}