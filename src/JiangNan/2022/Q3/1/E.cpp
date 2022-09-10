/**
 * @author: XiaFan
 * @date: 09-09 19:43
 **/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

typedef long long i64;

struct DSU {
    std::vector<int> f, siz;
    
    DSU(int n) : f(n), siz(n, 1) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int leader(int x) {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }

    bool same(int x, int y) { 
        return leader(x) == leader(y); 
    }

    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) { 
        return siz[leader(x)]; 
    }
};

struct road {
    int x, y, c;
    friend bool operator<(const road &a, const road &b) {
        return a.c < b.c;
    }
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<road> a(m);
    
    for (int i = 0; i < m; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].c;
        a[i].x--, a[i].y--;
    }

    DSU dsu(n);
    for (int i = 0; i < k; i++) {
        int t, x;
        std::cin >> t >> x;
        x--;
        for (int j = 1; j < t; j++) {
            int y;
            std::cin >> y;
            y--;
            dsu.merge(x, y);
        }
    }

    int ans = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        if (dsu.merge(a[i].x, a[i].y)) {
            ans += a[i].c;
        }
    }

    for (int i = 1; i < n; i++) {
        if (!dsu.same(0, i)) {
            ans = -1;
            break;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}