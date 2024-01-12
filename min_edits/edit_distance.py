def min_edit(a,b):
    if len(b) == 0:
        return 0
    if len(a) == 0 and len(b) != 0:
        return len(b)
    if a[0] == b[0]:
        return min_edit(a[1:],b[1:])
    insert = b[0] + a
    delete = a[1:]
    replace = b[0] + a[1:]
    return min(
            1 + min_edit(insert , b),
            1 + min_edit(delete , b),
            1 + min_edit(replace , b)
            )

a = "abad"
b = "abac"
print(min_edit(a,b))
print('-----------')
a = "anshuman"
b = "antihuman"
print(min_edit(a,b))
