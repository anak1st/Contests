// P1757 通天之分组背包 普及-
// 动态规划,dp 背包
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int maxN = 1234;
struct Good {
    int w;  // weight
    int v;  // value
    Good() {}
    Good(int _w, int _v) {
        w = _w;
        v = _v;
    }
};

int dp[maxN][maxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Good> g[maxN];
    for(int i = 1; i <= m; i++) {
        int tw, tv, t;
        cin >> tw >> tv >> t;
        g[t].push_back(Good(tw, tv));
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            bool flag = true;
            for(int k = 0; k < (int)g[i].size(); k++) {
                if(j >= g[i][k].w) {
                    int next = dp[i - 1][j - g[i][k].w] + g[i][k].v;
                    dp[i][j] = max(dp[i][j], max(dp[i - 1][j], next));
                    flag = false;
                }
            }
            if(flag) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}