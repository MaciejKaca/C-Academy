def count_duplicates(sentence, how_many_times):
    result=""
    for char in sentence:
        count = sentence.count(char)
        if count == how_many_times and result.count(char) == 0:
            result+=char

    return result

assert count_duplicates("aabcdddee", 2) == "ae", "Failed to count!" # only 'a' end 'e' were present 2 times.
assert count_duplicates("indivisibility", 6) == "i", "Failed to count!"
assert count_duplicates("Karima", 1) == "Krim", "Failed to count!"


