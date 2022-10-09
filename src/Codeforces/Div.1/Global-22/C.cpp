/**
 * @author: XiaFan
 * @date: 09-30 23:17
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(2);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[a[i] % 2]++;
    }
    //std::cout << b[0] << " " << b[1] << "\n";

    if ((n + 1) / 2 % 2 == 1 && b[0] < n - 1) {
        std::cout << "Bob\n";
        return;
    }

    if (n <= 2) {
        if (b[0] >= 1) {
            std::cout << "Alice\n";
        } else {
            std::cout << "Bob\n";
        }
        return;
    }

    if (n == 3) {
        if (b[0] == 0 || b[0] == n) {
            std::cout << "Alice\n";
        } else {
            std::cout << "Bob\n";
        }
        return;
    }

    if (n == 4 && b[0] == b[1]) {
        std::cout << "Bob\n";
        return;
    }

    std::cout << "Alice\n";
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