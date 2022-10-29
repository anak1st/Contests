while True:
    try:
        s = input()
        n, m = map(int, s.split())
        if n < m:
            print(0)
        else:
            f = [[0 for i in range(m + 1)] for j in range(n + 1)]
            
            f[0][0] = 1
            for i in range(1, n + 1):
                for j in range(1, m + 1):
                    f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j]

            print(f[n][m])
    except:
        break
