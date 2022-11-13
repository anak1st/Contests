/**
 * @author: XiaFan
 * @date: 11-06 22:58
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;

    std::deque<std::pair<int, int>> op;

    if (n == 1) {
        if (a == b && a == "0") {
            std::cout << "YES\n";
            std::cout << 0 << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
        return;
    }

    int c1 = std::count(a.begin(), a.end(), '0');
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            a[i] = '1';
            b[i] = (b[i] - '0' + c1 - 1) % 2 + '0';
            op.push_back({i + 1, i + 1});
        } else {
            b[i] = (b[i] - '0' + c1) % 2 + '0';
        }
    }

    // std::cerr << "a: " << a << "\nb: " << b << "\n";  

    if (b != std::string(n, '0') && b != std::string(n, '1')) {
        std::cout << "NO\n";
        return;
    } 

    if (b == std::string(n, '1')) {
        op.push_back({1, 1});
        op.push_back({2, n});
    } else {
        op.push_back({1, n});
    }

    std::cout << "YES\n";
    std::cout << op.size() << "\n";
    for (auto [x, y] : op) {
        std::cout << x << " " << y << "\n";
    }
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