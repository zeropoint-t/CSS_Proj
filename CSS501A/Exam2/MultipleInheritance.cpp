
#include<iostream>
using namespace std;

class left {
public:
    void foo(){
        cout << "left called at " << this << endl;
    };
};

class right {
public:
    void foo(){
        cout << "right called at " << this << endl;
    };
};

class bottom : public left, public right {
public:
    void foo()
    {
        //base::foo();// ambiguous
        left::foo();
        right::foo();

        // and when foo() is not called for 'this':
        bottom b;
        b.left::foo();  // calls b.foo() from 'left'
        b.right::foo();  // call b.foo() from 'right'
    }
};

int main(){
    bottom b;
    b.foo();
}