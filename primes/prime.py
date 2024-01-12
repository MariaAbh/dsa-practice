def is_prime(a):
    for i in range(2,a):
        if a % i == 0:
            return False
    return True

for i in range(1,51):
    if is_prime(i):
        print(i)
