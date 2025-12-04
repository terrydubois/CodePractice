'''

LeetCode 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Every close bracket has a corresponding open bracket of the same type.

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

Example 5:
    Input: s = "([)]"
    Output: false
'''

def is_valid(s: str) -> bool:

    paren_stack = []

    for c in s:

        # for each open paren we see, we must add an expeted close paren
        if c == '(':
            paren_stack.append(')')
        elif c == '[':
            paren_stack.append(']')
        elif c == '{':
            paren_stack.append('}')
        # for each closed paren we see, we must check the top of our stack for a matching open paren
        elif c == ')'or c == ']' or c == '}':

            # if the stack is already empty when we are trying to pop, it is unbalanced
            # if the stack has paren(s), but not the one we expect, it is unbalanced
            if len(paren_stack) < 1 or c != paren_stack.pop():
                return False

    # if we have made it this far, just check if there are any unmatched parens left in the stack
    return len(paren_stack) == 0

if __name__ == '__main__':
    input = "()[]{}"
    result = is_valid(input)
    print(result)