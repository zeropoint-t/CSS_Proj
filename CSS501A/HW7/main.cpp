#include <iostream>
#include <string>
#include <memory>
#include "BinaryNode.h"
#include "BinaryTree.h"

using namespace std;

template<class T>
void visit(T& item){
    cout << item << endl;
}

int main(){
    // shared_ptr<BinaryNode<int>> bn1 = make_shared<BinaryNode<int>>(1);
    // shared_ptr<BinaryNode<int>> bn3 = make_shared<BinaryNode<int>>(3);
    // shared_ptr<BinaryNode<int>> bn2 = make_shared<BinaryNode<int>>(2,bn1,bn3);
    // shared_ptr<BinaryNode<int>> bn5 = make_shared<BinaryNode<int>>(5);
    // shared_ptr<BinaryNode<int>> bn4 = make_shared<BinaryNode<int>>(4,bn2,bn5);//this is root

    // BinaryTree<int> bt(bn4);

    BinaryTree<int> bt;
    bt.add(4);
    bt.add(2);
    bt.add(1);
    bt.add(3);
    bt.add(5);

    bt.preorderTraversal(visit);
    cout << endl;
    bt.inorderTraversal(visit);
    cout << endl;
    bt.postorderTraversal(visit);
    cout << endl;
    bt.breadthFirstSearch(visit);
    cout << endl;
    bt.depthFirstSearch(visit);
}