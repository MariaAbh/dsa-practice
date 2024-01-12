def are_anagrams(a,b):
    if len(a) != len(b):
        return False
    la = [0] * 128
    lb = [0] * 128
    for i in range(len(a)):
        la[ord(a[i])] += 1
        lb[ord(b[i])] += 1
    for j in range(128):
        if lb[j] != la[j]:
            return False
    return True

a = "abbc"
b = "baab"
print(are_anagrams(a,b))

