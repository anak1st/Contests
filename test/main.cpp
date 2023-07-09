/**
 * @author: XiaFan
 * @date: 2023-06-18 15:46
 */
#include <bits/stdc++.h>

using i64 = long long;

int calc_dif(const std::string& a, const std::string& b) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            ++ans;
        }
    }
    return ans;
}

int fun(int d) {
    int ans = 0;
    if (d % 2) {
        ans = 2 * d - 1;
    } else {
        ans = 2 * d;
    }
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;

    int d1 = calc_dif(a, b);
    std::reverse(b.begin(), b.end());
    int d2 = calc_dif(a, b);
    if (d1 <= 1) {
        std::cout << d1 << '\n';
        return;
    }

    int ans = std::min(fun(d1), 2 + fun(std::max(0, d2 - 1)));
    
    std::cout << ans << '\n';
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