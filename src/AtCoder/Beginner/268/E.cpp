/**
 * @author: XiaFan
 * @date: 09-12 20:49
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        pos[x] = i;
    }

    std::vector<i64> sk(n), sb(n);

    auto add = [&](int l, int r, int k, int b) {
        if (l > r) return;
        sk[l] += k;
        sb[l] += b;
        if (r + 1 < n) {
            sk[r + 1] -= k;
            sb[r + 1] -= b;
        }
    };

    auto fun = [&](int v) {
        if (v < n / 2) {
            add(0, v - 1, -1, v);
            add(v, v + n / 2, 1, -v);
            add(v + n / 2 + 1, n - 1, -1, n + v);
        } else {
            add(0, v - n / 2 - 1, 1, n - v);
            add(v - n / 2, v - 1, -1, v);
            add(v, n - 1, 1, -v);
        }
    };

    for (int i = 0; i < n; i++) {
        int v = (pos[i] - i + n) % n;
        fun(v);
    }
    for (int i = 1; i < n; i++) {
        sk[i] += sk[i - 1];
        sb[i] += sb[i - 1];
    }

    i64 ans = 1LL << 60;
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, sk[i] * i + sb[i]);
    }
    std::cout << ans << "\n";

    return 0;
}