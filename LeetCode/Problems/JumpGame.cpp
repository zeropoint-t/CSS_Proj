// 55. Jump Game
// Medium

// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// Example 1:

// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Node{
    public:
        int index;
        Node(int ind):index(ind){}
        ~Node(){
            cout << "Node being destroyed at " << this << endl;
        }
};

bool canJump1(vector<int>& nums) {
    if(nums.size() > 0){
        stack<Node*> s;
        Node* n = new Node(nums[0]);
        s.push(n);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= nums[i]; j++){
                cout << i+j << endl;
                Node* n = new Node(i+j);
                s.push(n);
            }
        }

        cout << endl;

        while(s.empty() == false){
            Node* n = s.top();
            s.pop();
            cout << n->index << endl;
            if(n->index == nums.size()-1)
                return true;
        }
    }
    return false;
}

bool canJump2(vector<int>& nums) {
    if(nums.size() > 0){
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= nums[i]; j++){
                if(i+j == nums.size()-1)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> v = {1,3,2,4,0,1,5,0,3,1};//{2,3,1,1,4};
    bool canJmp = canJump1(v);
    cout << endl;
    cout << canJmp << endl;

    cout << endl;
    canJmp = canJump2(v);
    cout << canJmp << endl;
}