/**
 * @author: XiaFan
 * @date: 2023-09-11 23:30
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    auto ask = [&](int x) -> int {
        std::cout << "? " << x + 1 << std::endl;
        int res = 1;
        std::cin >> res;
        return res;
    };

    auto answer = [&](int x) -> void {
        std::cout << "! " << x << std::endl;
    };

    i64 xsum = ask(0);
    int z = n % k;
    if (z) {
        // std::cerr << 0 << " " << z / 2 << " " << z << "\n";
        xsum ^= ask(z / 2);
        xsum ^= ask(z);
    }
    
    for (int i = z + k; i + k <= n; i += k) {
        xsum ^= ask(i);
    }

    answer(xsum);
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}