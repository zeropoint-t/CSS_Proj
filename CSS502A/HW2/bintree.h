
#ifndef BINTREE_H
#define BINTREE_H

#include <string>
#include <iostream>
#include <fstream>
#include "nodedata.h"
using namespace std;

class BinTree;
ostream & operator << (ostream &out, const BinTree &bt) 
{
    return out; 
}

class BinTree {				// you add class/method comments and assumptions

    friend ostream & operator << (ostream &out, const BinTree &bt);

public:
	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	BinTree& operator=(const BinTree &);
	bool operator==(const BinTree &) const;
	bool operator!=(const BinTree &) const;
	bool insert(NodeData*);
	bool retrieve(const NodeData&, NodeData*) const;
    int getHeight(const NodeData&) const;
	void displaySideways() const;			// provided below, displays the tree sideways
    void bstreeToArray(NodeData* []);
    void arrayToBSTree(NodeData* []);

private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

    // utility functions
    void inorderHelper() const;
    void sideways(Node*, int) const;		// provided below, helper for displaySideways()
    void deleteNode(Node*);                 //provides a way to release memories for the entire tree
    void findNodeHelper(Node*, const NodeData&, Node*&) const;
    int getHeightHelper(const Node*) const;//helper method to calculate height
    int getMax(int l, int r) const;//find maximum of 2 int
    bool insertHelper(Node*&, NodeData*);//helper method to insert
    NodeData* deepCopy(Node*, Node*&);//helper method to deep copy
};

//default constructor
BinTree::BinTree():root(NULL){
}

//copy constructor - deep copy
BinTree::BinTree(const BinTree & bt){
    if(bt.root != NULL)
    {
        root = new Node();
        root->data = deepCopy(bt.root, root);
    }
}

//destructor
BinTree::~BinTree(){
    // delete trees in post order
    deleteNode(root);
}	

// --BinTree::getHeight(const NodeData& nd) const----------------------------------------------------
// Description: returns a height from a node through the longest path to the leaf for the NodeData
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------------------------------
int BinTree::getHeight(const NodeData& nd) const{
    Node* n = NULL;
    findNodeHelper(root, nd, n);
    if(n != NULL)
    {
        return getHeightHelper(n);
    }else
    {
        return 0;
    }
}

// --BinTree::getHeight(const NodeData& nd) const----------------------------------------------------
// Description: finds & sets a node pointer that contains tgtNodeData to foundNode if exists
// Preconditions: foundNode is NULL
// Postconditions: foundNode points to a node that contains tgtNodeData 
// --------------------------------------------------------------------------------------------------
void BinTree::findNodeHelper(Node* root, const NodeData& tgtNodeData, Node*& foundNode) const{
    //didn't find it in this path
    if(root == NULL)
        return;

    //found the node that contains tgtNodeData
    //set the pointer to foundNode and return
    if(*(root->data) == tgtNodeData){
        foundNode = root;
        return;
    }

    //go left
    findNodeHelper(root->left, tgtNodeData, foundNode);

    //go right if not found yet
    if(foundNode == NULL){
        findNodeHelper(root->right, tgtNodeData, foundNode);
    }
}

// --BinTree::insert(NodeData* n)--------------------------------------------------------------------
// Description: Inserts a NodeData object and returns true if successful. 
//              Returns false if duplicate is found
// Preconditions: NONE
// Postconditions: BinTree will contain a new node
// --------------------------------------------------------------------------------------------------
bool BinTree::insert(NodeData* n){
    return insertHelper(root, n);
}

bool BinTree::insertHelper(Node*& n, NodeData* nd){
    if(n == NULL)
    {
        n = new Node();
        n->data = nd;
        n->left = NULL;
        n->right = NULL;
        return true;
    }
    
    //duplicate
    if(*nd == *(n->data))
    {
        return false;
    }
    //less, go left
    else if(*nd < *(n->data))
    {
        return insertHelper(n->left, nd);
    }
    //more, go right
    else
    {
        return insertHelper(n->right, nd);
    }
}

NodeData* BinTree::deepCopy(Node* origNode, Node*& newNode){
    if(origNode == NULL)
        return NULL;

    newNode->data = new NodeData(*origNode->data);

    if(origNode->left != NULL){
        newNode->left = new Node();
        newNode->left->left = NULL;
        newNode->left->right = NULL;
        NodeData* leftNodeData = deepCopy(origNode->left, newNode->left);

        if(leftNodeData != NULL){
            newNode->left->data = leftNodeData;
        }
    }

    if(origNode->right != NULL){
        newNode->right = new Node();
        newNode->right->left = NULL;
        newNode->right->right = NULL;
        NodeData* rightNodeData = deepCopy(origNode->right, newNode->right);

        if(rightNodeData != NULL){
            newNode->right->data = rightNodeData;
        }
    }

    return newNode->data;
}

int BinTree::getHeightHelper(const Node* n) const{
    if(n == NULL)
        return 0;

    return 1 + getMax(getHeightHelper(n->left), getHeightHelper(n->right));
}

int BinTree::getMax(int l, int r) const{
    return l > r ? l : r;
}


void BinTree::deleteNode(Node* root){
    if(root == NULL)
        return;

    deleteNode(root->left);
    deleteNode(root->right);
    delete root;
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}

#endif