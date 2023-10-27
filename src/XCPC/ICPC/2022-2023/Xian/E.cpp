/**
 * @author: XiaFan
 * @date: 2023-10-19 12:31
 */
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}

std::vector<int> to3(i64 x) {
    std::vector<int> res;
    while (x) {
        res.push_back(x % 3);
        x /= 3;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    
    auto R = to3(r);

    int n = R.size();
    i64 ans = 0;
    i64 sum = 0;
    i64 num = 0;
    i64 base = power(3LL, n - 1);
    for (int i = 0; i < n; ++i) {
        // std::cerr << base << " " << num + R[i] * base - 1 << "\n";
        if (R[i] > 0 && num + R[i] * base - 1 >= l) {
            if (R[i] == 1 && sum == 0) {
                ans = std::max(ans, (n - i - 1) * 3LL);
            } else {
                ans = std::max(ans, sum + R[i] + (n - i - 1) * 3LL);
            }
        }

        sum += R[i] + 1;
        num += R[i] * base;

        base /= 3;
    }
    ans = std::max(ans, sum);
    std::cout << ans << "\n";
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