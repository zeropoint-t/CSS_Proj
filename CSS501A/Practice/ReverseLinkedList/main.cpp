
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

            cout << "n1: " << n1 << endl;
            cout << "n2: " << n2 << endl;
            cout << "n3: " << n3 << endl;
            // Node* n4 = new Node(4);
            // Node* n5 = new Node(5);
            head = n1;
            n1->next = n2;
            n2->next = n3;
            // n3->next = n4;
            // n4->next = n5;
        }
        Node* tail;
        Node* head;

        void display(){
            Node* curNode = head;
            while(curNode != nullptr){
                cout << curNode->data << endl;
                curNode = curNode->next;
            }
        }

        Node* reverseRecursion(Node* n){
            if(n->next == nullptr){
                return n;
            }else{
                Node* tmp = reverseRecursion(n->next);
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
        
        void gfg_RecursiveReverse(Node** head_ref) 
        { 
            cout << "Pointer to  head: " << head_ref << endl;
            Node* first; 
            Node* rest; 
            
            /* empty list - head points to null*/
            if (*head_ref == nullptr) 
            return;    
        
            /* suppose first = {1, 2, 3}, rest = {2, 3} */
            first = *head_ref;   
            rest  = first->next;
        
            /* List has only one node */
            if (rest == nullptr) 
            return;
        
            /* reverse the rest list and put the first element at the end */
            gfg_RecursiveReverse(&rest); 
            first->next->next  = first;   
            
            /* tricky step -- see the diagram */
            first->next  = nullptr;           
        
            /* fix the head pointer */
            cout << "Pointer to head at the end: " << head_ref << " Chaned to " << rest << endl;
            *head_ref = rest;          
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
    // cout << endl;
    // list.printInReverseIterative();
    // cout << endl;
    // list.display();
    list.display();
    cout << endl;

    cout << &list << endl;
    cout << &list.head << endl;

    list.gfg_RecursiveReverse(&list.head);

    cout << endl;
    list.display();
}

