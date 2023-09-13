import math

def double_factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * double_factorial(n - 2)

def get_zeros(n):
    x = math.factorial(n)
    
    zeros = 0
    while x % 10 == 0:
        zeros += 1
        x //= 10

    return zeros


for i in range(2, 50, 2):
    print(get_zeros(i), end=' ')