
/*
I want a technology to allow off-the-grid housing. As an evidence for climate change has become undeniable that humans are the main cause,
we all are resposible for our own actions to reduce carbon emmissions. By allowing a housing to be self-sustaining with cutting edge technologies,
it will have an impact on how we collect and cosume energy for our needs.
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

        //obtain a value as double first before converting to int. Necessary step to handle how cin handles decimal numbers
        double usr_val = 0;

        //take in a base nubmer from a user
        cin >> usr_val;

        //non numeric value was entered. Show error message and skip the rest of while loop
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cerr << "Error: Base must be a numeric value!!" << endl << endl;
            continue;
        }
        //convert double to int
        base = usr_val;

        //exist if base is 0
        if(base == 0){
            break;
        }

        cout << "To the power of? ";
        //obtain power from a user
        cin >> usr_val;
        power = usr_val;
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