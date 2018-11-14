// 53. Maximum Subarray
// Easy

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// Accepted

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int finalMax = nums[0];
    int curMax = nums[0];
    int length = nums.size();
    vector<int>::iterator curStartValue = nums.begin();
    for(auto it = nums.begin()+1; it != nums.end(); it++){
        int nextMax = curMax + *it;
        if(nextMax < curMax){
            curMax -= (*curStartValue);
            curStartValue++;
        }
        curMax += *it;
        if(curMax > finalMax)
            finalMax = curMax;
    }
    return finalMax;
}
int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int max = maxSubArray(nums);
    cout << max << endl;
    return 0;
}

