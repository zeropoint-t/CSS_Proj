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
    cout << "Key: " << key << " value: " << value << endl;
}



int main(){
    // ///////////////////////////////////////
    // //--------Left Unbalanced Tree--------
    // ///////////////////////////////////////
    // //     6
    // //   4   7
    // // 2   5
    // //1  3
    // cout << "-----Left Unbalanced Tree-----" << endl;
    // BinaryTree<int,int> bt;
    // bt.add(6,0);
    // bt.add(4,0);
    // bt.add(7,0);
    // bt.add(5,0);
    // bt.add(2,0);
    // bt.add(3,0);
    // bt.add(1,0);

    // cout << "Preorder Traversal: ";
    // bt.preorderTraversal(visit);
    // cout << endl;

    // cout << "Inorder Traversal: ";
    // bt.inorderTraversal(visit);
    // cout << endl;

    // cout << "Postorder Traversal: ";
    // bt.postorderTraversal(visit);
    // cout << endl;

    // cout << "BreadthFirstSearch Traversal: ";
    // bt.breadthFirstSearch(visit);
    // cout << endl;

    // cout << "DepthFirstSearch Traversal: ";
    // bt.depthFirstSearch(visit);
    // cout << endl;
    
    // bt.clear();

    // cout << endl;

    // ///////////////////////////////////////
    // //--------Right Unbalanced Tree--------
    // ///////////////////////////////////////
    // //     2
    // //   1   4
    // //      3  6
    // //        5  7
    // cout << "-----Right Unbalanced Tree-----" << endl;
    // bt.add(2,0);
    // bt.add(1,0);
    // bt.add(4,0);
    // bt.add(3,0);
    // bt.add(6,0);
    // bt.add(5,0);
    // bt.add(7,0);

    // cout << "Preorder Traversal: ";
    // bt.preorderTraversal(visit);
    // cout << endl;

    // cout << "Inorder Traversal: ";
    // bt.inorderTraversal(visit);
    // cout << endl;

    // cout << "Postorder Traversal: ";
    // bt.postorderTraversal(visit);
    // cout << endl;

    // cout << "BreadthFirstSearch Traversal: ";
    // bt.breadthFirstSearch(visit);
    // cout << endl;

    // cout << "DepthFirstSearch Traversal: ";
    // bt.depthFirstSearch(visit);
    // cout << endl;

    // bt.clear();

    // cout << endl;
    
    // ///////////////////////////////////////
    // //--------Balanced Tree--------
    // ///////////////////////////////////////
    // //       4
    // //   2       6
    // // 1   3   5   7
    // cout << "-----Balanced Tree-----" << endl;
    // bt.add(4,0);
    // bt.add(2,0);
    // bt.add(1,0);
    // bt.add(3,0);
    // bt.add(6,0);
    // bt.add(5,0);
    // bt.add(7,0);

    // cout << "Preorder Traversal: ";
    // bt.preorderTraversal(visit);
    // cout << endl;

    // cout << "Inorder Traversal: ";
    // bt.inorderTraversal(visit);
    // cout << endl;

    // cout << "Postorder Traversal: ";
    // bt.postorderTraversal(visit);
    // cout << endl;

    // cout << "BreadthFirstSearch Traversal: ";
    // bt.breadthFirstSearch(visit);
    // cout << endl;

    // cout << "DepthFirstSearch Traversal: ";
    // bt.depthFirstSearch(visit);
    // cout << endl;

    // bt.clear();

    // cout << endl << endl;
    


    //step 1  create a string to compress
    string str = "Hi my name is Tetsuya. I am from Japan originally but I have been here a very long time.";

    //step 2 - create a frequency table and save the unique characters
    map<char,int> frequencyMap;
    for(auto it = str.begin(); it != str.end(); it++){
        auto c = frequencyMap.find(*it);
        if(c != frequencyMap.end()){
            frequencyMap[*it] += 1;
        }else{
            frequencyMap.insert(pair<char,int>(*it,1));
        }
    }

    int numOfAlphabets = frequencyMap.size();
    char alphabets[numOfAlphabets];
    int cnt = 0;
    for(auto it = frequencyMap.begin(); it != frequencyMap.end(); it++){
        alphabets[cnt++] = (*it).first;
    }

    //step 3 - create a node for each alphabet and put them into a priority queue & save the number of alphabets
    priority_queue<BinaryNode<char,int>> pq;
    for(auto pair : frequencyMap){
        // cout << pair.first << " " << pair.second << endl;
        BinaryNode<char,int> n(pair.first, pair.second);
        pq.push(n);
    }

    //step 4 - pop 2 at a time and create a offman tree root
    while(pq.size() >= 2){
        BinaryNode<char,int> bn1 = pq.top();
        pq.pop();

        BinaryNode<char,int> bn2 = pq.top();
        pq.pop();

        BinaryNode<char,int> bn3('$',bn1.getValue() + bn2.getValue());
        bn3.setLeftChildPtr(make_shared<BinaryNode<char,int>>(bn1));
        bn3.setRightChildPtr(make_shared<BinaryNode<char,int>>(bn2));

        pq.push(bn3);
    }


    //step 5 - complete Hoffman Tree
    BinaryNode<char,int> hoffmanBT = pq.top();
    shared_ptr<BinaryNode<char,int>> nptr = make_shared<BinaryNode<char,int>>(hoffmanBT);
    BinaryTree<char,int> hoffmanTree(nptr);
    // hoffmanTree.postorderTraversal(visit);


    //step 5 create Code Table
    string codeTable[numOfAlphabets];
    for(int i = 0; i < numOfAlphabets; i++){
        hoffmanTree.displayRoot();
        string hcode = hoffmanTree.getHoffmanCode(alphabets[i]);
        hoffmanTree.displayRoot();
        cout << hcode << endl;
        codeTable[(int)alphabets[i]] = hcode;
        hoffmanTree.displayRoot();
    }
    

    // char c = 'A';
    // cout << int(c) << endl;
    int a;
    cin >> a;
}