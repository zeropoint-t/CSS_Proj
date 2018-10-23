
#include <iostream>
#include <string>
using namespace std;

class PokerCard{

    friend ostream& operator<<(ostream &outStream, const PokerCard &pk);

    public:
        PokerCard(int suit, int faceVal){
            setSuit(suit);
            setFaceValue(faceVal);
        }
        int getFaceValue() const{
            return faceValue;
        }
        string getSuit() const{
            switch (suit)
            {
                case 1:
                    return "Diamond";
                    break;
                case 2:
                    return "Clover";
                    break;
                case 3:
                    return "Heart";
                    break;
                case 4:
                    return "Spade";
                    break;
                default: 
                    return "";
            }
        }
        void setFaceValue(int fv){
            if(fv > 0 && fv < 14){
                this->faceValue = fv;
            }
        }
        void setSuit(int suit){
            if(suit > 0 && suit < 5){
                this->suit = suit;
            }
        }

        bool operator==(const PokerCard& pk){
            if(this->faceValue == pk.getFaceValue() 
                && this->getSuit() == pk.getSuit()){
                    return true;
            }else{
                return false;
            }
        }

    private:
        int faceValue;
        int suit;
};

ostream& operator<<(ostream &outStream, const PokerCard &pk)
{
	outStream << pk.getSuit() << " / " << pk.getFaceValue();
	return outStream;
}

int main(int argc, const char* argv[]){
    PokerCard pk1(2,5);
    PokerCard pk2(2,5);
    PokerCard pk3(3,11);
    cout << pk1 << endl;

    bool sameCard = pk1 == pk2;
    cout << sameCard << endl;

    // sameCard = pk1 == pk3;
    cout << (pk1 == pk3) << endl;
}