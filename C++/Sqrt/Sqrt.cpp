/*
LeetCode 69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.

Example 1
    Input: x = 4
    Output: 2
Example 2
    Input: x = 8
    Output: 2
*/

#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x)
{

    // use binary search to find sqrt
    int l = 1;
    int r = x;
    while (l <= r)
    {
        // try midpoint between left and right
        int mid = l + (r - l) / 2;

        // cast mid to long long so we can square it if goes above INT_MAX
        long long midSquared = static_cast<long long>(mid) * mid;

        // follow normal binary search rules
        if (midSquared == x)
            return mid;
        else if (midSquared > x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    // cast back into an int and round the right pointer
    return static_cast<int>(round(r));
}

int main()
{

    int num = 2147395599;
    int numSquared = mySqrt(num);
    cout << "sqrt of " << num << " is " << numSquared << endl;

    return 0;
}