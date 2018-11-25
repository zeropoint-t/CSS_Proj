#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Contact{
    string FirstName;
    string LastName;
    long MobileNumber;
};

bool sortByLastName(Contact*& c1, Contact*& c2){
    return c1->LastName < c2->LastName;
}

class ContactList{
    public:
        ContactList(){}
        ContactList(const ContactList& cl){
            
        }
        virtual void Add(Contact* ct) = 0;
        virtual Contact* Find(string lastName){
            return nullptr;
        }
        virtual void Remove(string lastName){

        }
    protected:
        vector<Contact*> contacts;
    private:

};

class AddressBook : public ContactList{
    public:
        AddressBook():ContactList(){}
        AddressBook(const AddressBook& ab): ContactList(ab){

        }
        void Add(Contact* ct) override{
            this->contacts.push_back(ct);
            sort(this->contacts.begin(),this->contacts.end(),sortByLastName);
        }
        void print(){
            for(auto it : this->contacts){
                cout << (it)->LastName << endl;
            }
        }
    protected:

    private:
};

class CallHistory{
    public:

    protected:

    private:
};

int main(){
    cout << "Hello World" << endl;
    AddressBook ab;

    Contact c1;
    c1.FirstName = "Tetsuya";
    c1.LastName = "Hayashi";
    c1.MobileNumber = 6308653432;

    Contact c2;
    c2.FirstName = "Erin";
    c2.LastName = "Nadolny";
    c2.MobileNumber = 6309654789;

    Contact c3;
    c3.FirstName = "Ohnono";
    c3.LastName = "Zyaya";
    c3.MobileNumber = 6589774878;

    ab.Add(&c1);
    ab.Add(&c2);
    ab.Add(&c3);

    ab.print();
}