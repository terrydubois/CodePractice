/*
LeetCode 54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]

Example 2
    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    vector<int> spiral;

    // handle empty matrices
    if (matrix.size() < 1) {
        return spiral;
    }

    // keep track of the direction we are currently traveling in matrix (r, d, u, l)
    char dir = 'r';
    int rowLen = matrix[0].size();
    int colLen = matrix.size();
    int spiralSize = rowLen * colLen;

    // each time we reach the edge of the matrix, we close in further
    int colMin = 0;
    int colMax = rowLen - 1;
    int rowMin = 0;
    int rowMax = colLen - 1;

    int rowNum = 0;
    int colNum = 0;
    while (spiral.size() < spiralSize) {
        
        // add current cell to spiral vector
        vector<int> row = matrix[rowNum];
        int cell = row[colNum];
        spiral.push_back(cell);

        // moving right
        if (dir == 'r') {
            colNum++;

            // turning from right to down
            if (colNum >= colMax) {
                dir = 'd';
                rowMin++;
                if (colNum > colMax) {
                    colNum = colMax;
                    rowNum++;
                }
            }
        }
        // moving down
        else if (dir == 'd') {
            rowNum++;

            // turning from down to left
            if (rowNum >= rowMax) {
                dir = 'l';
                colMax--;
                if (rowNum > rowMax) {
                    rowNum = rowMax;
                    colNum--;
                }
            }
        }
        // moving left
        else if (dir == 'l') {
            colNum--;

            // turning from left to up
            if (colNum <= colMin) {
                dir = 'u';
                rowMax--;
                if (colNum < colMin) {
                    colNum = colMax;
                    rowNum--;
                }
            }
        }
        // moving up
        else if (dir == 'u') {
            rowNum--;
            
            // turning from up to right
            if (rowNum <= rowMin) {
                dir = 'r';
                colMin++;
                if (rowNum < rowMin) {
                    rowNum = rowMin;
                    colNum++;
                }
            }
        }
    }

    return spiral;
}

void printVec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
    }
    cout << endl;
}

int main() {

    cout << "hello world!\n";

    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> spiral = spiralOrder(matrix);
    printVec(spiral);

    return 0;
}