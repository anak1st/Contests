/**
 * @author: XiaFan
 * @date: 2023-08-07 12:36
 */
#include <bits/stdc++.h>
// #include <debug/vector>

using i64 = long long;

constexpr i64 BIT = 32;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b[i];
    }

    std::vector<i64> xsum(n);
    for (int i = 0; i < n - 1; i++) {
        xsum[i + 1] = xsum[i] ^ b[i];
    }
    
    // for (int i = 0; i < n; i++) {
    //     std::cerr << xsum[i] << " \n"[i == n - 1];
    // }

    std::vector<i64> bit(BIT, -1);

    for (i64 i = 0; i < n - 1; i++) {
        for (i64 j = BIT - 1; j >= 0; j--) {
            bool x = xsum[i] >> j & 1;
            bool y = xsum[i + 1] >> j & 1;
            if (x != y) {
                if (x) {
                    if (bit[j] == 0) {
                        std::cout << -1 << '\n';
                        return;
                    }
                    bit[j] = 1;
                } else {
                    if (bit[j] == 1) {
                        std::cout << -1 << '\n';
                        return;
                    }
                    bit[j] = 0;
                }
                break;
            }
        }
    }

    i64 zero = std::count(bit.begin(), bit.end(), -1);
    i64 max = 1LL << zero;

    // std::cerr << k << " " << max << '\n';
    k--;
    if (k >= max) {
        std::cout << -1 << '\n';
        return;
    }
    

    for (int i = 0, j = 0; i < BIT && j < BIT; i++) {
        while (j < BIT && bit[j] != -1) {
            j++;
        }
        if (j < BIT) {
            bit[j] = (k >> i) & 1;
        }
    }

    // for (int i = 0; i < 30; i++) {
    //     std::cerr << bit[i] << " \n"[i == 29];
    // }

    std::vector<i64> a(n);
    for (int i = 0; i < BIT; i++) {
        a[0] |= bit[i] << i;
    }
    for (int i = 0; i < n - 1; i++) {
        a[i + 1] = a[i] ^ b[i];
    }

    i64 max_ele = *std::max_element(a.begin(), a.end());
    if (max_ele >= (1LL << 30)) {
        std::cout << -1 << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
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