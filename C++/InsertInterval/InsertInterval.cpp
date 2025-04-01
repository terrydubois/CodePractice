/*
LeetCode 57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Example 1
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]

Example 2
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printVecVec(vector<vector<int>>& vecVec) {
    for (int i = 0; i < vecVec.size(); i++) {
        printVec(vecVec[i]);
    }
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    // add new interval to intervals and sort
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    for (int i = 0; i < intervals.size(); i++) {

        vector<int>& curInterval = intervals[i];

        // if there are no results yet, append curInterval
        if (result.size() < 1) {
            result.push_back(curInterval);
        }
        // otherwise, let's check if we should append curInterval or extend lastResult
        else {
            vector<int>& lastResult = result[result.size() - 1];

            // if curInterval start lies between lastResult, we may need to extend lastResult
            if (curInterval[0] >= lastResult[0] && curInterval[0] <= lastResult[1]) {
                lastResult[1] = max(lastResult[1], curInterval[1]);
            }
            // if curInterval is entirely after lastResult, we can just append curInterval
            else {
                result.push_back(curInterval);
            }
        }
    }

    return result;
}

int main() {

    // {{2,3},{5,7}} / {0,6}
    // {{1,2},{3,5},{6,7},{8,10},{12,16}} / {4,8}

    vector<vector<int>> input = {{2,3},{5,7}};
    vector<int> newInterval = {0,6};
    cout << "input:\n";
    printVecVec(input);
    
    vector<vector<int>> output = insert(input, newInterval);
    cout << "output:\n";
    printVecVec(output);

    return 0;
}