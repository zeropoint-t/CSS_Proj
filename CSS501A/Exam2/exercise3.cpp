
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

template<class T>
T doAddition(T& n1, T& n2){
    return n1 + n2;
};

template<class T>
class Node{
    public:
        Node(){}
        Node(T d){
            this->data = d;
        }
    private:
        T data;
};

class Animal{
    public:
        Animal(){}
        Animal(string name, int legs):name(name),numOfLegs(legs){
            // throw runtime_error("Hey this is wrong");
        }
        virtual void Run(){
            cout << "I am running" << endl;
        }
        virtual void Speak() = 0;
    private:
        string name = "";
        int numOfLegs = 0;
};

class Human{
    public:
        Human(){}
        Human(string name, int legs):name(name),numOfLegs(legs){
            // throw runtime_error("Hey this is wrong");
        }
        virtual void Run(){
            cout << "I am running" << endl;
        }
        virtual void Speak() = 0;
    private:
        string name = "";
        int numOfLegs = 0;
};


class Cow: virtual public Animal{
    public:
        Cow():Animal(){}
        Cow(string name, int legs, string favGrass):Animal(name,legs){
            this->favoriteGrass = favGrass;
        }
        virtual void Speak() override{
            cout << "Moooooooooooow" << endl;;
        }
        virtual void Run() override{
            cout << "Running Cow" << endl;
        }
    private:
        string favoriteGrass;
};
class CatCow;
class Cat: virtual public Animal{
    friend CatCow;
    public:
        Cat():Animal(){}
        Cat(string name, int legs, string favGrass):Animal(name,legs){
            this->favoriteCatfood = favGrass;
        }
        virtual void Speak() override{
            cout << "Moooooooooooow" << endl;;
        }
        virtual void Run() override{
            cout << "Running Cow" << endl;
        }
    private:
        string favoriteCatfood = "Some awesome cat food";
};

//multiple level inheritance
class Jerssey: public Cow{

};

//multiple inheritance
class HumanCow: public Cow, public Human{

};

//hibrid
class CatCow: public Cat, public Cow{
    friend void PrintCatCow(CatCow& cc);
    public:
        CatCow(int poops):Cat(),Cow(){
            NumOfPoops = poops;
        }
        virtual void Run(){

        }
        virtual void Speak(){

        }
        // void PrintCat(Cat& c){
        //     cout << c.favoriteCatfood << endl;
        // }
    private:
        int NumOfPoops;
        Cat cat;
};

void PrintCatCow(CatCow& cc){
    cout << cc.NumOfPoops << endl;
}

int main(){
    Cat cat;
    CatCow cc(4);
    PrintCatCow(cc);
    // cc.PrintCat(cat);


    Cow c("Jonny",4,"wheat");
    c.Speak();
    c.Run();

    Animal* an = &c;
    an->Speak();
    an->Run();

    // int a = 5;
    // int b = 10;
    // int sum = doAddition<int>(a,b);

    // Node<int> n(30);

}