#include <iostream>
#include <vector>

using namespace std;

int findRow(vector<vector<int>>& matrix, int target) {

	int l = 0;
	int r = matrix.size() - 1;

	while (l < r) {
		int mid = l + (r - l) / 2;
		vector<int> row = matrix[mid];

		int rowFirst = row[0];
		int rowLast = row[row.size() - 1];
		if (target == rowFirst || target == rowLast) {
			// target is in this row, either first or last
			return mid;
		}
		else if (target > rowFirst && target < rowLast) {
			// target could be in this row, and cannot be in any other row
			return mid;
		}
		else if (target < rowFirst) {
			// target is not in this row, check left subarray
			r = mid - 1;
		}
		else {
			// target is not in this row, check right subarray
			l = mid + 1;
		}
	}

	return l;
}

int searchRow(vector<int>& row, int target) {

	int l = 0;
	int r = row.size() - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (row[mid] == target) return mid;
		else if (row[mid] < target) l = mid + 1;
		else if (row[mid] > target) r = mid - 1;
	}

	return -1;
}


int main() {

	vector<vector<int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};

	int target = 1;

	int rowIndex = findRow(matrix, target);
	cout << "rowIndex: " << rowIndex << endl;

	vector<int> row = matrix[rowIndex];
	int index = searchRow(row, target);

	return 0;
}

/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/