#include <bits/stdc++.h>

typedef long long i64;

void solve() {
    i64 n, a, b;
    std::cin >> n >> a >> b;

    if(a == 1) {
        if((n - 1) % b == 0) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
        return;
    }

    for(i64 i = 1; i <= n; i *= a) {
        if((n - i) % b == 0) {
            std::cout << "Yes\n";
            return;
        }
    }

    std::cout << "No\n";
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