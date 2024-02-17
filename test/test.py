import numpy as np

a, b = 0, 1
for _ in range(10):
    print(f"fibonacci({_}) = {a}")
    a, b = b, a + b

def test():
    a = np.ones((3, 3))
    b = np.ones((3, 3))
    c = a @ b
    print("a: ", a, "\nb: ", b, "\nc: ", c)

if __name__ == "__main__":
    test()