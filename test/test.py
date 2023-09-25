import math

def fun(x, n=9):
    return x ** n * math.exp(x - 1)


def integral(start, end, step):
    result = 0
    while start < end:
        result += fun(start) * step
        start += step
    return result

print(integral(0, 1, 1e-8))