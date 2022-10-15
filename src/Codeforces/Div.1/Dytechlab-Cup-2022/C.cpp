/**
 * @author: XiaFan
 * @date: 10-13 20:26
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p(3);
    std::map<int, int> mpa, mpb;
    for (auto &[a, b] : p) {
        std::cin >> a >> b;
        mpa[a]++;
        mpb[b]++;
    }
    int tx, ty;
    std::cin >> tx >> ty;
    int x = 0, y = 0;
    for (auto [key, val] : mpa) {
        if (val > mpa[x]) {
            x = key;
        }
    }
    for (auto [key, val] : mpb) {
        if (val > mpb[y]) {
            y = key;
        }
    }
    if ((x == 1 || x == n) && (y == 1 || y == n)) {
        if (tx == x || ty == y) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
        return;
    }
    int dx = std::abs(x - tx);
    int dy = std::abs(y - ty);
    if (dx % 2 == 1 && dy % 2 == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
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