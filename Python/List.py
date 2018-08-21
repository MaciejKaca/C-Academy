def filter_list(list):
    new_list=[]
    for element in list:
        if type(element) is int:
            new_list.insert(len(new_list), element)
    return new_list

def filter_list1(list): #using list comprehensions
    return [element for element in list if type(element) is int]


print(filter_list1([12, "A", 3, "d"]))