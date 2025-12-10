function longestSubstringNoRepeats(s) {

    let left = 0;
    let chars = new Set();
    const len = s.length;
    let longest = 0;
    
    for (let right = 0; right < len; right++) {

        while (chars.has(s[right])) {
            chars.delete(s[left]);
            left++;
        }

        chars.add(s[right]);

        longest = Math.max(longest, right - left + 1);
    }

    return longest;
}

result = longestSubstringNoRepeats("aabcdeefg")
console.log(`result: ${result}`)