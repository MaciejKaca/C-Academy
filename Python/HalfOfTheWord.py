def remove_chars(sentence):
     return sentence[0:len(sentence)//2]

assert remove_chars("Tieto") == "Ti", "Failed test case"
assert remove_chars("Work") == "Wo", "Failed test case"
assert remove_chars("Academy") == "Aca", "Failed test case"