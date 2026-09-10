def is_anagram(s,t):
    dict1 = {}
    dict2 = {}

    for i in s:
        if i in dict1:
            dict1[i] += 1
        else:
            dict1[i] = 1

    for i in t:
        if i in dict2:
            dict2[i] += 1
        else:
            dict2[i] = 1

    if dict1 == dict2:
        return True

    return False


s = input("Enter first string: ")
t = input("Enter second string: ")

print(is_anagram(s,t))