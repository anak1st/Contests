/**
 * @author: XiaFan
 * @date: 2023-07-21 15:58
 */
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n = 0;
    std::cin >> n;
    std::bitset<64> bit1 = n;
    int size = std::__lg(bit1.to_ullong()) + 1;
    std::cerr << size << '\n';
    u64 mod = (1ull << size);
    std::bitset<64> bit2 = (u64(- n - 1)) % mod;

    std::cout << bit1.to_string() << '\n';
    std::cout << bit2.to_string() << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}