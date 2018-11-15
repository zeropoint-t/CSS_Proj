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
#include <queue>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max = *(nums.begin());
    int runningMax = *(nums.begin());
    vector<int>::iterator init = nums.begin();
    for(auto it = nums.begin()+1; it != nums.end(); it++){
        if(*init < 0){
            runningMax -= *init;
            init++;
        }
        runningMax += *it;
        if(runningMax > max){
            max = runningMax;
        }
    }
    runningMax = max;
    while(init != nums.end()){
        runningMax -= *(init);
        if(runningMax > max)
            max = runningMax;
        init++;
    }
    return max;
}

int maxSubArray_v2(vector<int>& nums) {
    //this algorithm moves through a vector like how a warm moves
    //0. set max & runningMax to be the first value
    //1. find the first positive value
    //2. keep running total from there to the end
    //3. keep track of the max value along the way
    //4. remove each value from the first positive value to the end
    //5. keep track of the max value

    //step 0
    auto init = nums.begin();
    int max = *init;
    int runningMax = *init;

    //step 1
    init++;
    while(*init < 1 && init != nums.end()){
        if(*init > runningMax)
            runningMax = max = *init;
        init++;
    }

    //there is no positive value
    //just return the max negative value
    if(init == nums.end())
        return max;
    
    //init points to the first positive number
    //set running and max to init
    runningMax = max = *init;

    //step 2
    queue<int> q;
    q.push(*init);//push the first element into a queue
    for(auto it = init+1; it != nums.end(); it++){
        //keep track of runningMax and max
        runningMax += *it;
        if(runningMax > max){
            max = runningMax;
        }
        q.push(*it);//push each element into a queue
    }

    runningMax = max;

    while(!q.empty()){
        cout << q.front() << endl;
        runningMax -= q.front();
        q.pop();
        if(runningMax > max)
            max = runningMax;
    }

    return max;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};//{-1,-3,5,2,-9,4,7,-1,-2,20};//{-1,-3,1,5,-9,3,8,-5}
    int max = maxSubArray_v2(nums);
    cout << max << endl;
    return 0;
}

