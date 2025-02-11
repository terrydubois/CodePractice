#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVec(const vector<int>& vec) {
    cout << "vec: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
    }
    cout << endl;
}

void printVecVec(const vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        vector<int> subvec = vec[i];
        printVec(subvec);
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    // first, let's sort each interval by its lower end
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> mergedIntervals;

    // go through each interval and check if the current interval overlaps with the previous
    vector<int> prevInterval = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        
        // if current interval's low end is <= the previous interval's high end, they overlap
        vector<int> curInterval = intervals[i];
        if (curInterval[0] <= prevInterval[1]) {

            // if they overlap, we might need to extend the previous interval's high end
            prevInterval[1] = max(curInterval[1], prevInterval[1]);
        }
        else {

            // if there is no overlap, just add this as a completely new interval
            mergedIntervals.push_back(prevInterval);
            prevInterval = curInterval;
        }
    }

    // add final previous interval and return
    mergedIntervals.push_back(prevInterval);
    return mergedIntervals;
}


int main() {

    cout << "Hello world!\n";

    vector<vector<int>> input = {{1,4}, {4,5}};
    cout << "input...\n";
    printVecVec(input);

    vector<vector<int>> output = merge(input);
    cout << "output...\n";
    printVecVec(output);

    return 0;
}

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]