import sys
from collections import OrderedDict


testCases = open(sys.argv[1], 'r')
for word in testCases:
    if len(word) == 0:
        continue

    word = word.strip()
    charCount = OrderedDict()
    for letter in word:
        if letter in charCount:
            charCount[letter] += 1
        else:
            charCount[letter] = 1

    for key, value in charCount.items():
        if value == 1:
            print(key)
            break
