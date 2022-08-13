#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    std::sort(a.begin(), a.end());

    a[0] %= (i64)(n - 1);
    i64 mx = a[n - 1];
    if(sum < mx * (n - 1)) {
        std::cout << mx * (n - 1) - sum << '\n';
    } else {
        if(sum % (n - 1) == 0) {
            std::cout << 0 << '\n';
        } else {
            std::cout << (n - 1) - (sum % (n - 1)) << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}