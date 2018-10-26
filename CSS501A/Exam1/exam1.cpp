
#include <iostream>
#include <string>
using namespace std;

class Package{
    public:
        Package(){
            // cout << "Package is created at " << this << endl;
        }
        Package(string desc, int wt):description(desc){
            // cout << "Package is created at " << this << endl;
            setWeight(wt);
        }
        ~Package(){
            // cout << "Package is destroyed at " << this << endl;
        }
        void setDescription(string desc){
            this->description = desc;
        }
        string getDescription() const{
            return this->description;
        }
        void setWeight(int wt){
            if(wt < 0)
                cout << "Weight can not be negative" << endl;

            if(wt > 1000)
                cout << "This is too heavy for drones to deliver!!" << endl;

            this->weight = wt;
        }
        int getWeight() const{
            return this->weight;
        }

        bool operator>(const Package& pkg) const{
            if(this->weight > pkg.getWeight())
                return true;
            else 
                return false;
        }
        bool operator<(const Package& pkg) const{
            if(this->weight > pkg.getWeight())
                return false;
            else 
                return true;
        }
    private:
        int weight = 0;
        string description = "";
};

class Node{
    public:
        Node(Package& pkg):next(nullptr){
            this->data = pkg;
            cout << "Node Constr Data contains package of " << &this->data << endl;
        }
        Node* getNext() const{
            return this->next;
        }
        void setNext(Node* next){
            this->next = next;
        }
        Package getData() const{
            return this->data;
        }
        void setData(Package& pkg){
            this->data = pkg;
        }
    private:
        Node* next;
        Package data;
};

class DeliveryManager{
    public:
        DeliveryManager(){}

        DeliveryManager(Package& pkg){
            add(pkg);
        }

        ~DeliveryManager(){
            Node* cur = head;
            while(cur != nullptr){
                Node* nodeToRemove = cur;
                cur = cur->getNext();
                delete nodeToRemove;
            }
        };

        void add(Package& pkg){
            Node* newNode = new Node(pkg);
            if(head == nullptr){
                head = newNode;
            }
            else{
                newNode->setNext(head);
                head = newNode;
            }
            updateDroneCounts(pkg);
            numOfPackages++;
        };

        void sort(){
            // if(numOfPackages >= 2)
            //     sort(numOfPackages-1);

            bool swapped = false;
            do{
                swapped = false;
                sort_InClassMethod(head, swapped);
            }while(swapped);
        }

        Package search(Package& pkg);

        void print(){
            Node* cur = head;
            while(cur != nullptr){
                Package p = cur->getData();
                cout << p.getDescription() << ": " << p.getWeight() << endl;
                p.setDescription("Fake Package");
                cur = cur->getNext();
            }
        }
        
    private:
        Node* head = nullptr;
        int numOfPackages = 0;
        int numOfDronesNeeded = 0;
        int totalPounds = 0;
        void updateDroneCounts(Package& pkg){
            totalPounds += pkg.getWeight();
            numOfDronesNeeded = totalPounds / 10 + 1;
        }

        void sort(int cnt){
            if(cnt == 0)
                return;

            Node* cur = head;
            Node* prev = nullptr;
            Node* next = cur->getNext();

            for(int i = 0; i < cnt; i++){   
                if(cur->getData().getWeight() < next->getData().getWeight()){
                    swap(prev,cur,next);
                }
                prev = cur;
                cur = next;
                next = next->getNext();
            }
            sort(cnt-1);
        }

        void sort_InClassMethod(Node* cur, bool& swapped){
            if(cur->getNext() == nullptr){
                return;
            }

            sort_InClassMethod(cur->getNext(),swapped);

            if(cur->getData() > cur->getNext()->getData()){
                Package tmp = cur->getNext()->getData();
                Package curPkg = cur->getData();
                cur->getNext()->setData(curPkg);
                cur->setData(tmp);
                swapped = true;
            }
        }

        void swap(Node* &prev, Node* &cur, Node* &next){
            if(prev != nullptr){
                prev->setNext(next); 
            }else{
                head = next;
            }
            cur->setNext(next->getNext());
            next->setNext(cur);

            Node* tmp = next;
            next = cur;
            cur = tmp;
        }
};

bool isEvenNumber(int num)
{
  for (int i = 0; i < num; i++)
  {
     num += i;
  }
  return true;
}

class base{
    public:
    virtual void method1(){
        cout << "Base Class" << endl;
    }
};

class derived: public base{
    public:
    void method1 () {
        cout << "derived class" << endl;
    }
};

int main(){
    base* b = new derived();
    b->method1(); 

    // isEvenNumber(5);

    Package pkg1("Package 1", 5);
    Package pkg2("Package 2", 7);
    Package pkg3("Package 3", 15);
    Package pkg4("Package 4", 3);
    Package pkg5("Package 5", 12);
    // bool pkg1_heavier = pkg1 > pkg2;

    DeliveryManager dm;
    dm.add(pkg5);
    dm.add(pkg4);
    dm.add(pkg3);
    dm.add(pkg2);
    dm.add(pkg1);

    dm.print();

    dm.sort();
    dm.print();
}