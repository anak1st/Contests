#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    int ans = 1LL * (n - 1) * a / b;
    if(1LL * ans * b <= 1LL * a * (n - 1)) {
        ans++;
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