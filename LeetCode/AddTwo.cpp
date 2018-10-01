

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argc, const char * argv[]){

    int nums[] = {2,5,20,1,-8,4,0,9};
    int target = 12;
    unordered_map<int,int> m;

    if(sizeof(nums)>0){
        for(int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
            m.insert(pair<int,int>(nums[i],i));
            int diff = target - nums[i];
            auto idx = m[diff];
            if(idx != 0){
                cout << "Found it at " << idx << " and " << i << endl;
                break;
            }

            // auto it =  m.at(diff);
            // int a = 0;
            // if(it != m.end()){
            //     auto val = *it;
            //     cout << "Found it at " << val.second << " and " << i << endl;
            //     break;
            // }
        }
    }

    // for(int i = 0; i < sizeof(nums) / sizeof(nums[0]);i++){
    //     if(nums[i] <= target){
    //         int diff = target-nums[i];
    //         auto pair = m[diff];
    //         if(pair != 0){
    //             cout << "Found it at " << i << " and " << pair << endl;
    //             break;
    //         }
    //     }
    // }

    cout << "Hello World" << endl;
}