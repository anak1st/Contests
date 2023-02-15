/**
 * @author: XiaFan
 * @date: 2023-02-15 20:39
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 1e5;
constexpr int inf = 1e9;

std::vector<int> divs[N + 1];

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    std::vector<int> cnt(m + 1);
    int bad = m, ans = inf;
    for (int i = 0, j = 0; i < n; i++) {
        while (j <= n && bad > 0) {
            if (j < n) {
                for (auto x : divs[a[j]]) {
                    if (x <= m) {
                        bad -= !cnt[x];
                        cnt[x]++;
                    }
                }
            }
            j++;
        }
        if (j <= n) {
            ans = std::min(ans, a[j - 1] - a[i]);
        }
        for (auto x : divs[a[i]]) {
            if (x <= m) {
                cnt[x]--;
                bad += !cnt[x];
            }
        }
    }
    
    if (ans == inf) ans = -1;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}