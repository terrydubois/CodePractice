/*
LeetCode 290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.

Example 1
    Input: pattern = "abba", s = "dog cat cat dog"
    Output: true

Example 2
    Input: pattern = "abba", s = "dog cat cat fish"
    Output: false
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> splitStr(string s) {
    vector<string> tokens;
    
    string token;
    stringstream ss(s);
    while (getline(ss, token, ' ')) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

void printVec(vector<string>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ", ";
    }
    cout << endl;
}

bool wordPattern(string pattern, string s) {

    // keep a map<char, string>
    // loop through pattern, check if char is in our map
    // if it is in map, check if the next word in s matches whats in the map
    // if it is not in map, add it to map

    // split s and check if length matches pattern
    vector<string> split = splitStr(s);
    if (pattern.size() != split.size()) return false;

    unordered_map<char, string> map;
    unordered_set<string> mappedWords;

    for (int i = 0; i < pattern.size(); i++) {
        char chr = pattern[i];
        if (map.find(chr) != map.end()) {
            // chr is already in map
            if (map[chr] != split[i]) return false;
        }
        else {
            // chr is not in map

            // check if word has already been mapped
            if (mappedWords.find(split[i]) != mappedWords.end()) {
                // word has already been mapped to another char
                return false;
            }
            else {
                // word has not been mapped to any char yet
                map[chr] = split[i];
                mappedWords.insert(split[i]);
            }
        }
    }

    return true;
}

int main() {

    cout << "match: " << wordPattern("abba", "cat dog dog cat") << endl;

    return 0;
}