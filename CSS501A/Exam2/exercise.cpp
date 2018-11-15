
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
class Node{
    public:
        Node(T d){
            this->data = d;
        }
        Node(Node<T>* n){
            nodes.push_back(n);
        }
        Node(const Node<T>& n){
            
        }
        ~Node(){}
        T getData(){
            return data;
        }
        void Add(Node<T>* pn){
            this->nodes.push_back(pn);
        }
        void Remove(Node<T>* pn){
            this->nodes.erase(pn);
        }
        typename vector<Node<T>*>::iterator begin(){
            return this->nodes.begin();
        }
        typename vector<Node<T>*>::iterator end(){
            return this->nodes.end();
        }
        void display(){
            for(auto it = nodes.begin(); it != nodes.end(); it++){
                cout << (*it)->getData() << endl;
            }
        }

    private:
        T data;
        vector<Node<T>*> nodes;
};

int main(){
    Node<int> n(10);
    Node<int>* n1 = new Node<int>(20);
    Node<int>* n2 = new Node<int>(30);
    Node<int>* n3 = new Node<int>(40);
    n.Add(n1);
    n.Add(n2);
    n.Add(n3);
    n.display();
    return 0;
}