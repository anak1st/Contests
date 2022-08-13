#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int sum = 0, mn = 200, nega = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            if(x < 0) {
                nega++;
            }
            x = std::abs(x);
            sum += x;
            mn = std::min(mn, x);
        }
    }

    if(nega % 2 == 0) {
        std::cout << sum << '\n';
    } else {
        std::cout << sum - 2 * mn << '\n';
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