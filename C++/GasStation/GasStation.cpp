/*
LeetCode 134. Gas Station

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

Example 1
    Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    Output: 3

Example 2
    Input: gas = [2,3,4], cost = [3,4,3]
    Output: -1
*/

#include <iostream>
#include <vector>

using namespace std;

int vecSum(vector<int>& vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    // if there is not enough gas for the costs needed, there will be no valid solution
    if (vecSum(gas) < vecSum(cost)) {
        return -1;
    }

    // if we get to this point, we have guaranteed there is exactly 1 solution
    // so if we get to the end of the array, we do not need to loop around and check if our solution still works
    int total = 0;
    int startIndex = 0;
    for (int i = 0; i < gas.size(); i++) {

        // at each step, add from gas and subtract from cost
        total += gas[i] - cost[i];

        // if we go under zero, the solution we were trying was invalid, so the starting index must be later
        if (total < 0) {
            total = 0;
            startIndex = i + 1;
        }
    }

    return startIndex;
}

int main() {

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = canCompleteCircuit(gas, cost);
    cout << "result: " << result << endl;

    return 0;
}