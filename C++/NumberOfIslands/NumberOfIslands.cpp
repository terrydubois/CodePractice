/*
LeetCode 200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
    Input: grid = [
    ['1','1','1','1','0'],
    ['1','1','0','1','0'],
    ['1','1','0','0','0'],
    ['0','0','0','0','0']
    ]
    Output: 1

Example 2:
    Input: grid = [
    ['1','1','0','0','0'],
    ['1','1','0','0','0'],
    ['0','0','1','0','0'],
    ['0','0','0','1','1']
    ]
    Output: 3
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        vector<char> row = grid[i];
        for (int j = 0; j < row.size(); j++) {
            cout << row[j] << " ";
        }
        cout << endl;
    }
}

void searchIsland(vector<vector<char>>& grid, int rowStart, int colStart) {

    queue<vector<int>> q;
    q.push({rowStart, colStart});

    int gridWidth = grid[0].size();
    int gridHeight = grid.size();

    while (!q.empty()) {
        vector<int> cell = q.front();
        int cellRow = cell[0];
        int cellCol = cell[1];
        char cellVal = grid[cellRow][cellCol];

        if (cellVal == '1') {

            // visit current cell
            grid[cellRow][cellCol] = '2';

            // check to the right
            if (cellCol + 1 < gridWidth) {
                q.push({cellRow, cellCol + 1});
            }
            // check to the left
            if (cellCol - 1 >= 0) {
                q.push({cellRow, cellCol - 1});
            }
            // check to the top
            if (cellRow - 1 >= 0) {
                q.push({cellRow - 1, cellCol});
            }
            // check to the bottom
            if (cellRow + 1 < gridHeight) {
                q.push({cellRow + 1, cellCol});
            }
        }

        q.pop();
    }
}

int numIslands(vector<vector<char>>& grid) {

    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
        vector<char>& row = grid[i];
        for (int j = 0; j < row.size(); j++) {
            if (row[j] == '1') {
                searchIsland(grid, i, j);
                result++;
            }
        }
    }

    return result;
}

int main() {

    vector<vector<char>> grid = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };

    cout << "before: \n";
    printGrid(grid);

    int result = numIslands(grid);

    cout << "after: \n";
    printGrid(grid);

    cout << "result: " << result << endl;

    return 0;
}