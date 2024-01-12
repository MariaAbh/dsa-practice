def closest_to_zero(l):
    mini = float('inf')
    for f in l:
        if abs(f) < abs(mini):
            mini = f
    return mini

l = [1.2,2.3,-1.0,-0.5,0.2,5.3]
print(closest_to_zero(l))
