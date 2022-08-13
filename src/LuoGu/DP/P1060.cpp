// P1060 开心的金明 普及-
// 动态规划,dp 背包
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 5 * 30000 + 123;
int dp[30][maxN];
struct Good {
    int v;  // value
    int p;  // price
} g[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> g[i].v >> g[i].p;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(j > g[i].v) {
                int add = dp[i - 1][j - g[i].v] + g[i].p * g[i].v;
                dp[i][j] = max(dp[i - 1][j], add);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n] << '\n';
    return 0;
}