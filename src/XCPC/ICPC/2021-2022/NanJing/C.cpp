/**
 * @author: XiaFan
 * @date: 11-26 15:45
 **/
#include <bits/stdc++.h>

using i64 = long long;

const int N = 4e6 + 10;
int n, k;
int cnt[N], add[N], a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;

    int maxcnt = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += 2000000;
        cnt[a[i]]++;
        maxcnt = std::max(maxcnt, cnt[a[i]]);
    }

    if (k == 0)
        std::cout << maxcnt << '\n';
    else {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            add[a[i]] = std::max(0, add[a[i]] - 1);
            add[a[i] + k]++;
            ans = std::max(ans, add[a[i] + k] + cnt[a[i] + k]);
        }
        std::cout << ans << '\n';
    }
}