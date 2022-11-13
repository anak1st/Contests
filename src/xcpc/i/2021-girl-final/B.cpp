/**
 * @author: XiaFan
 * @date: 10-17 20:09
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int m, n;
    std::cin >> m >> n;

    int logn = 18; // log2(n) + 1;
    std::string s;
    std::cin >> s;
    s = '!' + s;

    std::vector<int> next(m, n + 1);
    std::vector<std::vector<int>> go(logn, std::vector<int>(n + 2));
    go[0][n + 1] = n + 1;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            go[0][i] = std::max(go[0][i], next[j]);
        }
        if (i >= 1) {
            next[s[i] - 'a'] = i;
        }
    }

    for (int i = 1; i < logn; i++) {
        for (int j = 0; j <= n + 1; j++) {
            int first = go[i - 1][j];
            go[i][j] = go[i - 1][first];
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        int t = l - 1;
        int ans = 1;
        for (int d = logn - 1; d >= 0; d--) {
            if (go[d][t] <= r) {
                t = go[d][t];
                ans += (1 << d);
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}