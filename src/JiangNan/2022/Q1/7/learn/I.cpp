/**
 * @author: XiaFan
 * @date: 04-18 19:37
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

// Longest Increasing Subsequence

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << "\n";

    return 0;
}