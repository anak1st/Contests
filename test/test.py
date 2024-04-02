def main():
    n, a, b = map(int, input().split())
 
    if n < 100 and pow(2, n) * a < b:
        print("-1")
        return
 
    for i in range(0, min(100, n + 1)):
        if pow(2, i) * a > b:
            print(i)
            return
        
    print("-1")
 
 
if __name__ == "__main__":
    main()