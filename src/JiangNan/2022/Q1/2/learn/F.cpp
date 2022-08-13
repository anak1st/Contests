#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    i64 sum = 0;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    std::sort(a.begin() + 1, a.end());
    int m;
    std::cin >> m;
    for(int i = 1; i <= m; i++) {
        int q;
        std::cin >> q;
        std::cout << sum - a[n - q + 1] << '\n';
    }

    return 0;
}