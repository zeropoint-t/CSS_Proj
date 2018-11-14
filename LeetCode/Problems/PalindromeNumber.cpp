// 9. Palindrome Number
// Easy
// 1051
// 1117

// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

// Example 1:

// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:

// Coud you solve it without converting the integer to a string?

// Accepted


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