/*
LeetCode 79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1
    Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = 'ABCCED'
    Output: true

Example 2
    Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = 'SEE'
    Output: true

Example 3
    Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = 'ABCB'
    Output: false
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printVec(vector<char>& vec) {
    for (char& c : vec) {
        cout << c << ' ';
    }
    cout << endl;
}

void printBoard(vector<vector<char>>& board) {
    cout << "board:\n";
    for (vector<char>& row : board) {
        printVec(row);
    }
}

bool dfs(vector<vector<char>>& board, string word, int wordIndex, int row, int col) {

    // if we've reached the end of the word, return true
    if (wordIndex >= word.size()) return true;

    // if we've hit the edge of the board, return false
    if (row < 0 || row >= board.size()) return false;
    if (col < 0 || col >= board[0].size()) return false;

    // if we've hit a #, we have visited this cell before
    if (board[row][col] == '#') return false;

    // if we've found a char that's not what we are looking for, return false
    if (board[row][col] != word[wordIndex]) return false;

    // get current cell value and mark as visited by changing cell to #
    char cell = board[row][col];
    board[row][col] = '#';
    
    // check in all four directions
    bool resultR = dfs(board, word, wordIndex + 1, row, col + 1);
    bool resultL = dfs(board, word, wordIndex + 1, row, col - 1);
    bool resultU = dfs(board, word, wordIndex + 1, row - 1, col);
    bool resultD = dfs(board, word, wordIndex + 1, row + 1, col);

    // revert cell back to original value before continuing
    board[row][col] = cell;

    return resultR || resultL || resultU || resultD;
}

bool exist(vector<vector<char>>& board, string word) {

    char firstChar = word[0];
    for (int i = 0; i < board.size(); i++) {
        vector<char>& row = board[i];
        for (int j = 0; j < row.size(); j++) {
            if (row[j] == firstChar) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {

    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    printBoard(board);

    bool result = exist(board, "ABCCED");
    cout << "result: " << result << endl;

    return 0;
}