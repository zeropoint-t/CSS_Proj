// 91. Decode Ways
// Medium

// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.

// Example 1:

// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

#include <vector>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int numDecodings(string s) {

    int combs = 0;
    if(s.size()==0){
        //if string is empty, that's 1 pattern
        //set combs to 1 as 1 pattern
        combs = 1;
    }else{
        //take the left most char off the string
        string sub1 = string(s.begin()+1, s.end());
        combs += numDecodings(sub1);

        //if string has more than or equal to 2 chars
        //and the combined num of the left most 2 chars is <= 26
        //remove the left most 2 chars
        if(s.size() >= 2 && s[0]-'0' <= 2 && s[1]-'0' <= 6){
            string sub2 = string(s.begin()+2, s.end());
            combs += numDecodings(sub2);
        }
    }

    return combs;
}

int main(){
    string s = "27162922";
    int comb = numDecodings(s);
    cout << "The combination is " << comb << endl;
}