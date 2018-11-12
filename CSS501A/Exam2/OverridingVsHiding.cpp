

#include <iostream>
#include <string>

using namespace std;

class base{
    public:
        virtual void foo(){
            cout << "Base" << endl;
        }
};

class derived: public base{
    public:
        void foo(){
            cout << "Derived" << endl;
        }
};

int main(){
    base* b = new derived();
    b->foo();
    return 0;
}