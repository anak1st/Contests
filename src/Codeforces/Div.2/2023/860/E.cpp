#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> step(n + 1, -1), suf(n + 1), f(n + 1);
    step[n] = 0;
    std::vector<int> ans(n);
    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1;
        int k = j + a[j] + 1;

        if (k <= n && step[k] != -1) {
            step[j] = step[k] + 1;
        }

        suf[j] = std::max(suf[j + 1], step[j + 1]);

        f[j] = suf[j] + 1;
        if (k <= n) {
            f[j] = std::max(f[j], f[k] + 1);
        }

        if (step[j] == a[i]) {
            ans[i] = 0;
        } else if (step[j] != -1 || f[j] >= a[i]) {
            ans[i] = 1;
        } else {
            ans[i] = 2;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        std::cout << ans[i] << " \n"[i == n - 2];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}