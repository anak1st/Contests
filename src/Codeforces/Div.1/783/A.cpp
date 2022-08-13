/**
 * @author: XiaFan
 * @date: 04-22 23:03
 **/
#include <bits/stdc++.h>

typedef long long i64;

void solve() {
    int n, m;
    std::cin >> n >> m;
    if((n == 1 && m >= 3) || (m == 1 && n >= 3)) {
        std::cout << "-1\n";
        return;
    }
    n--, m--;
    int a = std::min(n, m);
    n -= a, m -= a;
    int b = n + m;
    int add = b / 2;
    std::cout << a * 2 + b + add * 2 << '\n';
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