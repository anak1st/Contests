import queue

inf = 10 ** 9

n = int(input())
a = [[0] * n for i in range(n)]
for i in range(n):
    a[i] = list(map(float, input().split())) 
    # for j in range(n):
    #     if a[i][j] == 0:
    #         a[i][j] = inf

def print_path(path : list):
    l = len(path)
    for i in range(l):
        print(path[i] + 1, end='->' if i != l - 1 else '\n')

def print_matrix():
    for i in range(n):
        for j in range(n):
            print("{:.3f}".format(a[i][j]), end=' ' if j != n - 1 else '\n')
# print_matrix()

def tsp():
    cnt = 0
    start = 0, [0]
    q = queue.PriorityQueue()
    q.put(start)
    mn = inf
    ans_path = []
    while not q.empty():
        s, v = q.get()
        if cnt < 20:
            cnt += 1
            # print("{:.0f}".format(s), end=': ')
            print_path(v)
        if s >= mn:
            continue

        if len(v) == n:
            s += a[v[-1]][0]
            if s < mn:
                mn = s
                ans_path = v
            continue
        
        for i in range(0, n):
            if i not in v:
                if (s + a[v[-1]][i]) < mn:
                    q.put((s + a[v[-1]][i], v + [i]))
    
    return mn, ans_path

mn, ans_path = tsp()
if (abs(mn - round(mn)) < 0.0001):
    mn = int(mn)
    print(mn, end=': ')
    print_path(ans_path)
else:
    print("{:.3f}".format(mn), end=': ')
    print_path(ans_path)
