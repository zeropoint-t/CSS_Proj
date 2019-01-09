
// 101. Symmetric Tree

// Easy
// 172736FavoriteShare


// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric: 
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3

// But the following [1,2,2,null,3,null,3] is not:

//     1
//    / \
//   2   2
//    \   \
//    3    3

// Note:
//  Bonus points if you could solve it both recursively and iteratively. 

#include <iostream>
#include <stack>
using namespace std;

//Definition for a binary tree node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    bool isSymmetric(Node* root) {
        this->root = root;
        bool isSymmetric = checkSymmetry(this->root);
        //if stack is not empty after all calls, left subtree has more nodes & asymmetrical
        if(!s.empty())
            return false;
        else
            return isSymmetric;
    }
private:
    bool checkSymmetry(Node* n) {
        bool isSymmetric = true;
        if(n == nullptr){
            return true;
        }
        
        //left node traversal
        isSymmetric = checkSymmetry(n->left);

        if(isSymmetric){
            cout << n->val << endl;

            //middle part between left & right node traversals
            //only if traversal passed root node
            if(this->isRootPassed){
                //if stack is empty, right subtree has more nodes & it is asymmetrical
                //if stack.top().val is different from current node val, it is also asymmetrical
                cout << "Stack empty: " << s.empty() << endl;
                if(s.empty() || s.top() != n->val){
                    isSymmetric = false;
                }
                s.pop();
            //if still on the left side of root, push it to stack
            }else if(n != this->root){
                s.push(n->val);
            }
        }

        //if n is root, flag isRootPassed to true
        if(n == this->root)
            this->isRootPassed = true;

        //right node traversal only if it is still symmetrical
        if(isSymmetric){
            isSymmetric = checkSymmetry(n->right);
        }
        
        return isSymmetric;
    }

    Node* root = nullptr;
    stack<int> s;
    bool isRootPassed = false;
};

int main(){
    // Node root(1);
    // root.left = new Node(2);
    // // root.left->left = new Node(3);
    // root.left->right = new Node(3);
    // root.right = new Node(2);
    // // root.right->left = new Node(4);
    // root.right->right = new Node(3);

    Node root(1);
    root.left = new Node(2);
    root.left->left = new Node(3);
    root.left->left->right = new Node(2);
    root.left->right = new Node(4);

    root.right = new Node(2);
    root.right->left = new Node(4);
    root.right->right = new Node(2);

    Solution s;
    bool isSymmetric = s.isSymmetric(&root);
}