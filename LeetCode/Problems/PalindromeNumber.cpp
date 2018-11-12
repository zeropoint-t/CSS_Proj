
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0)
        return false;

    //count number of digits here
    int tmp = x;
    int digits = 0;
    while(tmp >= 1){
        tmp /= 10;
        digits++;
    }

    //if 1 digit, that's a palindrome so return true
    if(digits == 1)
        return true;

    //store each digit in an array
    int arr[digits];
    int idx = 0;
    while(x >= 1){
        int a = x%10;
        arr[idx++] = a;
        x/=10;
    }

    int l = 0;
    int r = digits - 1;
    for(int i = 0; i < digits; i++){
        if(arr[l++] != arr[r--])
            return false;

        if(l > r)
            break;
    }

    return true;
}

int main(){
    bool isPal = isPalindrome(-121);
    cout << isPal << endl;
}