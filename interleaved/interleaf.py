def interleave(s1,s2,s3):
    if len(s1) == 0 and len(s2) == 0:
        return True
    if len(s1) > 0 and s1[0] == s3[0]:
        return interleave(s1[1:],s2,s3[1:])
    if len(s2) > 0 and s2[0] == s3[0]:
        return interleave(s1,s2[1:],s3[1:])
    return False

s1 = "aab"
s2 = "cd"
s3 = "aacdb"
print(interleave(s1,s2,s3))

s1 = "abb"
s2 = "baa"
s3 = "abbbaa"
s4 = "ababba"
print(interleave(s1,s2,s3))
print(interleave(s1,s2,s4))
