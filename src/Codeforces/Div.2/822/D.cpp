/**
 * @author: XiaFan
 * @date: 09-23 21:40
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    k--;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    bool ok = false;

    auto game = [&](void) {
        i64 h = 0;
        i64 maxh = -1;
        for (int i = k, j = k - 1; i <= n; i++) {
            if (i == n) {
                ok = true;
                break;
            }
            h += a[i];
            if (h < 0) {
                return;
            }

            if (maxh < h) {
                maxh = h;
                i64 th = h;
                int tj = j;
                    while (tj >= 0 && th >= 0) {
                        th += a[tj];
                        tj--;
                        if (th > h) {
                            h = th;
                            j = tj;
                        }
                        if (tj < 0) {
                            j = -1;
                        }
                    }
            }

            if (h < 0) {
                return;
            }
        }
    };

    game();
    std::reverse(a.begin(), a.end());
    k = n - 1 - k;
    game();

    if (ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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