/**
 * @author: XiaFan
 * @date: 04-19 23:50
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int l, r;
    std::cin >> l >> r;
    int mod = r / 2 + 1;
    if(l <= mod) {
        std::cout << r % mod << '\n';
    } else {
        std::cout << r % l << '\n';
    }
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