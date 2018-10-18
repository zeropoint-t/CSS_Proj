
#include <iostream>
#include "PokerCard.h"
using namespace std;

ostream& operator<<(ostream& outStream, const PokerCard& pk){
    outStream << "Face Value: " << endl;
    return outStream;
}

void PokerCard::setFaveValue(faceValue fv){
    this->fv = fv;
}

faceValue PokerCard::getFaceValue(){
    return this->fv;
}

void PokerCard::setSuit(suit s){
    this->s = s;
}

suit PokerCard::getSuit(){
    return this->s;
}