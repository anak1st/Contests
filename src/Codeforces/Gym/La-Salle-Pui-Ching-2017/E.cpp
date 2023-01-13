/**
 * @author: XiaFan
 * @date: 2023-01-11 20:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, r;
    std::cin >> n >> r;
    std::vector<int> a(2 * n);
    int pre = 0;
    for (int i = 0; i < r - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        std::cin >> a[x] >> a[y];
        if (a[x] == a[y]) {
            pre = std::max(pre, a[x]);
        }
    }

    std::vector<int> cnt(n + 1);
    for (int i = 0; i < 2 * n; i++) {
        cnt[a[i]]++;
    }
    int close = cnt[0];
    if (close == 0) {
        std::cout << n;
        return 0;
    }
    double ans = pre;
    // strategy 1
    for (int i = n; i >= pre + 1; i--) {
        if (cnt[i] == 2) {
            ans = i;
            break;
        }
    }
    // strategy 2
    for (int i = n; i >= pre + 1; i--) {
        if (cnt[i] == 1) {
            double p = 1.0 / close;
            ans = std::max(ans, i * p + (1 - p) * pre);
            break;
        }
    }
    // strategy 3
    double sum = 0, sump, p = 2.0 / close / (close - 1);
    for (int i = pre + 1; i <= n; i++) {
        if (cnt[i] != 0) continue;
        sum += i * p;
        sump += p;
    }
    sum += (1 - sump) * pre;
    ans = std::max(ans, sum);

    std::cout << std::fixed << std::setprecision(10) << ans;

    return 0;
}