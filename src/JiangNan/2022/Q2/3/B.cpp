/**
 * @author: XiaFan
 * @date: 06-30 20:51
 **/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;
const int inf = 1e9;
const int maxn = 1010;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v, x;
    while (cin >> n >> v >> x) {
        vector<pair<int, int>> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end());
        
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i].second;
        }

        vector<vector<vector<int>>> 
            dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, inf)));

        int all = sum[n];
        for (int i = 1; i <= n; i++) {
            dp[i][i][0] = abs(a[i].first - x) * all;
            dp[i][i][1] = abs(a[i].first - x) * all;
        }

        for (int d = 1; d < n; d++) {
            for (int i = 1; i <= n - d; i++) {
                int j = i + d;
// dp[i][j][0]表示最后一次送外卖是在左端点 dp[i][j][1]表示在右端点
dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + abs(a[i + 1].first - a[i].first) * (all - (sum[j] - sum[i])));
dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + abs(a[j].first - a[i].first)     * (all - (sum[j] - sum[i])));
dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + abs(a[j].first - a[i].first)     * (all - (sum[j - 1] - sum[i - 1])));
dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + abs(a[j].first - a[j - 1].first) * (all - (sum[j - 1] - sum[i - 1])));
            }
        }

        cout << min(dp[1][n][0], dp[1][n][1]) * v << "\n";
    }

    return 0;
}