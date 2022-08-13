/**
 * @author: XiaFan
 * @date: 06-30 16:57
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int white, black;
    cin >> white >> black;
    double win = 0;
    vector dp(white + 1, vector<double>(black + 1));
    dp[white][black] = 1;
    for (int i = white; i >= 1; i--) {
        for (int j = black; j >= 1; j--) {
            // princess
            double w = i, b = j;
            double temp = dp[i][j] * w / (w + b);
            double next = dp[i][j] * b / (w + b);
            win += temp;
            b--; 

            // dragon
            next *= b / (w + b);
            b--;
            if (j >= 2) {
                dp[w - 1][b] += next * w / (w + b);
            }
            if (j >= 3) {
                dp[w][b - 1] += next * b / (w + b);
            }
        }
        if (i > 0) {
            win += dp[i][0];
        }
    }
    cout << fixed << setprecision(10) << win;

    return 0;
}