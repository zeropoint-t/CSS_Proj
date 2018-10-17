
#include <iostream>
using namespace std;

class Node{
    public:
        Node(int data):data(data),next(nullptr){
            cout << "Node with " << data << " is created at " << this << endl;
        }
        ~Node(){
            cout << "Node is with data " << data << " destroyed at " << this << endl;
        }
        Node* next;
        int data;
};

class LinkedList{
    public:
        LinkedList(){
            Node* n1 = new Node(1);
            Node* n2 = new Node(2);
            Node* n3 = new Node(3);
            Node* n4 = new Node(4);
            Node* n5 = new Node(5);
            head = n1;
            n1->next = n2;
            n2->next = n3;
            n3->next = n4;
            n4->next = n5;
        }
        Node* head;

        void display(){
            Node* curNode = head;
            while(curNode != nullptr){
                cout << curNode->data << endl;
                curNode = curNode->next;
            }
        }

        Node* reverseRecersion(Node* n){
            if(n->next == nullptr){
                return n;
            }else{
                Node* tmp = reverseRecersion(n->next);
                n->next = nullptr;
                Node* cur = tmp;
                while(cur->next != nullptr){
                    cur = cur->next;
                }
                cur->next = n;
                return tmp;
            }
        }

        void printInReverseRecursive(Node* n){
            if(n == nullptr)
                return;
            else {
                printInReverseRecursive(n->next);
                cout << n->data << endl;
                return;
            }
        }

        void printInReverseIterative(){

            Node* origChain = head;
            Node* newChain = new Node(origChain->data);
            Node* newHead = newChain;
            while(origChain->next != nullptr){
                origChain = origChain->next;
                Node* newNode = new Node(origChain->data);
                newChain->next = newNode;
                newChain = newChain->next;
            }

            Node* cur = newHead;
            Node* prev = nullptr;
            Node* next = nullptr;

            while(cur != nullptr){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            Node* curNode = prev;
            while(curNode != nullptr){
                cout << curNode->data << endl;
                Node* nodeToDelete = curNode;
                curNode = curNode->next;
                delete nodeToDelete;
            }
        }
        

        // Node* reverseList2(Node* n){
        //     if(n->next == nullptr){
        //         return n;
        //     }else{
        //         Node* tmp = reverseList2(n->next);
        //         n->next = nullptr;
        //         Node* cur = reverseList2(tmp);
        //         cur->next = n;
        //         return tmp;
        //     }
        // }
};

int main(int argc, const char* argv[]){

    LinkedList list;
    // list.display();
    // cout << endl;
    // list.printInReverseRecursive(list.head);
    // // list.head = list.reverseRecersion(list.head);//list.reverseList(list.head);
    cout << endl;
    list.printInReverseIterative();
    cout << endl;
    list.display();
}

