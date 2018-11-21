// Create a Node object with templated data and pointer to at least three other nodes
// Create an abstract object representing a linked structure that meets the following criteria:
//      Constructors
//          Given a data point
//          Given a single node
//          Given a node with links to other nodes (copy constructor; perform deep copy)
//      Actions
//          One unimplemented method for searching through the structure (pure virtual)
//          One method to be overridden for printing the structure (virtual)
// Create a child object that inherits the abstract linked structure
//      Implement an iterative search algorithm and print method (iterators optional)
// Create another child object that inherits the abstract linked structure
//      Implement a recursive search algorithm and print method



#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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
        void display(Node<T>* n){
            for(auto it = n->begin(); it != n->end(); it++){
                cout << (*it)->getData() << endl;
            }
        }

    private:
        T data;
        vector<Node<T>*> nodes;
};

template<class T>
class LinkedStructure{
    public:
        LinkedStructure(T d){
            Node<T>* rt = new Node<T>(d);
            this->root = rt;
        }

        LinkedStructure(Node<T>* n){
            this->root = n;
        }

        LinkedStructure(const LinkedStructure<T>& ls){
            Node<T>* origRoot = ls.getRoot();
            Node<T>* rt = new Node<T>(origRoot->getData());
            this->root = rt;
            DeepCopy(this->root, origRoot);
        }

        virtual Node<T>* search(T value) = 0;

        virtual void print(Node<T>* n = nullptr){
            if(n == nullptr){
                n = this->root;
                cout << n->getData() << endl;
            }
            for(auto it = n->begin(); it != n->end(); it++){
                cout << (*it)->getData() << endl;
                print(*it);
            }
        }

    protected:
        Node<T>* root;
        Node<T>* getRoot(){
            return this->root;
        }
    private:
        void DeepCopy(Node<T>* newNode, Node<T>* origNode){
            for(auto it = origNode->begin(); it != origNode->end(); it++){
                Node<T>* nn = new Node<T>((*it)->getData());
                newNode->Add(nn);
                DeepCopy(nn,*it);
            }
        }
};

template<class T>
class RecursiveLinkedStructure: public LinkedStructure<T>{
    public:
        RecursiveLinkedStructure(T d):LinkedStructure<T>(d){
            Node<T>* rt = new Node<T>(d);
            this->root = rt;
        }

        RecursiveLinkedStructure(Node<T>* n):LinkedStructure<T>(n){
            this->root = n;
        }

        RecursiveLinkedStructure(const LinkedStructure<T>& ls):LinkedStructure<T>(ls){
        }

        virtual Node<T>* search(T value) override{
            if(this->root->getData() == value)
                return this->root;
                
            return search(this->root, value);
        }

    private:
        //search using recursive
        Node<T>* search(Node<T>* n, T value){
            Node<T>* found = nullptr;
            for(auto it = n->begin(); it != n->end(); it++){
                if((*it)->getData() == value){
                    return *it;
                }
                found = search(*it, value);
            }
            return found;
        }
};

template<class T>
class IterativeLinkedStructure: public LinkedStructure<T>{
    public:
        IterativeLinkedStructure(T d):LinkedStructure<T>(d){
            Node<T>* rt = new Node<T>(d);
            this->root = rt;
        }

        IterativeLinkedStructure(Node<T>* n):LinkedStructure<T>(n){
            this->root = n;
        }

        IterativeLinkedStructure(const LinkedStructure<T>& ls):LinkedStructure<T>(ls){
        }

        virtual Node<T>* search(T value) override{
            
            return nullptr;
        }

        void print(Node<T>* n = nullptr) override {
            if(n == nullptr)
                n = this->root;

            if(n == nullptr)
                return;

            queue<Node<T>*> q;
            q.push(n);
            while(!q.empty()){
                Node<T>* front = q.front();
                q.pop();
                for(auto it = front->begin(); it != front->end(); it++){
                    q.push(*it);
                }
                cout << front->getData() << endl;
            }
        }
    private:

};

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i>j);}
} myobject;

class CustomClass{
    friend ostream& operator<<(ostream& os, const CustomClass& dt);
    public:
        CustomClass():data(0){}
        CustomClass(int d):data(d){}
        int getData() const{
            return data;
        }
        bool operator<(const CustomClass& cc){
            return this->getData() < cc.getData();
        }
    private:
        int data;
};

ostream& operator<<(ostream& os, const CustomClass& dt)  
{  
    os << dt.getData();
    return os;  
}  

int main(){
    // vector<CustomClass> vi (10);
    // for(auto it = vi.begin(); it != vi.end(); it++){
    //     cout << *it << " ";
    // }
    // CustomClass& ccs= vi[2];
    // cout << ccs << endl;
    // cout << vi.pop_back() << endl;


    // CustomClass cc1(23);
    // CustomClass cc2(15);
    // CustomClass cc3(12);
    // CustomClass cc4(63);
    // CustomClass cc5(28);
    // CustomClass myCC[] = {cc1,cc2,cc3,cc4,cc5};
    // std::vector<CustomClass> myccvector (myCC, myCC+5); 
    // std::sort(myccvector.begin(), myccvector.end());
    // for(auto it = myccvector.begin(); it != myccvector.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // int myints[] = {32,71,12,45,26,80,53,33};
    // std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33
    // cout << myints << endl;
    // cout << myints + 8 << endl;

    // // using default comparison (operator <):
    // std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
    // for(auto it = myvector.begin(); it != myvector.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // // using function as comp
    // std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
    // for(auto it = myvector.begin(); it != myvector.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // // using object as comp
    // std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
    // for(auto it = myvector.begin(); it != myvector.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    // // print out content:
    // std::cout << "myvector contains:";
    // for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    // std::cout << ' ' << *it;
    // std::cout << '\n';



    Node<int> n(10);
    Node<int>* n1 = new Node<int>(20);
    Node<int>* n2 = new Node<int>(30);
    Node<int>* n3 = new Node<int>(40);
    Node<int>* n4 = new Node<int>(50);
    Node<int>* n5 = new Node<int>(60);
    Node<int>* n6 = new Node<int>(70);
    Node<int>* n7 = new Node<int>(80);
    Node<int>* n8 = new Node<int>(90);
    Node<int>* n9 = new Node<int>(100);
    Node<int>* n10 = new Node<int>(110);
    Node<int>* n11 = new Node<int>(120);
    n.Add(n1);
    n.Add(n2);
    n.Add(n3);
    n1->Add(n4);
    n1->Add(n5);
    n2->Add(n6);
    n2->Add(n7); 
    n3->Add(n8);
    n3->Add(n9); 
    n9->Add(n10); 
    n9->Add(n11); 


    cout << endl;

    RecursiveLinkedStructure<int> dls1(&n);
    dls1.print();
    Node<int>* srch = dls1.search(100);
    if(srch != nullptr)
        cout << "Found value is " << srch->getData() << endl;
    else
        cout << "Value not found" << endl;

    cout << endl;   

    IterativeLinkedStructure<int> dls2(&n);
    dls2.print();
    srch = dls2.search(100);
    if(srch != nullptr)
        cout << "Found value is " << srch->getData() << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}