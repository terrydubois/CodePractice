# LeetCode 14. Longest Common Preix
# 
# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".
#
# Example 1
# Input: strs = ["flower","flow","flight"]
# Output: "fl"
# 
# Example 2
# Input: strs = ["dog","racecar","car"]
# Output: ""

def longest_common_prefix(strs: list[str]) -> str:

    chr = ''
    chrIndex = 0

    # loop through each string, check if current index is shared in all strings
    while True:
        for i in range(len(strs)):

            # if we reach the end of any string, don't continue
            if chrIndex >= len(strs[i]):
                return '"' + strs[0][0:chrIndex] + '"'
            
            # if this is the first string in the list, get the character at chrIndex
            if i == 0:
                chr = strs[i][chrIndex]
            # if this is not the first string, check if it matches the characer we're looking for
            elif strs[i][chrIndex] != chr:
                return strs[0][0:chrIndex]
        
        # if we've made it through the whole list of strings, repeat with the next char
        chrIndex += 1

if __name__ == '__main__':

    words = ["flower","flow","flight"]
    prefix = longest_common_prefix(words)
    print(f"prefix: {prefix}")