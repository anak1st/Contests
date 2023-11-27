#include <bits/stdc++.h>

constexpr int N = 5e5 + 10;

std::vector<std::pair<int, int>> Q[N];

int n, m;
int a[N];
int tr[N];
int last[N];

constexpr int lowbit(int x) { return x & (-x); }

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += k;
    }
}
int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

void solve() {
    std::cin >> n >> m;
    std::vector<std::vector<int>> st(n + 10);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] <= n) {
            st[a[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        st[i].push_back(n + 1);
        last[a[i]] = n + 2;
    }
    for (int mex = 1; mex <= n + 1; mex++) {
        int lst = 1;
        for (auto x : st[mex]) {
            int l = lst;
            int r = x - 1;
            if (l <= r) {
                Q[r].push_back({l, mex});
            }
            lst = x + 1;
        }
    }
    int ans = -1e9;
    for (int r = 1; r <= n; r++) {
        add(last[a[r]], -1);
        last[a[r]] = r;
        add(last[a[r]], 1);
        for (auto [l, val] : Q[r]) {
            ans = std::max(ans, query(r) - query(l - 1) - val);
        }
        Q[r].clear();
    }
    for (int i = 1; i <= n; i++) {
        tr[i] = 0;
    }
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}