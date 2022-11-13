/**
 * @author: XiaFan
 * @date: 05-09 00:13
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct seg {
    int x, y;
    seg(int _x, int _y) : x(_x), y(_y) {}
    friend bool operator<(const seg& a, const seg& b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    friend seg operator+(const seg& a, const seg& b) {
        return seg(a.x + b.x, a.y + b.y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector dp(n / 2, vector<seg>(2, seg(0, 0)));
        function<int(int, int)> cost = [&](int p, int c) -> int {
            int res = 0;
            if (s[2 * p] != '0' + c) {
                res++;
            }
            if (s[2 * p + 1] != '0' + c) {
                res++;
            }
            return res;
        };
        dp[0][0] = seg(cost(0, 0), 1);
        dp[0][1] = seg(cost(0, 1), 1);
        for (int i = 1; i < n / 2; i++) {
            dp[i][0] = min(dp[i - 1][0] + seg(cost(i, 0), 0), dp[i - 1][1] + seg(cost(i, 0), 1));
            dp[i][1] = min(dp[i - 1][1] + seg(cost(i, 1), 0), dp[i - 1][0] + seg(cost(i, 1), 1));
        }
        seg ans = min(dp[n / 2 - 1][0], dp[n / 2 - 1][1]);
        cout << ans.x << " " << ans.y << "\n";
    }

    return 0;
}