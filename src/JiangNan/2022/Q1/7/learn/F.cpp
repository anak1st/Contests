/**
 * @author: XiaFan
 * @date: 04-18 13:07
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            std::cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        b[i][1] = b[i - 1][1] + a[i][1];
        if(i >= 2) {
            b[i][i] = b[i - 1][i - 1] + a[i][i];
        }
        for(int j = 2; j <= i - 1; j++) {
            b[i][j] = std::max(b[i - 1][j - 1], b[i - 1][j]) + a[i][j];
        }
    }

    int ans = -1e9;
    for(int i = 1; i <= n; i++) {
        ans = std::max(ans, b[n][i]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}