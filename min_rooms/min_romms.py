def min_rooms(a):
    start_times = []
    end_times = []
    count = len(a)
    for ir,row in enumerate(a):
        for ic,elem in enumerate(row):
            if ic == 0:
                start_times.append(elem)
            else:
                end_times.append(elem)
    visited = []
    for e in end_times:
        for s in start_times:
            if s >= e and (e not in visited and s not in visited):
                visited.append(e)
                count -= 1
    return count

A = [
        [0, 30],
        [5, 10],
        [15, 20],
    ]
print(min_rooms(A))

A = [
        [1, 18],
        [18, 23],
        [15, 29],
        [4, 15],
        [2, 11],
        [5, 13],
     ]
print(min_rooms(A))
