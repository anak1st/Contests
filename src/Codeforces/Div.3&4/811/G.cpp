/**
 * @author: XiaFan
 * @date: 08-10 23:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::array<i64, 3>> edge(n);
    for (int i = 1; i < n; i++) {
        std::cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        edge[i][0]--;
    }

    std::vector<std::array<i64, 4>> ans(n, std::array<i64, 4>{-1, 0, 0, 0});
    ans[0][0] = 0;
    ans[0][1] = 0;
    ans[0][2] = 0;
    ans[0][3] = 0;

    std::function<int(int, i64)> find = [&](int x, i64 A) -> int {
        if (ans[x][2] <= A) {
            return ans[x][3];
        } else {
            auto [f, a, b] = edge[x];
            return find(f, A);
        }
    };

    std::function<int(int)> fun = [&](int x) -> int {
        if (ans[x][0] == -1) {
            auto [f, a, b] = edge[x];
            fun(f);
            ans[x][1] = ans[f][1] + a;
            ans[x][2] = ans[f][2] + b;
            ans[x][3] = ans[f][3] + 1;
            ans[x][0] = find(x, ans[x][1]);
        }
        return ans[x][0];
    };

    for (int i = 1; i < n; i++) {
        std::cout << fun(i) << " ";
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