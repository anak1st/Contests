/**
 * @author: XiaFan
 * @date: 09-30 20:28
 **/
#include <bits/stdc++.h>
using i64 = long long;

class DSU {
private:
    std::vector<int> f, s;

public:
    DSU(int n) : f(n), s(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        s[x] += s[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return s[find(x)];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    DSU dsua(n), dsub(n);
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] + a[i + 1]) % 2 == 0) {
            dsua.merge(i, i + 1);
        }
        if ((b[i] + b[i + 1]) % 2 == 0) {
            dsub.merge(i, i + 1);
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if (dsua.same(x1, x2) && dsub.same(y1, y2)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}