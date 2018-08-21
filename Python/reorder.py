import re

def reorder_substrings(sentence):
    for word in sentence.split():
        return re.findall('\d', word)

print(reorder_substrings("is2 Thi1s T4est 3a"))

# assert reorder_substrings("is2 Thi1s T4est 3a") == "Thi1s is2 3a T4est", "Failed!"
