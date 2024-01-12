def max_sum(a):
    start = 0
    maxi = a[0]
    while start < len(a)-1:
        end = len(a)-1
        while end > start:
            s = 0
            for i in range(start,end):
                s += a[i]
            if s > maxi:
                maxi = s
            end -= 1
        start += 1
    return maxi

a = [1,2,3,4,-10]
print(max_sum(a))

a = [-2,1,-3,4,-1,2,1,-5,4]
print(max_sum(a))
