#include <iostream>
#include <unordered_set>

using namespace std;

int longestSubstring(string str) {

    // keep a set of characters we have seen
    // keep a left index and right index
    int left = 0;
    int longest = 0;
    unordered_set<char> chars;

    for (int right = 0; right < str.size(); right++) {

        // if we have seen str[right] before, bump the left index up
        while (chars.find(str[right]) != chars.end()) {
            chars.erase(str[left]);
            left++;
        }

        // add str[right] to chars
        chars.insert(str[right]);
        
        // check if longest has increased at each step
        longest = max(longest, right - left + 1);
    }

    return longest;
}

int main() {

    string input = "abcabcbb";
    cout << "input: " << input << endl;
    cout << "output: " << longestSubstring(input) << endl;

    return 0;
}

// Input: s = "abcabcbb"
// Output: 3

// Input: s = "bbbbb"
// Output: 1

// Input: s = "pwwkew"
// Output: 3