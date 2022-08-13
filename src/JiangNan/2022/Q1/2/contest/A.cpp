#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    int s1 = 0;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i - 1];
        s1 = std::max(s1, a[i]);
    }
    int m;
    std::cin >> m;
    std::vector<int> b(m + 1);
    int s2 = 0;
    for(int i = 1; i <= m; i++) {
        std::cin >> b[i];
        b[i] += b[i - 1];
        s2 = std::max(s2, b[i]);
    }

    std::cout << s1 + s2 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}