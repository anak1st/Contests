/**
 * @author: XiaFan
 * @date: 08-01 20:41
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &i : a) {
        std::cin >> i;
    }
    std::vector<int> b(n);
    int Q = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= Q) {
            b[i] = 1;
        } else if (Q < q) {
            b[i] = 1;
            Q++;
        } else {
            b[i] = 0;
        }
    }
    for (auto i : b) {
        std::cout << i;
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}