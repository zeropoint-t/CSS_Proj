
/*
I want a technology to allow my mind to think of codes and type on a screen. This way, we programmers can speed up our train of thoughts.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double CalculatePower(int, int);

int main(int argc, const char * argv[]) {

    int base = -1, power = -1;
    while(true){
        cout << endl;
        cout << "Let's calculate the power of a number! (base number 0 to exit)" << endl;
        cout << "Base number? ";
        //take in a base nubmer from a user
        cin >> base;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cerr << "Error: Base must be a numeric value!!" << endl << endl;
            continue;
        }
        //exist of base is 0
        if(base == 0){
            break;
        }

        cout << "To the power of? ";
        //take in power from a user
        cin >> power;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cerr << "Error: Power must be a numeric value!!" << endl << endl;
            continue;
        }

        double result = CalculatePower(base, power);
        cout << base << " ^ " << power << " = " << result << endl;
    }

    return 0;
}

double CalculatePower(int base, int power){
    double result = base;
    if(power > 0){
        for(int i = 1; i < power; i++){
            result *= base;
        }
        return result;
    }else if(power < 0){
        for(int i = -1; i > power; i--){
            result *= base;
        }
        return 1/ result;
    }else{
        //power must be 0
        return 1;
    }
    return 0;
}