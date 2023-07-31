/**
 * @author: XiaFan
 * @date: 2023-07-28 00:26
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<std::pair<int, int>> a(m);
    for (auto &[x, y] : a) {
        std::cin >> x >> y;
    }
    std::vector<int> first0(n, -1);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            first0[i] = i;
        } else if (i > 0) {
            first0[i] = first0[i - 1];
        }
    }

    std::vector<int> last1(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            last1[i] = i;
        } else if (i < n - 1) {
            last1[i] = last1[i + 1];
        }
    }

    std::set<std::pair<int, int>> real;

    for (auto [l, r] : a) {
        l--;
        r--;
        l = last1[l];
        r = first0[r];
        // std::cerr << l << " " << r << "\n";
        if (l >= 0 && r >= 0 && l < r) {
            real.insert({l, r});
        } else {
            real.insert({-1, -1});
        }
    }

    std::cout << real.size() << "\n";
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