def longest_substring(s: str) -> int:

    left = 0
    length = len(s)
    chars = set()
    longest = 0

    for right in range(length):
        char = s[right]

        while char in chars:
            chars.remove(s[left])
            left += 1

        chars.add(char)
        longest = max(longest, right - left + 1)

    return longest

if __name__ == "__main__":
    input = "abcabcdea"
    output = longest_substring(input)
    print(f"result: {output}")