// 83. Remove Duplicates from Sorted List
// Easy

// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3

#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {
        
    }
};

Node* deleteDuplicates(Node* head) {
    map<int,int> m;
    Node* cur = head;
    m.insert(pair<int,int>(cur->val, 0));
    Node* prev = cur;
    cur = cur->next;
    while(cur != nullptr){
        auto n = m.find(cur->val);
        if(n != m.end()){//duplciate exists
            prev->next = cur->next;
            Node* nodeToRemove = cur;
            cur = cur->next;
            delete nodeToRemove;
        }
        else{
            m.insert(pair<int,int>(cur->val, 0));
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}


void print(Node* head){
    Node* cur = head;
    while(cur != nullptr){
        cout << cur->val << endl;
        cur = cur->next;
    }
}
int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(1);
    Node* n3 = new Node(1);
    Node* n4 = new Node(2);
    Node* n5 = new Node(2);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    print(n1);
    deleteDuplicates(n1);
    print(n1);
}