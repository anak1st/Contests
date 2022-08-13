/**
 * @author: XiaFan
 * @date: 04-18 09:36
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int n, v;
    std::cin >> n >> v;
    std::vector<i64> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(v + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= v; j++) {
            if(j >= b[i]) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    std::cout << dp[n][v] << "\n";
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