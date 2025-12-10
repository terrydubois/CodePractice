def length_of_longest_substring(s: str) -> int:

    # keep a left and right index
    left = right = 0
    longest = 0

    # keep a set of chars we have seen before
    chars = set()
    
    for right in range(len(s)):

        # if we have seen the char at the right index, bump up the left index
        while s[right] in chars:
            chars.remove(s[left])
            left += 1

        # always add the char at the right index
        chars.add(s[right])

        # always check to see if we have a new longest substring
        longest = max(longest, right - left + 1)


    return longest

if __name__ == "__main__":
    result = length_of_longest_substring("abcabcbb")
    print(f"result: {result}")