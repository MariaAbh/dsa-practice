def seven_split(s):
    words = []
    w = ""
    for i,c in enumerate(s):
        w += c
        if (i+1)%7 == 0 and i != 0:
            words.append(w)
            w = ""
    words.append(w)
    return words

s = "Hello WHello WHello W"
l = seven_split(s)
print(l)
