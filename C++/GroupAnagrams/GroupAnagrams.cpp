#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

	// mapping of sorted strings to a list of the original strings
	unordered_map<string, vector<string>*> sortedStrs;

	for (int i = 0; i < strs.size(); i++) {

		// get current string and sort it
		string str = strs[i];
		string strOriginal = str;
		sort(str.begin(), str.end());

		// if our map does not have this group yet, create it
		vector<string>* group = nullptr;
		if (sortedStrs.find(str) == sortedStrs.end()) {
			group = new vector<string>();
			sortedStrs[str] = group;
		}
		// if our map already has the group, use it
		else {
			group = sortedStrs[str];
		}

		// add current string to group
		group->push_back(strOriginal);
	}

	// now, make a list of all lists in sortedStrs
	vector<vector<string>> groups;
	for (auto it = sortedStrs.begin(); it != sortedStrs.end(); it++) {
		vector<string>* group = it->second;
		groups.push_back(*group);
		delete group;
	}

    return groups;
}

void printResult(const vector<vector<string>>& result) {
	for (int i = 0; i < result.size(); i++) {
		vector<string> anagrams = result[i];
		for (int j = 0; j < anagrams.size(); j++) {
			cout << anagrams[j];
			if (j + 1 < anagrams.size()) cout << ", ";
		}
		cout << endl;
	}
}

int main() {

	vector<string> input = {"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> output = groupAnagrams(input);

	printResult(output);

	return 0;
}

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]



