import numpy as np

def fab(x : int) -> int:
    if x < 1:
        return 1
    return fab(x-1) + fab(x-2)

if __name__ == "__main__":
    while True:
        s = input()
        if len(s) == 0:
            break
        # remove all blank space
        s = s.replace(" ", "")
        s = s.replace("\t", "")
        s = s.replace("\r", "")
        s = s.replace("\n", "")

        if len(s) == 0:
            break

        print(s, end="")
