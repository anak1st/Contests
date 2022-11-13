/**
 * @author: XiaFan
 * @date: 11-11 21:06
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::map<int, std::vector<int>> f[2];
    std::vector<int> sum(n + 1), xsum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        xsum[i] = xsum[i - 1] ^ a[i];
        f[i % 2][xsum[i]].push_back(i);
    }

    auto fun = [&](int l, int r) -> int {
        if (sum[r] - sum[l - 1] == 0) {
            return 0;
        }
        if (xsum[r] != xsum[l - 1]) {
            return -1;
        }
        if (a[l] == 0 || a[r] == 0 || (r - l) % 2 == 0) {
            return 1;
        }

        auto& b = f[l % 2][xsum[l - 1]];
        auto p = std::lower_bound(b.begin(), b.end(), l);
        if (p != b.end() && *p <= r) {
            return 2;
        }

        return -1;
    };

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << fun(l, r) << "\n";
    }
    
    return 0;
}