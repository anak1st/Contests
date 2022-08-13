#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

void solve() {
    int x;
    std::cin >> x;
    std::cout << 1 << ' ' << x - 1 << '\n';
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