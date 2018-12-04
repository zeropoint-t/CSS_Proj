// 70. Climbing Stairs

// Easy

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.

// Example 1:
// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include<map>

using namespace std;

class ClimbingStairs{
    public:
        int climbing_Stairs(int cummulativeSteps, int numOfSteps){
            if(cummulativeSteps < numOfSteps){

                auto it1 = m.find(cummulativeSteps+1);
                auto it2 = m.find(cummulativeSteps+2);
                if(it1 != m.end() && it2 != m.end()){
                    return it1->second + it2->second;
                }else if(it1 != m.end() && it2 == m.end()){
                    int i = climbing_Stairs(cummulativeSteps+2, numOfSteps);
                    m.insert(pair<int,int>(cummulativeSteps+2,i));
                    return it1->second + i;
                }else if(it1 == m.end() && it2 != m.end()){
                    int i = climbing_Stairs(cummulativeSteps+1, numOfSteps);
                    m.insert(pair<int,int>(cummulativeSteps+1,i));
                    return i + it2->second;
                }else{
                    int i1 = climbing_Stairs(cummulativeSteps+1, numOfSteps);
                    m.insert(pair<int,int>(cummulativeSteps+1,i1));
                    int i2 = climbing_Stairs(cummulativeSteps+2, numOfSteps);
                    m.insert(pair<int,int>(cummulativeSteps+2,i2));
                    return i1 + i2;
                }
            }
            
            if(cummulativeSteps == numOfSteps)
                return 1;

            if(cummulativeSteps > numOfSteps)
                return 0;

            return 0;
        }

        int climbingStairs(int numOfSteps){
            return climbing_Stairs(0,numOfSteps);
        }
    private:
        map<int,int> m;
};

int main(){
    ClimbingStairs cs;
    int a = cs.climbingStairs(6);
}