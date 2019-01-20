

#include <iostream>
#include <string>

using namespace std;

class BinaryTreeNode{
    public:
        BinaryTreeNode(int* item):item(item),leftChild(NULL),rightChild(NULL){}
        ~BinaryTreeNode(){
            // delete item;
            delete leftChild;
            delete rightChild;
        }
        int* item;
        BinaryTreeNode* leftChild;
        BinaryTreeNode* rightChild;
};

void inOrderTraversal(BinaryTreeNode*& n){
    if(n == NULL)
        return;

    inOrderTraversal(n->leftChild);
    cout << *n->item << endl;
    inOrderTraversal(n->rightChild);
}

//insert-----------------------------------
void insert_rec(BinaryTreeNode *&root, int* item) 
{
    if (root == NULL) 
    {
        root = new BinaryTreeNode(item);
    }else if (*item < *root->item)
    {
        insert_rec(root->leftChild, item);
    } else{
        insert_rec(root->rightChild, item);
    }
}

void insert_iter(BinaryTreeNode *&root, int* item) 
{
    BinaryTreeNode *node = new BinaryTreeNode(item);
    
    if  (root == NULL)
    {
        root = node;
    } else 
    {
        BinaryTreeNode *cur = root;
        while (true) 
        {
            if (*item < *cur->item)
            {       
                if(cur->leftChild == NULL) 
                {
                    cur->leftChild = node;
                    return;
                }else 
                {
                    cur = cur->leftChild;
                }
            } else if(cur->rightChild == NULL) 
            {
                cur->rightChild = node;
                return;
            }else 
            {
                cur = cur->rightChild;
            }
        }
    }
}

//remove node------------------------------------------

// Pre-condition: root is not NULL
int *findAndDeleteMostLeft(BinaryTreeNode *&root) 
{
    if (root->leftChild == NULL) 
    {
        int* item = root->item;
        BinaryTreeNode *tmp = root;
        root = root->rightChild;//promote right child to be the root
        delete tmp;
        return item;
    }
    else 
    {
        return findAndDeleteMostLeft(root->leftChild);
    }
}


void deleteRoot(BinaryTreeNode *&root) 
{
    if (root->leftChild == NULL && root->rightChild == NULL) 
    {
        delete root->item;
        delete root;
        root = NULL;
    } else if (root->leftChild == NULL) 
    {
        BinaryTreeNode *tmp = root;
        root = root->rightChild;
        delete tmp->item;
        delete tmp;
    } else if (root->rightChild == NULL) {
        BinaryTreeNode *tmp = root;
        root = root->leftChild;
        delete tmp->item;
        delete tmp;
    } else 
    {
        delete root->item;
        root->item = findAndDeleteMostLeft(root->rightChild);
    }
}

bool deleteNode(BinaryTreeNode *&root, const int &item) 
{
	if (root == NULL)
    {
        return false;
    }else if (item == *root->item) 
    {
        deleteRoot(root);
        return true;
	}else if (item < *root->item){
        return deleteNode(root->leftChild, item);
    }else{
		return deleteNode(root->rightChild, item);
	}
}

int main(){
    BinaryTreeNode* btn10 = new BinaryTreeNode(new int(10));
    BinaryTreeNode* btn6 = new BinaryTreeNode(new int(6));
    BinaryTreeNode* btn5 = new BinaryTreeNode(new int(5));
    BinaryTreeNode* btn4 = new BinaryTreeNode(new int(4));
    BinaryTreeNode* btn9 = new BinaryTreeNode(new int(9));
    BinaryTreeNode* btn13 = new BinaryTreeNode(new int(13));
    BinaryTreeNode* btn12 = new BinaryTreeNode(new int(12));
    BinaryTreeNode* btn15 = new BinaryTreeNode(new int(15));

    btn10->leftChild = btn6;
    btn6->leftChild = btn5;
    btn5->leftChild = btn4;
    btn6->rightChild = btn9;
    btn10->rightChild = btn13;
    btn13->leftChild = btn12;
    btn13->rightChild = btn15;

    inOrderTraversal(btn10);
    cout << endl;

    insert_rec(btn10, new int(11));

    inOrderTraversal(btn10);
    cout << endl;

    deleteNode(btn10,10);

    inOrderTraversal(btn10);
    cout << endl;
}