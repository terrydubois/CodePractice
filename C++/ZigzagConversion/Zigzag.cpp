/*
LeetCode 6. Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows

Example 1:
    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

Example 2:
    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
*/

#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<char>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

string convert(string s, int numRows) {

    // create a list of chars for each row that we will later concatenate into one string
    vector<vector<char>> rows(numRows);

    int rowIndex = 0;
    int incr = numRows == 1 ? 0 : 1;
    for (int i = 0; i < s.size(); i++) {
        
        // get relevant row's list and add current char to it
        vector<char>& row = rows[rowIndex];
        row.push_back(s[i]);

        // rowIndex should either increment, decrement, or stay the same if numRows == 1
        if (incr > 0 && rowIndex == numRows - 1) {
            incr = -1;
        }
        else if (incr < 0 && rowIndex == 0) {
            incr = 1;
        }
        rowIndex += incr;
    }

    // concatenate all rows into a single string and return that
    string zigzag = "";
    for (int i = 0; i < numRows; i++) {
        vector<char>& row = rows[i];
        for (int j = 0; j < row.size(); j++) {
            zigzag += row[j];
        }
    }
    return zigzag;
}

int main() {
    
    string input = "AB";
    string output = convert(input, 1);

    cout << "input: " << input << endl;
    cout << "output: " << output << endl;

    return 0;
}