// https://leetcode.com/problems/container-with-most-water/description/

// 11. Container With Most Water
// DescriptionHintsSubmissionsDiscussSolution
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example:

// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxArea(vector<double>& height) {
    int max = 0;
    for(auto oit = height.begin(); oit != height.end(); oit++){
        for(auto iit = oit + 1; iit != height.end(); iit++){
            int distance = iit - oit;
            cout << "Distance " << distance << endl;
            cout << "Outer " << (*oit) << endl;
            cout << "Inner " << (*iit) << endl;
            int area = distance * ((*oit) < (*iit) ? (*oit) : (*iit));
            if(area > max)
                max = area;
            cout << "Max " << max << endl << endl;
        }
    }

    return max;
}

int main(){
    vector<double> height = {1,8,6,2,5,4,8,3,7};
    int max = maxArea(height);
    cout << max << endl;
    return 0;
}