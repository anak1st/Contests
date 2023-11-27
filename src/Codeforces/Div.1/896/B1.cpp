/**
 * @author: XiaFan
 * @date: 2023-09-10 23:43
 */
#include <bits/stdc++.h>

using i64 = long long;

const int BIT = 32;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
    if (sum % n != 0) {
        std::cout << "No\n";
        return;
    }

    i64 avg = sum / n;
    std::map<i64, int> cnt;
    for (int i = 0; i < n; i++) {
        i64 dif = std::abs(a[i] - avg);
        
        if (dif == 0) continue;

        i64 x = 0, y;
        while (!(dif & 1)) {
            dif >>= 1;
            x++;
        }
        y = x;
        while (dif & 1) {
            dif >>= 1;
            y++;
        }

        if (dif) {
            std::cout << "No\n";
            return;
        }

        cnt[x] += a[i] > avg ? 1 : -1;
        cnt[y] -= a[i] > avg ? 1 : -1;
    }

    // if (cnt_same == 1 && !(cnt[1][0] || cnt[1][0])) {
    //     std::cout << "Yes\n";
    //     return;
    // }

    for (auto [k, v] : cnt) {
        if (v != 0) {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}