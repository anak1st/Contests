/**
 * @author: XiaFan
 * @date: 04-17 18:36
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    for(int i = 0; i < 63; i++) {
        i64 add = (1ll << i);
        if(!(l & add) && l + add <= r) {
            l += add;
        }
    }
    std::cout << l << "\n";
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