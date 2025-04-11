/*
LeetCode 2843. Count Symmetric Integers

You are given two positive integers low and high.
An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
Return the number of symmetric integers in the range [low, high].

Example 1
    Input: low = 1, high = 100
    Output: 9 (11, 22, 33, 44, 55, 66, 77, 88, 99)

Example 2
    Input: low = 1200, high = 1230
    Output: 4 (1203, 1212, 1221, and 1230)
*/

#include <iostream>

using namespace std;

// function to count the digits in an integer
int countDigits(int num) {
    int digits = 0;
    while (num > 0) {
        num = num / 10;
        digits++;
    }
    return digits;
}

bool isIntSymmetric(int num) {

    // if the amount of digits is odd, the int is not symmetric
    int digits = countDigits(num);
    if (digits % 2 != 0) return false;

    // sum up the digits in the first half and last half
    int i = 0;
    int sumOfFirstDigits = 0;
    int sumOflastDigits = 0;
    while (num > 0) {
        // get current digit, starting from the right of the int
        if (i < digits / 2) sumOflastDigits += num % 10;
        else sumOfFirstDigits += num % 10;

        num = num / 10;
        i++;
    }

    // return whether or not the sums match
    return sumOfFirstDigits == sumOflastDigits;
}

int countSymmetricIntegers(int low, int high) {

    // check if each int between low and high is symmetric
    int symmetricInts = 0;
    for (int i = low; i <= high; i++) {
        if (isIntSymmetric(i)) symmetricInts++;
    }
    return symmetricInts;
}

int main() {

    int result = countSymmetricIntegers(1200, 1230);
    cout << "result: " << result << endl;

    return 0;
}