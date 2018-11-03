
#include <iostream>
using namespace std;

class Node{
    public:
        Node(int data):data(data){}
        Node* next = nullptr;
        int data = 0;
};

class LinkedList{
    public:
        Node* head = nullptr;
        void Push_Back(int data){
            if(head == nullptr){
                head = new Node(data);
            }else{
                Node* cur = head;
                while(cur->next != nullptr){
                    cur = cur->next;
                }
                Node* newNode = new Node(data);
                cur->next = newNode;
            }
        }
};

LinkedList merge(LinkedList& list1, LinkedList& list2){
    LinkedList newList;
    Node* n1 = list1.head;
    Node* n1_prev = nullptr;
    Node* n2 = list2.head;
    Node* n2_prev = nullptr;

    if(n1 == nullptr && n2 != nullptr){
        newList.head = n2;
        return newList;
    }
    
    if(n1 != nullptr && n2 == nullptr){
        newList.head = n1;
        return newList;
    }

    newList.head = n1->data < n2->data ? n1 : n2;

    while(n1 != nullptr && n2 != nullptr){
        //move n1 forward until n1->data is larger than n2->data
        while(n1 != nullptr && n1->data < n2->data){
            n1_prev = n1;
            n1 = n1->next;
        }
        if(n2 != nullptr && n1_prev != nullptr)
            n1_prev->next = n2;

        //move n2 forward until n2->data is larger than n1->data
        while(n2 != nullptr && n1 != nullptr && n2->data < n1->data){
            n2_prev = n2;
            n2 = n2->next;
        }
        if(n1 != nullptr && n2_prev != nullptr)
            n2_prev->next = n1;
    }

    return newList;
}

void print(LinkedList& list){
    Node* cur = list.head;
    while(cur != nullptr){
        cout << cur->data << endl;
        cur = cur->next;
    }
}

int main(){
    LinkedList list1;
    list1.Push_Back(4);
    list1.Push_Back(5);
    list1.Push_Back(6);


    LinkedList list2;
    list2.Push_Back(1);
    list2.Push_Back(2);
    list2.Push_Back(3);


    LinkedList newList = merge(list1,list2);
    print(newList);
}