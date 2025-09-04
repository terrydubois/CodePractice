/*
LeetCode 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

Example 1
Input: s = "abcabcbb"
Output: 3

Example 2
Input: s = "bbbbb"
Output: 1
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// sliding window
// use l and r pointers, both start at beginning of string
// have an unordered_set that tracks which chars are in window
// each time we move r pointer, check if longest has grown
int longestSubstring(string s) {

    int l = 0;
    int longest = 0;
    int len = s.size();
    unordered_set<char> chars;

    for (int r = 0; r < len; r++) {

        // if we have seen char before, bump up l pointer
        char c = s[r];
        while (chars.find(c) != chars.end()) {
            chars.erase(s[l]);
            l++;
        }

        chars.insert(c);

        // check if length has grown
        longest = max(longest, r - l + 1);
    }

    return longest;
}

int main() {

    cout << "hello world" << endl;
    int result = longestSubstring("bbbbb");
    cout << "result: " << result << endl;

}