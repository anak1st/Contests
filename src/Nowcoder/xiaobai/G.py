
# (ax+by)^n%p

def C(n : int, m : int) -> int:
    if m > n:
        return 0
    res = 1
    for i in range(m):
        res = res * (n - i) // (i + 1)
    return res

def pw(x : str, y : int) -> str:
    if y == 0:
        return ""
    if y == 1:
        return x
    return x + '^' + str(y)
def poly(c : int, ch1 : str, ch2 : str, x : int, y : int) -> str:
    res = ""
    if c != 1:
        res = str(c)
    X = pw(ch1, x)
    if len(X) > 0:
        if len(res) == 0:
            res = X
        else:
            res += "*" + X
    Y = pw(ch2, y)
    if len(Y) > 0:
        if len(res) == 0:
            res = Y
        else:
            res += "*" + Y
    return res

if __name__ == '__main__':
    inp = input()

    ch1 = inp[inp.find('+') - 1]
    ch2 = inp[inp.find(')') - 1]
    # print(ch1, ch2)

    p1 = inp.find('(')
    p2 = inp.find(ch1)
    a = 1
    if p1 + 1 != p2:
        a = int(inp[p1 + 1:p2])
    p3 = inp.find('+')
    p4 = inp.find(ch2, p3 + 1)
    b = 1
    if p3 + 1 != p4:
        b = int(inp[p3 + 1:p4])
    p5 = inp.find(')')
    p6 = inp.find('%')
    n = 1
    if p5 + 1 != p6:
        n = int(inp[p5 + 2:p6])
    p = int(inp[p6 + 1:])
    # print(a, b, n, p)

    ans = "0"
    if ch1 == ch2:
        a += b
        # print(a, n, p)

        con = pow(a, n, p)
        if con > 0:
            ans = ""
            if con != 1:
                ans = str(con) + "*"

            if n == 1:
                ans += ch1 + '%' + str(p)
            else:
                ans += ch1 + '^' + str(n) + '%' + str(p)

    else:
        cons = []
        cnt = 0
        for i in range(n + 1):
            cons.append(C(n, i) * pow(a, n - i, p) * pow(b, i, p) % p)
            if cons[-1] != 0:
                if cnt != 0:
                    ans += "+" + poly(cons[-1], ch1, ch2, n - i, i)
                else:
                    ans = poly(cons[-1], ch1, ch2, n - i, i)
                cnt += 1

        if cnt > 1:
            ans = "(" + ans + ")"
        if cnt > 0:
            ans += "%" + str(p)

    print(inp + " = " + ans)