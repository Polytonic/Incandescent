from collections import Counter

# This one is more easily solved by taking advantage of
# the strong Python standard library, specifically the
# Counter class. Check that the ransom word exists in the
# magazine and that the frequency of which that word occurs
# does not exceed the quantity found in the magazine.

def ransom_note(magazine, ransom):

    magazine_words = Counter(magazine)
    ransom_words = Counter(ransom)

    for word in ransom_words:
        if not word in magazine_words:
            return False
        if ransom_words[word] > magazine_words[word]:
            return False

    return True

m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
    print("Yes")
else:
    print("No")

