#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> sum(n + 1);
    std::vector<i64> xsum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        xsum[i] = xsum[i - 1] ^ a[i];
    }

    auto fun = [&](int l, int r) -> i64 {
        // assert(1 <= l && l <= n && 1 <= r && r <= n);
        return sum[r] - sum[l - 1] - (xsum[r] ^ xsum[l - 1]);
    };

    while (q--) {
        int L, R;
        std::cin >> L >> R;
        i64 sum = fun(L, R);
        std::array<int, 3> ans{R - L + 1, L, R};
        for (int i = L; i <= R; i++) {
            int l = i, r = R, tmp = R;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (fun(i, mid) == sum) {
                    r = mid - 1;
                    tmp = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (fun(i, tmp) == sum && tmp - i + 1 < ans[0]) {
                ans = {tmp - i + 1, i, tmp};
            }
        }
        std::cout << ans[1] << ' ' << ans[2] << '\n';
    }
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
