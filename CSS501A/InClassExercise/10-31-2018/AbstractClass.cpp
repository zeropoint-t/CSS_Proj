#include <iostream>
using namespace std;

class AbstractAirplane{
    public:
        virtual void Fly() = 0;
};

class BaseAirplane : public AbstractAirplane{
    public:
        virtual void Fly(){
            cout << "Abstract Airplane Flying" << endl;
        };
};

class F18 : public BaseAirplane{
    public:
        void Fly() override{
            cout << "F18 Flying" << endl;
        }
};

class Boeing547 : public BaseAirplane{
    public:
        void Fly() override{
            cout << "Boeing547 Flying" << endl;
        }
};

class Game{
    public:
        void Fly(BaseAirplane* ap){
            ap->Fly();
        }
};

int main(){
    Game g;
    F18 f18;
    Boeing547 b;

    g.Fly(&f18);
    g.Fly(&b);
}