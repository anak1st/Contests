// P1802 5 倍经验日 普及-
// 动态规划,dp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 1234;

struct Friend {
    int loss;
    int win;
    int use;
} f[maxN];
int dp[maxN][maxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> f[i].loss;
        cin >> f[i].win;
        cin >> f[i].use;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            if(j >= f[i].use) {
                int Win = dp[i - 1][j - f[i].use] + f[i].win;
                int Loss = dp[i - 1][j] + f[i].loss;
                dp[i][j] = max(Win, Loss);
            } else {
                dp[i][j] = dp[i - 1][j] + f[i].loss;
            }
        }
    }
    cout << (i64)dp[n][x] * 5 << '\n';
    return 0;
}