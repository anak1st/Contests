/**
 * @author: XiaFan
 * @date: 2023-01-30 13:50
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }
    
    auto norm = [&](int x) -> int {
        return (x % m + m) % m;
    };

    std::vector<int> a(n), b(n);
    for (int i = 0; i < (n + 1) / 2; ++i) {
        int j = n - i - 1;
        int sum = norm(c[i] + c[j]);
        if (sum % 2) {
            sum += m;
        }
        if (sum % 2) {
            std::cout << "No\n";
            return 0;
        }
        a[i] = sum / 2;
        a[j] = a[i];
        b[i] = norm(c[i] - a[i]);
        b[j] = norm(-b[i]);
        if (norm(c[j]) != norm(a[j] + b[j])) {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }

    return 0;
}