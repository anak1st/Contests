/**
 * @author: XiaFan
 * @date: 09-26 20:50
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    auto check = [&](double time) -> double {
        double l = 0, r = 1e9;
        for (int i = 0; i < n; i++) {
            double t = time - b[i];
            if (t < 0) {
                return -1;
            }
            l = std::max(l, a[i] - t);
            r = std::min(r, a[i] + t);
        }
        if (l <= r) {
            return l;
        } else {
            return -1;
        }
    };

    double left = *std::max_element(b.begin(), b.end());
    double right = 1e9;
    double ans = left;

    while (right - left >= 1e-7) {
        double mid = (left + right) / 2;
        double res = check(mid);
        //std::cout << mid << " " << res << "\n";
        if (res != -1) {
            right = mid;
            ans = res;
        } else {
            left = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(7) << ans << "\n";
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