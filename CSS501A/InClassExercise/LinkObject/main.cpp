
#include <iostream>
#include "LinkObject.cpp"
#include "Node.cpp"
using namespace std;

int main(int argc, const char* argv[]){

    Node* n1 = new Node("Node1");
    //remove test
    LinkedList ll;

    //insert only 1 node
    ll.insert(n1);
    ll.displayForward();
    cout << endl;
    ll.remove(0);
    ll.displayForward();

    //insert 2 nodes
    Node* n2 = new Node("Node2");
    Node* n3 = new Node("Node3");
    ll.insert(n2);
    ll.insert(n3);
    ll.displayForward();
    cout << endl;
    ll.remove(1);
    ll.displayForward();
    cout << endl;

    ll.clear();

    Node* n4 = new Node("Node4");
    Node* n5 = new Node("Node5");
    Node* n6 = new Node("Node6");
    Node* n7 = new Node("Node7");
    ll.insert(n4);
    ll.insert(n5);
    ll.insert(n6);
    ll.insert(n7);
    ll.displayForward();
    cout << endl;
    ll.remove(3);
    ll.displayForward();
    cout << endl;

    //insert at the end test
    Node* n8 = new Node("Node8");
    ll.insert(n8,3);
    ll.displayForward();

    ll.clear();
}