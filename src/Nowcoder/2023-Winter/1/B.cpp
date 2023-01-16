#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
const int mod = 998244353;
// dp([i])[j][s][t]
const int mx = 41 * 3;
int dp[125][102][102];
int line[125][102][102], up[125][102][102], down[125][102][102];
// line: 一道左上方向的斜线上的求和 ;up: 一个上三角形状部分的求和 ;down:
// 一个下三角形状部分的求和
int main() {
    cin >> n >> m >> x >> y;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        // 存储i-1 轮后的数据
        for (int j = 0; j <= mx; j++) {
            for (int u = 0; u <= x; u++) line[j][u][0] = down[j][u][0] = dp[j][u][0];
            for (int v = 0; v <= y; v++) line[j][0][v] = up[j][0][v] = dp[j][0][v];
            for (int u = 1; u <= x; u++) {
                for (int v = 1; v <= y; v++) {
                    line[j][u][v] = (line[j][u - 1][v - 1] + dp[j][u][v]) % mod;
                }
            }
            for (int u = 0; u <= x; u++) {
                for (int v = 0; v <= y; v++) {
                    if (v) down[j][u][v] = (down[j][u][v - 1] + line[j][u][v]) % mod;
                    if (u) up[j][u][v] = (up[j][u - 1][v] + line[j][u][v]) % mod;
                }
            }
        }
        for (int j = 0; j <= mx; j++) {
            for (int u = 0; u <= x; u++) {
                for (int v = 0; v <= y; v++) {
                    dp[j][u][v] = 0;
                    if (j >= 0) {
                        // += dp[i-1][j][s][t] where (u-s)<(v-t)
                        if (v) dp[j][u][v] += down[j][u][v - 1];
                        dp[j][u][v] %= mod;
                    }
                    if (j >= 1) {
                        // += dp[i-1][j-1][s][t] where (u-s)==(v-t)
                        dp[j][u][v] += line[j - 1][u][v];
                        dp[j][u][v] %= mod;
                    }
                    if (j >= 3) {
                        // += dp[i-1][j-3][s][t] where (u-s)>(v-t)
                        if (u) dp[j][u][v] += up[j - 3][u - 1][v];
                        dp[j][u][v] %= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = m; j <= mx; j++) {
        ans += dp[j][x][y];
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}
