/**
 * @author: XiaFan
 * @date: 2023-03-11 19:16
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 100 + 5;
// dp[i][j][k][l] 表示前 i 个点，选择了 
// j 个 A，
// k 个 B，
// l 个 C, 
// i - j - k - l 个 D 
// 的最大值
i64 dp[N][N][N][N];

void chmax(i64 &a, i64 b) {
    a = std::max(a, b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(4));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; j + k < i; k++) {
                for (int l = 0; j + l + k < i; l++) {
                    // int z = i - j - k - l;
                    // 选择 a
                    chmax(dp[i][j + 1][k][l], dp[i - 1][j][k][l] + a[i][0]);
                    // 选择 b
                    chmax(dp[i][j][k + 1][l], dp[i - 1][j][k][l] + a[i][1]);
                    // 选择 c
                    chmax(dp[i][j][k][l + 1], dp[i - 1][j][k][l] + a[i][2]);
                    // 选择 d
                    chmax(dp[i][j][k][l], dp[i - 1][j][k][l] + a[i][3]);
                }
            }
        }
    }

    i64 ans = dp[n][n / 4][n / 4][n / 4];

    std::cout << ans << '\n';

    return 0;
}