// P1359 租用游艇 普及-
// 动态规划,dp 图论 邻接表 最短路
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 1e3 + 1;
// const int inf = 1e9;
int river[maxN][maxN];
int dp[maxN];  // 1 -> i

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 1; i <= N - 1; i++) {
        for(int j = i + 1; j <= N; j++) {
            cin >> river[i][j];  // ):
        }
    }
    for(int i = 2; i <= N; i++) {
        dp[i] = river[1][i];
    }
    for(int i = 3; i <= N; i++) {
        // a = 1, b = j, c = i
        for(int j = 2; j <= i; j++) {
            int dis = dp[j] + river[j][i];
            dp[i] = min(dp[i], dis);
        }
    }
    cout << dp[N] << endl;
    return 0;
}