
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//friend practice
class Animal{
    friend ostream& operator<<(ostream& os, const Animal& dt);
    public:
        Animal(){}
        Animal(string name, int age){
            this->name = name;
            this->age = age;
        }
        virtual void Speak(){
            cout << "I am an animal" << endl;
        };
        int getAge(){
            return this->age;
        }
        bool operator<(const Animal& an) const{
            return this->name < an.name;
        }
    private:
        string name;
        int age;
};

ostream& operator<<(ostream& os, const Animal& an)  
{  
    os << "My name is " << an.name << "and age is " << an.age << " at " << &an;
    return os;
}

bool AnimalSort(Animal& a1, Animal& a2){
    return a1.getAge() < a2.getAge();
}

int main(){

    // vector<Animal> animals1;

    Animal a1("Tetsuya",4);
    Animal a2("Charlie",6);
    Animal a3("Zareena",2);
    Animal animals[] = {a1,a2,a3};

    vector<Animal> animals2(animals, animals+3);

    Animal a4("Ahmed",7);
    animals2.push_back(a4);
    for(auto it = animals2.begin(); it != animals2.end();it++)
        cout << *it << endl;

    sort(animals2.begin(), animals2.end(), AnimalSort);
    for(auto it = animals2.begin(); it != animals2.end();it++)
        cout << *it << endl;

    cout << endl;

    for(auto it = animals2.rbegin(); it != animals2.rend();it++)
        cout << *it << endl;

    cout << animals2.at(3) << endl;
    cout << animals2[3] << endl;


    // vector<Animal> animals3(10);
}