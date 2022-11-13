/**
 * @author: XiaFan
 * @date: 09-08 19:21
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct DSU {
    std::vector<int> f, s;
    
    DSU(int n) : f(n), s(n, 1) { 
        std::iota(f.begin(), f.end(), 0); 
    }

    int find(int x) {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
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

void solve() {
    int n;
    std::cin >> n;
    n *= 2;
    std::string s;
    std::cin >> s;

    DSU dsu(n);
    std::vector<int> a(n, -1);
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == '(') {
            if (a[j] != -1) {
                dsu.merge(i, a[j]);
            }
            a[j] = i;
            j++;
        } else {
            j--;
            if (a[j] != -1) {
                dsu.merge(i, a[j]);
                a[j + 1] = -1;
            }
        }
    }
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(dsu.find(i));
    }
    std::cout << st.size() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}