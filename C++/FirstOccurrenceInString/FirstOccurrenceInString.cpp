/*
LeetCode 28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1
    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0

Example 2
    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
*/

#include <iostream>

using namespace std;

// look through haystack until we find first char in needle
// if we find first char in needle, loop through needle to see if we can make it to end of needle
// if we do, return starting index

int strStr(string haystack, string needle) {

    // handle empty strings
    if (haystack.size() < 1 || needle.size() < 1) return -1;

    int needleStartIndex = -1;
    for (int i = 0; i < haystack.size(); i++) {
        
        // if we haven't found a startIndex yet, and this matches the first char in needle, we'll try this startIndex
        if (haystack[i] == needle[0] && needleStartIndex == -1) {
            needleStartIndex = i;
        }

        // if we are looking in a potential match...
        if (needleStartIndex >= 0) {

            // needleIndex will give us the char in needle we should check next
            int needleIndex = i - needleStartIndex;

            // if this char in needle isn't haystack, we will go back to our startIndex in haystack and keep looking
            if (haystack[i] != needle[needleIndex]) {
                i = needleStartIndex;
                needleStartIndex = -1;
            }
            // if we are still matching and have reached the end of needle, we just return the startIndex
            else if (needleIndex == needle.size() - 1) {
                return needleStartIndex;
            }
        }
    }

    return -1;
}

int main() {

    int output = strStr("mississippi", "pi");
    cout << "output: " << output << endl;

    return 0;
}