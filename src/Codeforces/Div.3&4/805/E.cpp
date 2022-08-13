/**
 * @author: XiaFan
 * @date: 07-20 16:25
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class DisjointSet {
private:
    int n;
    std::vector<int> f;

public:
    DisjointSet(int _n) : n(_n), f(_n) {
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

    bool unity(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};

void solve() {
    int n;
    cin >> n;
    DisjointSet ds(n);
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        vis[a]++; vis[b]++;
        ds.merge(a, b);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] != 2) {
            cout << "No\n";
            return;
        }
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[ds.find(i)]++;
    }

    for (auto [x, y] : mp) {
        if (y % 2 == 1) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}