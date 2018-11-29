#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <queue>

#include "BinaryNode.h"
#include "BinaryTree.h"

using namespace std;

template<class K, class V>
void visit(K& key, V& value){
    cout << key << endl;
}



int main(){
    // shared_ptr<BinaryNode<int>> bn1 = make_shared<BinaryNode<int>>(1);
    // shared_ptr<BinaryNode<int>> bn3 = make_shared<BinaryNode<int>>(3);
    // shared_ptr<BinaryNode<int>> bn2 = make_shared<BinaryNode<int>>(2,bn1,bn3);
    // shared_ptr<BinaryNode<int>> bn5 = make_shared<BinaryNode<int>>(5);
    // shared_ptr<BinaryNode<int>> bn4 = make_shared<BinaryNode<int>>(4,bn2,bn5);//this is root

    // BinaryTree<int> bt(bn4);

    BinaryTree<int,int> bt;
    bt.add(4,0);
    bt.add(2,0);
    bt.add(1,0);
    bt.add(3,0);
    bt.add(5,0);

    bt.preorderTraversal(visit);
    cout << endl;
    bt.inorderTraversal(visit);
    cout << endl;
    bt.postorderTraversal(visit);
    cout << endl;
    bt.breadthFirstSearch(visit);
    cout << endl;
    bt.depthFirstSearch(visit);

    string str = "Hi my name is Tetsuya. I am from Japan originally but I have been here a very long time.";
    map<char,int> frequencyMap;
    for(auto it = str.begin(); it != str.end(); it++){
        auto c = frequencyMap.find(*it);
        if(c != frequencyMap.end()){
            frequencyMap[*it] += 1;
        }else{
            frequencyMap.insert(pair<char,int>(*it,1));
        }
    }

    //priority_queue<BinaryNode<
    for(auto pair : frequencyMap){
        cout << pair.first << " " << pair.second << endl;
    }

    char c = 'A';
    cout << int(c) << endl;
}