#include <iostream>
using namespace std;

int getFactorialByValue(int number){
    if(number > 1){
        number = number * getFactorialByValue(number-1);
    }
    return number;
}

int& getFactorialByRef(int& number){
    if(number > 1){
        int nextNum = number-1;
        return number = number * getFactorialByRef(nextNum);
    }
    return number;
}

int* getFactorialByPtr(int* number){
    if(*number > 1){
        *number = *number - 1;
        *number = *number * *getFactorialByPtr(number);
    }
    return number;
}

class Node{
    public:
        Node(int d):data(d),next(nullptr),prev(nullptr){}
        Node* next;
        Node* prev;
        int data;
};

class LinkedList{
    public:
        LinkedList(){
            Node* n1 = new Node(1);
            Node* n2 = new Node(2);
            Node* n3 = new Node(3);
            head = n1;
            tail = n3;
            n1->next = n2;
            n2->prev = n1;
            n2->next = n3;
            n3->prev = n2;
        }
        void displayForward(){
            Node* curNode = head;
            while(curNode != nullptr){
                cout << curNode->data << endl;
                curNode = curNode->next;
            }
            cout << endl;
        }
        void displayBackward(){
            Node* curNode = tail;
            while(curNode != nullptr){
                cout << curNode->data << endl;
                curNode = curNode->prev;
            }
            cout << endl;
        }

        void swap(){
            Node* n1 = head->next;
            Node* n2 = head->next->next;
            swapNodes(n1,n2);
            // Node* temp = head->next;
            // head->next = temp->next;
            // temp->next->prev = head;
            // temp->prev = nullptr;
            // temp->next = head;
            // head->prev = temp;

            // head = temp;
            // tail = head->next->next;
        }

        void swapNodes(Node* &n1, Node* &n2){
            if(n1 != nullptr && n2 != nullptr){
                Node* next = n2->next;
                Node* prev = n1->prev;

                //1. rewire next
                if(next != nullptr){
                    next->prev = n1;
                }else{
                    //if next is null, n1 will be the last node in the list so tail needs to point to it
                    tail = n1;
                }

                //2. rewire n2
                n2->next = n1;
                n2->prev = prev;

                //3. rewire n1
                n1->next = next;
                n1->prev = n2;

                //4. rewire prev
                if(prev != nullptr){
                    prev->next = n2;
                }else{
                    //if prev is nullptr, n2 will be the first node in the list so head needs to point to it
                    head = n2;
                }

                // swap n1 & n2;
                Node* temp_n1 = n1;
                n1 = n2;
                n2 = temp_n1;
            }
        }

        Node* head;
        Node* tail;
};

int main (int argc, const char* argv[]){

    // LinkedList list;
    // list.displayForward();
    // list.displayBackward();

    // list.swap();
    // list.displayForward();
    // list.displayBackward();

    // int factorialByVal = getFactorialByValue(5);
    // cout << factorialByVal << endl;

    // int number = 5;
    // int factorialByRef = getFactorialByRef(number);
    // cout << factorialByVal << endl;

    // int num = 5;
    // int* pNum = &num;
    // int factorialByPtr = *getFactorialByPtr(pNum);
    // cout << factorialByVal << endl;
}