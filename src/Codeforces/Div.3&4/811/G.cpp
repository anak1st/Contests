/**
 * @author: XiaFan
 * @date: 08-10 23:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct edge {
    int i;
    i64 a, b;
    edge(int _i = 0, i64 _a = 0, i64 _b = 0) : i(_i), a(_a), b(_b) {}
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<edge>> G(n);
    for (int i = 1; i < n; i++) {
        int p;
        i64 a, b;
        std::cin >> p >> a >> b;
        G[p - 1].push_back(edge(i, a, b));
    }

    std::vector<i64> temp, ans(n, -1);
    std::function<void(int, i64)> dfs = [&](int i, i64 A) {
        ans[i] = std::upper_bound(temp.begin(), temp.end(), A) - temp.begin() - 1;

        for (auto [son, a, b] : G[i]) {
            i64 last = temp.back();
            temp.push_back(b + last);
            dfs(son, A + a);
            temp.pop_back();
        }
    };

    temp.push_back(0);
    dfs(0, 0);

    for (int i = 1; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
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