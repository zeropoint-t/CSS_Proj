// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"

#include <string>
#include <iostream>
using namespace std;

string CountAndSay(int n){
    string finalSay = "1";
    cout << 1 << " " << finalSay << endl;;
    for(int i = 1; i < n; i++){
        int lgt = finalSay.length();
        string curSay = "";
        for(int j = 0; j < lgt; j++){
            int cnt = 1;
            char c = finalSay[j];
            while(c == finalSay[j+1]){
                cnt++;
                j++;
            }
            curSay += to_string(cnt) + string(1,c);
        }
        cout << i+1 << " " << curSay << endl;
        finalSay = curSay;
    }
    return finalSay;
}

int main(){
    CountAndSay(10);
}