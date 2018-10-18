

#ifndef PokerCard_h
#define PokerCard_h

#include <iostream>
using namespace std;

enum suit {Heart,Spade,Clover,Diamond};
enum faceValue {Ace,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King};

class PokerCard{
    friend ostream& operator<<(ostream& outStream, const PokerCard& pk);
    
    public:
        void setFaveValue(faceValue fc);
        faceValue getFaceValue();

        void setSuit(suit s);
        suit getSuit();

        void operator<<(PokerCard& pk);
    private:
        faceValue fv;
        suit s;
};

#endif