// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"


// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.


// Note:

// All given inputs are in lowercase letters a-z.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string arr[6] = {"flower","flow","flowht","flowng","flowwu","flo"};
    int size = 6;
    int curPos = 0;
    bool stillGood = true;
    vector<char> prefix;
    //loop unti;; stillGood is false
    do{
        //loop each string in an array comparing currnet string at corPos to the next
        for(int i = 0; i < size-1; i++){
            //if characters don't match, flag stillGood as false and break out of the loop
            if(arr[i][curPos] != arr[i+1][curPos]){//curPos == arr[i].length() || curPos == arr[i+1].length() || 
                stillGood = false;
                break;
            }
        }
        if(stillGood)
            prefix.push_back(arr[0][curPos++]);
    }while (stillGood);

    string s(prefix.begin(),prefix.end());
    cout << s << endl;
}