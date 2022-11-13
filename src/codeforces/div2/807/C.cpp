/**
 * @author: XiaFan
 * @date: 07-21 21:12
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, c, q;
    std::cin >> n >> c >> q;
    std::string s;
    std::cin >> s;
    std::vector<std::array<i64, 3>> a(c + 1);
    a[0][0] = (i64)s.length() - 1;
    for (int i = 1; i <= c; i++) {
        std::cin >> a[i][1] >> a[i][2];
        a[i][1]--, a[i][2]--;
        a[i][0] = a[i - 1][0] + a[i][2] - a[i][1] + 1;
    }

    std::function<i64(i64)> find = [&](i64 p) -> i64 {
        if (p < (i64)s.length()) {
            return p;
        } else {
            i64 i = std::lower_bound(a.begin(), a.end(), std::array<i64, 3>{p, 0, 0}) - a.begin();
            return find(p - a[i - 1][0] - 1 + a[i][1]);
        }
    };

    while (q--) {
        i64 x;
        std::cin >> x;
        x--;
        std::cout << s[find(x)] << "\n";
    }
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