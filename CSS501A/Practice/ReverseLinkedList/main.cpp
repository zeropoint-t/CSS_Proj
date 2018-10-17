
#include <iostream>
using namespace std;

class Node{
    public:
        Node(int data):data(data),next(nullptr){}
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

        Node* reverseList(Node* n){
            if(n->next == nullptr){
                return n;
            }else{
                Node* tmp = reverseList(n->next);
                n->next = nullptr;
                Node* cur = tmp;
                while(cur->next != nullptr){
                    cur = cur->next;
                }
                cur->next = n;
                return tmp;
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
    list.display();
    list.head = list.reverseList(list.head);//list.reverseList(list.head);
    cout << endl;
    list.display();
}

