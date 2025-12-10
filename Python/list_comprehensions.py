letters = ["a", "b", "c", "d", "e", "f", "g", "h", "i"]
vowels = ["a", "e", "i", "o", "u"]
vowels_in_letters = [c for c in letters if c in vowels]
print(vowels_in_letters)