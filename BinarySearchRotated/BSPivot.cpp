#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
    }
    cout << endl;
}

int binarySearch(vector<int>& vec, int val, int l, int r) {

    while (l <= r) {
        int mid = (l + r) / 2;
        if (vec[mid] == val) return mid;
        else if (vec[mid] > val) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

int findPivot(vector<int>& vec) {
    int l = 0;
    int r = vec.size() - 1;
    while (l < r) {
        
        // check if this subarray is already sorted
        if (vec[l] < vec[r]) return l;

        int mid = (l + r) / 2;

        // right subarray is out of order, so pivot is in the right half
        if (vec[mid] > vec[r]) l = mid + 1;
        // left subarray is out of order, so pivot is in the left half
        else r = mid;
    }

    return l;
}

int searchPivoted(vector<int>& vec, int val) {

    // first check if the value at pivot is what we are looking for
    int pivot = findPivot(vec);
    if (vec[pivot] == val) return pivot;

    // if the pivot is at 0, the entire vector is sorted, so do normal binary search
    if (pivot == 0) return binarySearch(vec, val, 0, vec.size() - 1);

    // if the first element in the array is less than what we want, search in left subvector
    if (vec[0] <= val) return binarySearch(vec, val, 0, pivot - 1);

    // otherwise search in right subvector
    return binarySearch(vec, val, pivot + 1, vec.size() - 1);
}

void searchAll(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        int val = vec[i];
        cout << "Searching for " << val << ": " << searchPivoted(vec, val) << endl;
    }
}

int main() {

    vector<int> numbers = {4, 5, 8, 12, 15, 45, 2, 3};
    searchAll(numbers);
    
    return 0;
}