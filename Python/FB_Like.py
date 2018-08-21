def who_likes_it(list):
    if len(list) == 0:
        return "no one likes this"
    elif len(list) == 1:
        return f"{list[0]} likes this"
    elif len(list) == 2:
        return f"{list[0]} and {list[1]} like this"
    elif len(list) == 3:
        return f"{list[0]}, {list[1]} and {list[2]} like this"
    else:
        return f"{list[0]}, {list[1]} and {len(list)-2} others like this"

assert who_likes_it([]) == "no one likes this", "Wrong like count!"
assert who_likes_it(["Ryszard"]) == "Ryszard likes this", "Wrong like count!"
assert who_likes_it(["Marcin", "Michal"]) == "Marcin and Michal like this", "Wrong like count!"
assert who_likes_it(["Edyta", "Igor", "Kamil"]) == "Edyta, Igor and Kamil like this", "Wrong like count!"
assert who_likes_it(["Michal", "Maciej", "Bartosz", "Przemek"]) == "Michal, Maciej and 2 others like this", "Wrong like count!"
