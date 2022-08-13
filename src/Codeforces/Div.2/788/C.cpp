/**
 * @author: XiaFan
 * @date: 05-09 20:12
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int p = 1e9 + 7;

struct fset {
    int n;
    std::vector<int> f;

    fset(int size) : n(size), f(size) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        f[rx] = ry;
    }

    bool is_unity(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    fset f(n);
    for (int i = 0; i < n; i++) {
        f.merge(a[i], b[i]);
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp[f.find(a[i])] != -1) {
            mp[f.find(a[i])]++;
        }
        if (c[i] >= 0) {
            mp[f.find(a[i])] = -1;
        }
    }
    i64 ans = 1;
    for (auto [_, i] : mp) {
        if (i > 1) {
            ans = (ans * 2) % p;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}