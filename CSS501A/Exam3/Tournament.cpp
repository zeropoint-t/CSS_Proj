#include <iostream>
#include <string>

using namespace std;

class Competitor{
    private:
        string name;
        int wins = 0;
        int losses = 0;
    public:
        Competitor(string name){
            this->name = name;
        }
        string getName(){
            return this->name;
        }
        void incrementWin(){wins++;}
        void incrementLosses(){losses++;}
        void setWins(int wins){
            if(wins > 0 && wins < 100){
                this->wins = wins;
            }else{
                throw out_of_range("Wins are negative or too many wins");
            }
        }
        void setLosses(int losses){
            if(losses > 0 && losses < 100){
                this->losses = losses;
            }else{
                throw out_of_range("losses are negative or too many losses");
            }
        }
        double getWLRatio() const{
            return losses == 0 ? 0 : wins / losses;
        }

        Competitor operator*(const Competitor& competitor){
            if(this->name > competitor.name)
                return *this;
            else
                return competitor;
        }

        bool operator<(const Competitor& competitor){
            if(this->getWLRatio() < competitor.getWLRatio())
                return true;
            else
                return false;
        }
};

int main(){
    cout << endl;
}