/**
 * @author: XiaFan
 * @date: 10-04 20:10
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        std::cin >> a[i];
    }

    auto judge = [&](int h) -> int {
        std::vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        std::queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                q.push(i);
            }
        }
        int res = 0;
        std::vector<int> b(n + 1, 1);
        while (q.front() != 1) {
            int v = q.front();
            q.pop();
            int f = a[v];
            cnt[f]--;
            if (b[v] >= h && f != 1) {
                res++;
                b[v] = -1;
            }
            b[f] = std::max(b[f], b[v] + 1);
            if (cnt[f] == 0) {
                q.push(f);
            }
        }
        return res;
    };

    int left = 1, right = n, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        //std::cout << "ddd " << mid << " " << judge(mid) << "\n";
        if (judge(mid) <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    std::cout << ans << "\n";
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