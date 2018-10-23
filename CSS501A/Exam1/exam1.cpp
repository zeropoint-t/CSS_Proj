
#include <iostream>
#include <string>
using namespace std;

class Package{
    public:
        Package():description(""),weight(0){

        }
        Package(string desc, int wt):description(desc){
            setWeight(wt);
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
    private:
        int weight;
        string description;
};

class Node{
    public:
        Node* getNext() const{
            return this->next;
        }
        void setNext(Node* next){
            this->next = next;
        }
        Package getData() const{
            return this->data;
        }
        void setData(Package pkg){
            this->data = pkg;
        }
    private:
        Node* next;
        Package data;
};

class DeliveryManager{
    public:

    private:
        int numOfPackages;
        int numOfDronesNeeded;
        void updateDroneCounts(Node* n){
            
        }
};