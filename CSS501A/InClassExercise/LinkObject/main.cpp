
#include <iostream>
#include "LinkObject.cpp"
#include "Node.cpp"
using namespace std;

int main(int argc, const char* argv[]){
    Node* n1 = new Node("Tetsuya");
    Node* n2 = new Node("am");
    Node* n3 = new Node("I ");
    Node* n4 = new Node("super");

    LinkedList ll;
    ll.insert(n1);
    ll.insert(n2);
    ll.insert(n3);

    bool isSuccess = ll.insert(n4,2);
    ll.display();

    cout << endl;

    bool isRemoved = ll.remove(3);
    ll.display();
}