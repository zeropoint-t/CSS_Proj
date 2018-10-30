
#include <string>
#include <iostream>

using namespace std;

int cvtRomanToNum(char c1, char c2, int& inc){
    cout  << c1 << c2 << endl;
    if(c1 == 'C' && c2 == 'M'){
        inc++; 
        return 900;
    }

    if(c1 == 'C' && c2 == 'D') {
        inc++; 
        return 400;
    }
    if(c1 == 'X' && c2 == 'C') {
        inc++; 
        return 90;
    }
    if(c1 == 'X' && c2 == 'L') {
        inc++; 
        return 40;
    }
    if(c1 == 'I' && c2 == 'X') {
        inc++; 
        return 9;
    }
    if(c1 == 'I' && c2 == 'V') {
        inc++; 
        return 4;
    }

    if(c1 == 'M') return 1000;
    if(c1 == 'D') return 500;
    if(c1 == 'C') return 100;
    if(c1 == 'L') return 50;
    if(c1 == 'X') return 10;
    if(c1 == 'V') return 5;
    if(c1 == 'I') return 1;

    return 0;
}

int main(){

    string roman = "LVIII";
    int num = 0;
    for(int i = 0; i < roman.length();i++){
        num+= cvtRomanToNum(roman[i], roman[i+1], i);
    }

    cout << num << endl;
}