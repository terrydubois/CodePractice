/*
LeetCode 73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1
    Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2
    Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {

    // use the first row and first col as marker
    // each time we encounter a zero, put a zero in the first row or col

    int rows = matrix.size();
    if (rows < 1) return;
    int cols = matrix[0].size();

    // check if first row has zeros
    bool firstRowHasZeros = false;
    for (int i = 0; i < cols; i++) {
        if (matrix[0][i] == 0) firstRowHasZeros = true;
    }

    // check if first col has zeros
    bool firstColHasZeros = false;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) firstColHasZeros = true;
    }

    // look for zeros in rows
    for (int i = 1; i < rows; i++) {
        vector<int>& row = matrix[i];
        for (int j = 1; j < cols; j++) {
            if (row[j] == 0) row[0] = 0;
        }
    }
    
    // look for zeros in cols
    for (int i = 1; i < cols; i++) {
        for (int j = 1; j < rows; j++) {
            if (matrix[j][i] == 0) matrix[0][i] = 0;
        }
    }
    
    // set row of zeros for any row that has zero at row[0]
    for (int i = 1; i < rows; i++) {
        vector<int>& row = matrix[i];
        if (row[0] == 0) {
            for (int j = 1; j < cols; j++) {
                row[j] = 0;
            }
        }
    }

    // set col of zeros for any col that has zero at col[0]
    for (int i = 1; i < cols; i++) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < rows; j++) {
                matrix[j][i] = 0;
            }
        }
    }

    // if first row had zeros, apply them here
    if (firstRowHasZeros) {
        for (int i = 0; i < cols; i++) {
            matrix[0][i] = 0;
        }
    }

    // if first col had zeros, apply them here
    if (firstColHasZeros) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> row = matrix[i];
        for (int j = 0; j < row.size(); j++) {
            cout << row[j] << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> input = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    cout << "input:\n";
    printMatrix(input);

    setZeroes(input);

    cout << "\noutput:\n";
    printMatrix(input);

    return 0;
}