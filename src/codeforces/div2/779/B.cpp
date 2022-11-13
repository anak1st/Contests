#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    if(n % 2 == 1) {
        std::cout << "0\n";
        return;
    }
    i64 ans = 1;
    for(int i = 1; i <= n / 2; i++) {
        ans = ans * i % mod * i % mod;
    }

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