// 73. Set Matrix Zeroes
// Medium

// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

// Example 1:

// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:

// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// Follow up:

// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
#include <vector>
#include <iostream>
#include <set>

using namespace std;

// Approach 1: Additional Memory Approach

// Intuition

// If any cell of the matrix has a zero we can record its row and column number. All the cells of this recorded row and column can be marked zero in the next iteration.

// Algorithm
// 1.We make a pass over our original array and look for zero entries.
// 2.If we find that an entry at [i, j] is 0, then we need to record somewhere the row i and column j.

// 3.So, we use two sets, one for the rows and one for the columns. 
//     if cell[i][j] == 0 {
//         row_set.add(i)
//         column_set.add(j)
//     }

// 4.Finally, we iterate over the original matrix. For every cell we check if the row r or column c had been marked earlier. If any of them was marked, we set the value in the cell to 0. 
//     if r in row_set or c in column_set {
//         cell[r][c] = 0
//     }

void setZeroes_Approach1(vector<vector<int>>& matrix) {
    set<int> row_set;
    set<int> col_set;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                row_set.insert(i);
                col_set.insert(j);
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(row_set.find(i) != row_set.end() || col_set.find(j) != col_set.end())
                matrix[i][j] = 0;
        }
    }
}

void display(vector<vector<int>>& matrix){
    for(auto row = matrix.begin(); row != matrix.end(); row++){
        for(auto cell = row->begin(); cell != row->end(); cell++){
            cout << *cell << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> r1 = {0,1,2,0};
    vector<int> r2 = {3,4,5,2};
    vector<int> r3 = {1,3,1,5};
    vector<vector<int>> matrix = {r1,r2,r3};
    display(matrix);
    cout << endl;
    setZeroes_Approach1(matrix);
    display(matrix);
}