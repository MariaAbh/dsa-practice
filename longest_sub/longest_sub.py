# Given two strings, S1 and S2, the task is to find the length of the Longest Common Subsequence, i.e. longest subsequence present in both of the strings. 
import functools

def calls_nb(calls):
    util = len(calls.values())
    not_util = sum([i-1 for i in calls.values()])
    return util,not_util

# @functools.cache
def longest_common(s1,s2):
    global calls
    if (s1,s2) not in calls:
        calls[(s1,s2)] = 1
    else:
        calls[(s1,s2)] += 1

    if len(s1) == 0 or len(s2) == 0:
        return 0
    if s1[0] == s2[0]:
        return 1+longest_common(s1[1:],s2[1:])
    else:
        return max(longest_common(s1[1:],s2), longest_common(s1,s2[1:]))

memo = {}
def longest_common_memo(s1,s2):
    global memo
    global calls
    
    if (s1,s2) in memo:
        return memo[(s1,s2)]
    else:
        if (s1,s2) not in calls:
            calls[(s1,s2)] = 1
        else:
            calls[(s1,s2)] += 1

        if len(s1) == 0 or len(s2) == 0:
            memo[(s1,s2)] = 0
        elif s1[0] == s2[0]:
            memo[(s1,s2)] = 1+longest_common_memo(s1[1:],s2[1:])
        else:
            memo[(s1,s2)] = max(longest_common_memo(s1[1:],s2), longest_common_memo(s1,s2[1:]))
        return memo[(s1,s2)]

s1 = "AGGTAB"
s2 = "GXTXAYB"
calls = {}
print(longest_common(s1,s2))
print(calls_nb(calls))
calls = {}
print(longest_common_memo(s1,s2))
# print(calls)
print(calls_nb(calls))
s1 = "BD"
s2 = "ABCD"
calls = {}
print(longest_common(s1,s2))
# print(calls)
print(calls_nb(calls))
s1 = "ABABABAB"
s2 = "CBACBACBA"
calls = {}
print(longest_common(s1,s2))
# print(calls)
print(calls_nb(calls))
