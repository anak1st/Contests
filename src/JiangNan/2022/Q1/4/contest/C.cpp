#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

void solve() {
    i64 x;
    std::cin >> x;
    if(x == 1) {
        std::cout << 0 << '\n';
    } else if(x == 2) {
        std::cout << 1 << '\n';
    } else if(x == 3 || x % 2 == 0) {
        std::cout << 2 << '\n';
    } else {
        std::cout << 3 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}