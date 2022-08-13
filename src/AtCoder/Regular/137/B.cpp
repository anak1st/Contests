#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int y1 = 0, y2 = 0, mn = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        int dy = x ? -1 : 1;
        y1 = std::min(0, y1 + dy);
        y2 = std::max(0, y2 + dy);
        mn = std::min(mn, y1);
        mx = std::max(mx, y2);
    }

    std::cout << mx - mn + 1 << '\n';
    return 0;
}