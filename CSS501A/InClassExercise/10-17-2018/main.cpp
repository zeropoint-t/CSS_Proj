

#include <iostream>
#include "string"
#include "PokerCard.h"
using namespace std;

class Cat{
    public:
        Cat(string name):name(name){
            cout << "Cat is constructed at " << this << endl;
        }
        string name;
    private:
};

int main(int argc, const char* argv[]){
    Cat myCat("MyCat");
    // cout << myCat << endl;
    // cout << myCat.name << endl;
    // cout << &myCat << endl;
    // cout << &(myCat.name) << endl;

    PokerCard pk;
    pk.setSuit(Diamond);
    pk.setFaveValue(King);

    cout << pk << endl;
}