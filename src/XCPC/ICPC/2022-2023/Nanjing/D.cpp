/**
 * @author: XiaFan
 * @date: 2023-10-23 21:28
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, k, m, c, d;
    std::cin >> n >> k >> m >> c >> d;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto find = [&](i64 i, i64 x) -> i64 {
        // a[i] + (i - m) * d + c >= x
        i64 l = 0, r = i, ans = 0;
        while (l <= r) {
            i64 mid = (l + r) / 2;
            if (a[i] + (i - mid) * d + c >= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    };

    auto check = [&](i64 x) -> bool {
        std::vector<int> add(n);

        for (i64 i = 0; i < n; i++) {
            if (a[i] >= x) {
                add[0]++;
                // std::cerr << 0 << " " << "inf" << "\n";
                continue;
            }

            if (c + std::min(i, m - 1) * d + a[i] >= x) {
                add[std::max(0LL, i - m + 1)]++;
                // std::cerr << std::max(0LL, i - m + 1) << " ";
                auto j = find(i, x);
                // std::cerr << j + 1 << "\n";
                if (j + 1 < n)
                    add[j + 1]--;
            }
        }

        i64 sum = 0, max = 0;
        // std::cerr << x << ": ";
        for (int i = 0; i < n; i++) {
            sum += add[i];
            // std::cerr << sum << " \n"[i == n - 1];
            max = std::max(max, sum);
        }

        return max >= k;
    };

    i64 l = 0, r = 1e16, ans = 0;
    while (l <= r) {
        i64 mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}