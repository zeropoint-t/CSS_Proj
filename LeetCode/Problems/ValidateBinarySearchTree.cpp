
// 98. Validate Binary Search Tree

// Medium

// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:
// •The left subtree of a node contains only nodes with keys less than the node's key.
// •The right subtree of a node contains only nodes with keys greater than the node's key.
// •Both the left and right subtrees must also be binary search trees.

// Example 1:
// Input:
//     2
//    / \
//   1   3
// Output: true

// Example 2:
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    stack<int> s;

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, root->val);
    }

    bool isValidBST(TreeNode* n, int& prevVal){
        if(n == nullptr)
            return true;
        
        bool isValid = isValidBST(n->left, n->val);

        if(!s.empty() && s.top() > n->val){
            return false;
        }
        s.push(n->val);

        cout << " Cur: " << n->val << endl;

        isValid = isValidBST(n->right, n->val);

        return isValid;
    }
};

int main(){
    // int a = 1;
    // int b = 4;
    // int *p = &a;
    // int **q = &p;
    // *q = &b;
    // *p = 5;
    // int x = a;

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(11);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    Solution s;
    bool isValidBST = s.isValidBST(root);
}