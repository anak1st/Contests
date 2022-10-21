/**
 * @author: XiaFan
 * @date: 10-18 20:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = a[i] - a[i - 1];
    }
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](const int &i, const int &j) -> bool {
        return b[i] > b[j];
    });
    for (int i = 0; i < n; i++) {
        std::cout << p[i] + 1 << " ";
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