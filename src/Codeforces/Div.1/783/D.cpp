/**
 * @author: XiaFan
 * @date: 04-23 10:41
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int inf = 10000000;

struct fenwick {
    int n;
    std::vector<i64> fen;
    fenwick(int size) : n(size), fen(size + 1, -inf) {}
    int lowbit(int x) {
        return x & -x;
    }
    void add(int pos, i64 val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            fen[i] = max(fen[i], val);
        }
    }
    i64 ask(int pos) {
        i64 val = -inf;
        for (int i = pos; i >= 1; i -= lowbit(i)) {
            val = max(val, fen[i]);
        }
        return val;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1), pref(n + 1);
    vector<int> ord(n + 1);
    vector<pair<i64, int>> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        v.push_back({pref[i], -i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        ord[-v[i].second] = i + 1;
    }
    /**
     * smaller prefix sum, smaller ord[i]
     * if j<i they have equal prefix sums, than ord[i]<ord[j],
     * this way we cannot count [j+1, ... i] as a winning segment
     */
    vector<i64> dp(n + 1);
    fenwick f(n);
    for (int i = 1; i <= n; i++) {
        i64 judge = 0;
        if (a[i] != 0) {
            judge = a[i] / abs(a[i]);
        }
        dp[i] = dp[i - 1] + judge;  // The last segment is 1 long.
        dp[i] = max(dp[i], f.ask(ord[i]) + i);
        if (pref[i] > 0) {
            dp[i] = i;  // Segment [1, ... i] is winning, so dp[i]=i;
        }
        f.add(ord[i], dp[i] - i);
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}