
// 86. Partition List

// Medium

// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5


#include <iostream>
#include <string>

using namespace std;

//  * Definition for singly-linked list.
 struct Node {
      int val;
      Node *next;
      Node(int x) : val(x), next(nullptr) {}
 };
 
Node* partition(Node* head, int x) {
    
    Node* pointerNode = head;//keeps track of the next insertion point
    Node* curNode = head;//keeps track of curret node in the iteration
    Node* prevNode = nullptr;//keeps track of the previous node of the curNode

    while(curNode != nullptr){
        cout << curNode->val << endl;
        //move curNode forward untill its nullptr or while curNode->val is greater than or equal to x
        while(curNode != nullptr && curNode->val >= x){
            prevNode = curNode;
            curNode = curNode->next;
            if(curNode != nullptr)
                cout << curNode->val << endl;
        }
        //at this point curNod is pointing to the next value that is smaller than X

        //if curNode is pointing to nullptr, there was no value less than x so just exit the loop
        if(curNode == nullptr)
            break;

        //save the curNode into insertNode
        Node* insertNode = curNode;

        //move curNode to next so curNode won't keep pointing to insertNode
        curNode = curNode->next;

        //only when insertion point and curNode are different
        if(pointerNode != insertNode){
            //start rewire nodes
            if(prevNode != nullptr)
                prevNode->next = insertNode->next;//skip the node curNode originally pointed to
            //point the insertNode' next to the pointer's next
            insertNode->next = pointerNode->next;
            //set pointer's next to inserNode
            pointerNode->next = insertNode;
            //then move the pointer forward 1
            pointerNode = pointerNode->next;
        }
    }

    return head;

}

void display(Node* head){
    while(head != nullptr){
        cout << head->val << " - ";
        head = head->next;
    }
}

int main(){
    Node* n_orig = new Node(1);
    Node* n = n_orig;
    n->next = new Node(4);
    n = n->next;
    n->next = new Node(3);
    n = n->next;
    n->next = new Node(2);
    n = n->next;
    n->next = new Node(5);
    n = n->next;
    n->next = new Node(2);
    n = n->next;
    n->next = new Node(2);
    n = n->next;
    n->next = new Node(8);
    n = n->next;
    n->next = new Node(6);
    n = n->next;
    n->next = new Node(1);
    n = n->next;
    n->next = new Node(4);
    n = n->next;

    display(n_orig);
    cout << endl;

    Node* head = partition(n_orig,3);
    display(head);
    cout << endl;
}