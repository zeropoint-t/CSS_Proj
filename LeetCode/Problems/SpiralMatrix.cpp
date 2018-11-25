// 54. Spiral Matrix
// Medium

// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row_max = matrix.size();
    int row_min = 1;
    int col_max = matrix[0].size();
    int col_min = 0;
    vector<int> spiral;
    while(col_max >= col_min && row_max >= row_min){
        for(int c = col_min; c <= col_max; c++){
            int num = matrix[row_min-1][c];
            spiral.push_back(num);
        }
        col_max-=1;
        for(int r = row_min; r <= row_max; r++){
            int num = matrix[r][col_max+1];
            spiral.push_back(num);
        }
        row_max-=1;
        for(int c = col_max; c >= col_min; c--){
            int num = matrix[row_max+1][c];
            spiral.push_back(num);
        }
        col_min += 1;
        for(int r = row_max; r >= row_min; r--){
            int num = matrix[r][col_min-1];
            spiral.push_back(num);
        }
        row_min += 1;
    }
    return spiral;
}

int main(){
    vector<vector<int>> matrix;
    vector<int> r1 = {1,2,3};
    vector<int> r2 = {4,5,6};
    vector<int> r3 = {7,8,9};
    matrix.push_back(r1);
    matrix.push_back(r2);
    matrix.push_back(r3);

    auto spiral = spiralOrder(matrix);
    for(auto it = spiral.begin(); it != spiral.end();it++){
        cout << *it << endl;
    }
}