
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

template <class T>
class Node{
	public:
        Node(T t);
        
        //nodes
        Node* node1 = nullptr;
        Node* node2 = nullptr;
        Node* node3 = nullptr;
        
        bool search(T data);
        void print();
        
        ///setters and getters
        T getData();
        void setData(T t);
    
  private:
  	T data;
};

template<class T>
class MG{
public:
  
  virtual bool search(T data);//=0;
  
  virtual void print();
  
  MG(T t);
  MG(Node<T> * n);
  MG(const MG& mg);//copy constructor
protected:
    Node<T> * root;
private:
    void DeepCopy(Node<T>* newNode, Node<T>* origNode);
    bool search(Node<T>* n, T d);
};

template<class T>
MG<T>::MG(T data){
    this->root = new Node<T>(data);
}

template<class T>
MG<T>::MG(Node<T>* n){
    this->root = n;
}

template<class T>
MG<T>::MG(const MG& mg){
	if(mg.root != nullptr){
        this->root = new Node<T>(mg.root->getData());
        DeepCopy(this->root, mg.root);
    }
}

template<class T>
void MG<T>::DeepCopy(Node<T>* newNode, Node<T>* origNode){
    if(origNode->node1 != nullptr){
      	Node<T>* n = new Node<T>(origNode->node1->getData());
        newNode->node1 = n;
        DeepCopy(newNode->node1, origNode->node1);
    }
    if(origNode->node2 != nullptr){
      	Node<T>* n = new Node<T>(origNode->node2->getData());
        newNode->node2 = n;
        DeepCopy(newNode->node2, origNode->node2);
    }
    if(origNode->node3 != nullptr){
        Node<T>* n = new Node<T>(origNode->node3->getData());
        newNode->node3 = n;
        DeepCopy(newNode->node3, origNode->node3);
    }
}

template<class T>
bool MG<T>::search(T data){
    // return this->root->search(data);
    if(this->root != nullptr){
        return this->search(this->root, data);
    }else{
        return false;
    }
}

template<class T>
bool MG<T>::search(Node<T>* n, T d){
    bool found = false;
    if(n->getData() == d)
        found = true;

    if(n->node1 != nullptr && !found)
        found = search(n->node1, d);
    if(n->node2 != nullptr && !found)
        found = search(n->node2, d);
    if(n->node3 != nullptr && !found)
        found = search(n->node3, d);

    return found;
}

template<class T>
bool Node<T>::search(T data){
    bool found = false;
    if(this->data == data) {
      found = true;
    }
  
    if(node1 != nullptr && !found){
		found = node1->search(data);
    }
    if(node2 != nullptr && !found){
		found = node2->search(data);
    }
    if(node3 != nullptr && !found){
        found = node3->search(data);
    }
  
    return found;
}

template<class T>
void Node<T>::print(){
  cout << this->data;
  
  if(node1 != nullptr){
		this->node1->print();
  }
  if(node2 != nullptr){
		this->node2->print();
  }
  if(node3 != nullptr){
		this->node3->print();
  }
}

template<class T>
void MG<T>::print(){
	this->root->print();
}

template<class T>
T Node<T>::getData(){
	return data;
}

template<class T>
Node<T>::Node(T d){
	this->data = d;
}

template<class T>
class IterativeMG: public MG<T>{
    public:
        IterativeMG(T d):MG<T>(d){}
        IterativeMG(Node<T>* n):MG<T>(n){}
        IterativeMG(const MG<T>& mg):MG<T>(mg){}
        bool search(T data) override{
            if(this->root == nullptr)
                return false;
            
            queue<Node<T>*> q;
            q.push(this->root);

            while(q.empty() == false){
                Node<T>* front = q.front();
                q.pop();
                if(front->getData() == data){
                    return true;
                }
                else{
                    if(front->node1 != nullptr)
                        q.push(front->node1);
                    if(front->node2 != nullptr)
                        q.push(front->node2);
                    if(front->node3 != nullptr)
                        q.push(front->node3);
                }
            }
            return false;
        }
};


class Parent
{
  private:
    string name;
  public:
    Parent(string name)
    {
      this->name = name;
      cout << this->name << endl;
    }
};

class Child : Parent
{
  public:
    Child(string name) : Parent(name) { }
};


int main(){

Child c("Adam");

    Node<int> n(5);
    Node<int> n1(10);
    Node<int> n2(20);
    Node<int> n3(30);
    Node<int> n4(40);
    Node<int> n5(50);
    n3.node1 = &n4;
    n2.node2 = &n5;
    n.node1 = &n1;
    n.node2 = &n2;
    n.node3 = &n3;
    MG<int> mg(&n);

    cout << mg.search(22) << endl;

    MG<int> newMG(mg);

    IterativeMG<int> img(mg);
    cout << img.search(22) << endl;
}