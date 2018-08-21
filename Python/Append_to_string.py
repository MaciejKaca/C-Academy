def append_to_string(sentence):
    if len(sentence) >= 5:
        return sentence + " World"
    else:
        return "Welcome, " + sentence



assert append_to_string("Hello") == "Hello World", "Failed test case"
assert append_to_string("Hi") == "Welcome, Hi", "Failed test case"

