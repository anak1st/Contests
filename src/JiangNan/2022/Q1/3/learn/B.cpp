#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

typedef long long i64;

inline i64 fun(i64 i, i64 j) {
    return i * (i + 100000) + j * (j - 100000) + i * j;
}

i64 numero(i64 n, i64 x) {
    i64 cur = 0;
    for(int j = 1; j <= n; j++) {
        i64 left = 1, right = n, c = 0;
        while(left <= right) {
            int i = (left + right) / 2;
            if(fun(i, j) <= x) {
                left = i + 1;
                c = i;
            } else {
                right = i - 1;
            }
        }
        cur += c;
    }
    return cur;
}

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    i64 left = -25000000000;
    i64 right = 75000000000;
    i64 ans = 0;
    while(left <= right) {
        i64 mid = (left + right) / 2;
        if(numero(n, mid) >= m) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}