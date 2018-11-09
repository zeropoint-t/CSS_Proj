// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int LongestSubstringWithoutRepeatingChars1(string str){
    set<char> s;
    int max = 0;
    int cnt = 0;

    for(int i = 0; i < str.length(); i++){
        if(str.length()-i <= max)
            break;
        for(int j = 0 + i; j < str.length(); j++){
            if(s.find(str[j]) == s.end()){
                s.insert(str[j]);
                cnt++;
                if(cnt > max)
                    max = cnt;

                // if(max == 12)
                //     int a = 0;

            }else{
                break;
            }
        }
        cnt = 0;
        s.clear();
    }
    return max;
}

int LongestSubstringWithoutRepeatingChars2(string str){
    
    int max = 0;
    int trainlingMax = 0;
    unordered_map<char,int> m;
    for(int i = 0; i < str.length(); i++){
        // cout << str[i] << endl;
        auto pair = m.find(str[i]);
        if(pair == m.end()){//not in the map
            m.insert({str[i],i});
            trainlingMax++;
            if(trainlingMax > max){
                max = trainlingMax;
            }
        }else{//in the map already
            // cout << pair->second << endl;
            trainlingMax = i-pair->second > trainlingMax+1 ? trainlingMax+1 : i-pair->second;
            if(trainlingMax > max){
                max = trainlingMax;
            }
            pair->second = i;
        }
    }

    return max;
}

int main(){
    int max1 = LongestSubstringWithoutRepeatingChars1("");
    cout << max1 << endl;

    int max2 = LongestSubstringWithoutRepeatingChars2("");
    cout << max2 << endl;
}