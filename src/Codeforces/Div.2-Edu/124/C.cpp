#include <bits/stdc++.h>

using i64 = long long;
constexpr int INF = 1E9;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n), b(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    i64 ans = std::min(std::abs(a[0] - b[0]) + std::abs(a[n - 1] - b[n - 1]),
                       std::abs(a[0] - b[n - 1]) + std::abs(a[n - 1] - b[0]));

    i64 a1 = INF, b1 = INF, an = INF, bn = INF;
    for(int i = 0; i < n; i++) {
        a1 = std::min(a1, std::abs(a[0] - b[i]));
        an = std::min(an, std::abs(a[n - 1] - b[i]));
        b1 = std::min(b1, std::abs(b[0] - a[i]));
        bn = std::min(bn, std::abs(b[n - 1] - a[i]));
    }

    ans = std::min({ans,
                    std::abs(a[0] - b[0]) + an + bn,
                    std::abs(a[0] - b[n - 1]) + an + b1,
                    std::abs(a[n - 1] - b[0]) + a1 + bn,
                    std::abs(a[n - 1] - b[n - 1]) + a1 + b1});

    ans = std::min(ans, a1 + an + b1 + bn);

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}