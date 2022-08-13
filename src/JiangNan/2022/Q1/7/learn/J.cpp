/**
 * @author: XiaFan
 * @date: 04-18 20:02
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int f, v;
    std::cin >> f >> v;
    std::vector<std::vector<int>> a(f + 1, std::vector<int>(v + 1));
    for(int i = 1; i <= f; i++) {
        for(int j = 1; j <= v; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> dp(f + 1, std::vector<int>(v + 1));
    for(int i = 1; i <= f; i++) {
        dp[i][i] = dp[i - 1][i - 1] + a[i][i];
        for(int j = i + 1; j <= v; j++) {
            dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j - 1] + a[i][j]);
        }
    }

    std::cout << dp[f][v] << "\n";

    return 0;
}