def longest_sub(a, acc):
    # print(f'{acc,a=}')
    if acc == None:
        acc = []
    if len(a) == 0:
        return len(acc)
    if len(acc) != 0 and acc[-1] >= a[0]:
        return longest_sub(a[1:],acc)
    elif (len(acc) != 0 and acc[-1] < a[0]) or len(acc) == 0:
        return max(longest_sub(a[1:],acc+[a[0]]),longest_sub(a[1:],acc))

A = [1, 2, 1, 5]
print(longest_sub(A,acc=None))
print('-----------')
A = [3,4,1,2]
print(longest_sub(A,acc=None))
print('-----------')
A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
print(longest_sub(A,acc=None))
print('-----------')
nums = [10,9,2,5,3,7,101,18]
print(longest_sub(nums,acc=None))
