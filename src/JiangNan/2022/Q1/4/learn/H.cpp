#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

i64 fppower(i64 a, i64 x, i64 p) {
    i64 res = 1;
    a %= p;
    while(x) {
        if(x % 2) {
            res = (res * a) % p;
        }
        x /= 2;
        a = (a * a) % p;
    }
    return res;
}

void solve() {
    i64 p, m;
    std::cin >> p >> m;
    i64 res = 0;
    for(int i = 0; i < m; i++) {
        i64 a, b;
        std::cin >> a >> b;
        res = (res + fppower(a, b, p)) % p;
    }
    std::cout << res << '\n';
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