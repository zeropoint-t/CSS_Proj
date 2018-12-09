
#include <iostream>
#include <string>

using namespace std;

class Competitor{

    friend Competitor Compete(Competitor& comp1, Competitor& comp2);

    private:
        string name;
        int strength;
        int cunning;
    public:
        Competitor(string name){
            this->name = name;
        }
        int getStrenth() const{
            return this->strength;
        }
        void setStrength(int str){
            this->strength = str;
        }
        int getCunning() const{
            return this->cunning;
        }
        void setCunning(int cn){
            this->cunning = cn;
        }

        bool operator<(const Competitor& comp){
            return true;
        }

        bool operator==(const Competitor& comp){
            return true;
        }
};

Competitor Compete(Competitor& comp1, Competitor& comp2){
    return comp1;
}

template<class T>
class Tournament{
    private:

    protected:
        T winner;
        int matchType = 0;
        int roundPlayed = 0;
    public:
        Tournament(int matchType){
            this->matchType = matchType;
        }
        virtual ~Tournament(){}
        virtual T& GetWinner() = 0;
        virtual void Enter(T t) = 0;
        int getRoundsPlayed(){
            return this->roundPlayed;
        }
};



int main(){

}