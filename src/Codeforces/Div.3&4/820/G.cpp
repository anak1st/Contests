/**
 * @author: XiaFan
 * @date: 09-22 19:13
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int mod = 1e9 + 7;
constexpr int inf = 1e9;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    int lens = s.length();
    int m = t.length();
    std::vector<int> a;
    a.push_back(-inf);
    for (int i = 0; i + m <= lens; i++) {
        if (s.substr(i, m) == t) {
            a.push_back(i + m - 1);
        }
    }

    int n = a.size();
    if (n == 0) {
        std::cout << 0 << " " << 1 << "\n";
        return;
    }

    std::vector<int> len(n, inf), cnt(n, 0);
    len[0] = 0;
    cnt[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] - a[j] < m) {
                continue;
            }
            bool ok = true;
            for (int k = j + 1; k < i; k++) {
                if (a[k] - a[j] >= m && a[i] - a[k] >= m) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }

            if (len[i] > len[j] + 1) {
                len[i] = len[j] + 1;
                cnt[i] = cnt[j];
            } else if (len[i] == len[j] + 1) {
                cnt[i] += cnt[j];
                cnt[i] %= mod;
            }
        }
    }

    int minlen = inf, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a.back() - a[i] < m) {
            minlen = std::min(minlen, len[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a.back() - a[i] < m && len[i] == minlen) {
            ans += cnt[i];
            ans %= mod;
        }
    }
    std::cout << minlen << " " << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}