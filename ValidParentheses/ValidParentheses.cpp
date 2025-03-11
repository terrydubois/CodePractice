/*
LeetCode 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
    Input: s = "()"
    Output: true

Example 2:
    Input: s = "()[]{}"
    Output: true

Example 3:
    Input: s = "(]"
    Output: false

Example 4:
    Input: s = "([])"
    Output: true
*/

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {

    // create a stack of parentheses
    stack<char> parens;
    for (int i = 0; i < s.size(); i++) {

        // each time we see an open paren in the string, add its closing paren to the stack
        if (s[i] == '(') parens.push(')');
        else if (s[i] == '[') parens.push(']');
        else if (s[i] == '{') parens.push('}');
        // if we see a close paren in the string, it should also be at the top of the stack
        else {
            // if it's not top of the stack, the parens are not valid
            if (parens.size() < 1) return false;
            if (parens.top() != s[i]) return false;
            parens.pop();
        }
    }

    return true;
}

int main() {

    string input = "([]])";
    bool output = isValid(input);
    cout << "input: " << input << ", output: " << output << endl;

    return 0;
}