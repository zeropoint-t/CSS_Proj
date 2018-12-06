// 94. Binary Tree Inorder Traversal
// Medium
// 1160
// 49


// Given a binary tree, return the inorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?
#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;

        s.push(root);
        TreeNode* curNode = root;

        while(curNode->left != nullptr){
            curNode = curNode->left;
            s.push(curNode);
        }

        while(s.empty() == false){
            curNode = s.top();
            s.pop();
            v.push_back(curNode->val);
            if(curNode->right != nullptr){
                s.push(curNode->right);
                curNode = curNode->right;
            }
            
            while(curNode->left != nullptr){
                curNode = curNode->left;
                s.push(curNode);
            }
        }
        return v;
    }
};

int main(){
    Solution s;
    TreeNode* tn1 = new TreeNode(1);
    TreeNode* tn2 = new TreeNode(2);
    TreeNode* tn3 = new TreeNode(3);
    TreeNode* tn4 = new TreeNode(4);
    TreeNode* tn5 = new TreeNode(5);
    TreeNode* tn6 = new TreeNode(6);
    TreeNode* tn7 = new TreeNode(7);

    tn1->left = tn2;
    tn1->right = tn3;

    tn2->left = tn4;
    tn2->right = tn5;

    tn3->left = tn6;
    tn3->right = tn7;

    vector<int> i = s.inorderTraversal(tn1);
    for(auto it = i.begin(); it != i.end(); it++){
        cout << *it << endl;
    }
}