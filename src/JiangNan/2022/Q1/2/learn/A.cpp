#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin() + 1, a.end());

    int ans = 0;
    while(n >= 4) {
        int mn1 = 2 * a[1] + a[n - 1] + a[n];
        int mn2 = a[1] + 2 * a[2] + a[n];
        n -= 2;
        ans += std::min(mn1, mn2);
    }
    if(n == 1) {
        ans += a[1];
    } else if(n == 2) {
        ans += a[2];
    } else if(n == 3) {
        ans += (a[1] + a[2] + a[3]);
    }
    std::cout << ans << '\n';
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