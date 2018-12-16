
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Music{
public:
    Music(string category, string title){
        this->category = category;
        this->title = title;
    }
    bool operator<(const Music& music){
        if(this->category < music.category)
            return true;
        else
            return false;
    }
    bool operator==(const Music& music){
        if(this->title == music.title && this->category == music.category)
            return true;
        else
            return false;
    }
    string category;
    string title;

};

class Node{
public:
    Node(Music music):data(music){}
    Music data;
    Node* left = nullptr;
    Node* right = nullptr;

private:
};

class MusicLibrary{
public:
    MusicLibrary(){}
    MusicLibrary(Music& music){
        AddMusic(music);
    }
    void AddMusic(Music& music){
        if(this->root == nullptr){
            this->root = new Node(music);
        }else{
            AddMusic(this->root, music);
        }
    }
    void RemoveMusic(Music& music){
        //https://www.youtube.com/watch?v=82cIlfCkCCw
        //1. root removal
        //  find the highest value from the left child and swap the value and remove the highest value
        //2. branch with 1 child removal
        //  remove the node, and point the parent of the node to point to the only child of the node
        //3. branch with 2 children removal
        //  swap the value with the left child, and point the left node to the left child of the left child of the node
        //4. leaf removal
        //  delete the leaf node and point the parent's pointer to set to nullptr
        RemoveMusic(this->root, nullptr, music);
    }
    void display(){
        display(this->root);
    }
protected:
    Node* root = nullptr;
    void AddMusic(Node* n, Music& music){
        if(music < n->data){
            if(n->left == nullptr){
                n->left = new Node(music);
                return;
            }else{
                AddMusic(n->left,music);
            }
        }else{
            if(n->right == nullptr){
                n->right = new Node(music);
                return;
            }else{
                AddMusic(n->right,music);
            }
        }
    }
    void RemoveMusic(Node* curNode, Node* parentNode, Music& music){
        if(curNode == nullptr)
            return;

        cout << curNode->data.category << endl;

        if(curNode->data == music){
            if(curNode == this->root){//root removal
                //find the next largest value next to the root to the left
                if(curNode->left != nullptr){
                    Node* n = curNode->left;
                    Node* par = curNode;
                    while(n->right != nullptr){
                        par = n;
                        n = n->right;
                    }
                    //remove the next largets value first
                    Music m = n->data;
                    RemoveMusic(n,par,n->data);
                    //swap value of root with the next highest value
                    this->root->data = m;
                }else if(curNode->right != nullptr){
                    //find the next largest value next to the root to the left
                    Node* n = curNode->right;
                    Node* par = curNode;
                    while(n->left != nullptr){
                        par = n;
                        n = n->left;
                    }
                    //remove the next largets value first
                    Music m = n->data;
                    RemoveMusic(n,par,n->data);
                    //swap value of root with the next highest value
                    this->root->data = m;
                }else{//root removal without child
                    delete curNode;
                    this->root = nullptr;
                }
            }else if(curNode->left != nullptr && curNode->right == nullptr){//left child only
                if(parentNode->left == curNode)
                    parentNode->left = curNode->left;
                else
                    parentNode->right = curNode->left;
                delete curNode;
            }else if(curNode->left == nullptr && curNode->right != nullptr){//right child only
                if(parentNode->left == curNode)
                    parentNode->left = curNode->right;
                else
                    parentNode->right = curNode->right;
                delete curNode;          
            }else if(curNode->left != nullptr && curNode->right != nullptr){//both children
                //find the next largest value next to the root
                Node* n = curNode->left;
                Node* par = curNode;
                while(n->right != nullptr){
                    par = n;
                    n = n->right;
                }
                //remove the next largest value first
                Music m = n->data;
                RemoveMusic(n,par,n->data);
                //swap value of root with the next highest value
                curNode->data = m;
            }else if(curNode->left == nullptr && curNode->right == nullptr){//leaf
                if(parentNode->left == curNode)
                    parentNode->left = nullptr;
                else
                    parentNode->right = nullptr;
                delete curNode;
            }
        }else if(music < curNode->data){
            RemoveMusic(curNode->left, curNode, music);
        }else{
            RemoveMusic(curNode->right, curNode, music);
        }
    }
    void display(Node* n){
        if(n == nullptr)
            return;
        display(n->left);
        cout << "Category: " << n->data.category << " Title: " << n->data.title << endl;
        display(n->right);
    }
private:

};

int main(){
    Music m1("AAA","Hello");
    Music m2("OOO","Hello");
    Music m3("HHH","Hello");
    Music m4("JJJ","Hello");
    Music m5("BBB","Hello");

    MusicLibrary ml;
    ml.AddMusic(m1);
    ml.AddMusic(m2);
    ml.AddMusic(m3);
    ml.AddMusic(m4);
    ml.AddMusic(m5);
    ml.display();

    cout << endl;
    ml.RemoveMusic(m1);
    ml.display();

    // Music m1("Kahki","Hello");
    // Music m2("Country","Hello");
    // Music m3("AAA","Hello");
    // Music m4("Accoustic","Hello");
    // Music m5("Decent","Hello");
    // Music m6("Ooo","Hello");
    // Music m7("Papajohns","Hello");
    // Music m8("Organize","Hello");

    // MusicLibrary ml;
    // ml.AddMusic(m1);
    // ml.AddMusic(m2);
    // ml.AddMusic(m3);
    // ml.AddMusic(m4);
    // ml.AddMusic(m5);
    // ml.AddMusic(m6);
    // ml.AddMusic(m7);
    // ml.AddMusic(m8);

    // ml.display();

    // cout << endl;
    // ml.RemoveMusic(m7);
    // ml.display();

    // Music m9("Yay","Hello");
    // Music m10("Bee","Hello");
    // ml.AddMusic(m9);
    // ml.AddMusic(m10);

    // cout << endl; 
    // ml.display();


    // cout << endl;
    // ml.RemoveMusic(m10);
    // ml.display();

    // cout << endl; 
    // ml.RemoveMusic(m7);
    // ml.display();
}