/**
 * @author: XiaFan
 * @date: 2023-01-09 21:39
 **/
#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
std::istream &operator>>(std::istream &is, i128 &x) {
    std::string s;
    is >> s;
    bool flag = false;
    if (s.front() == '-') {
        s = s.substr(1);
        flag = true;
    }
    x = 0;
    for (auto c : s) x = 10 * x + (c - '0');
    if (flag) x = -x;
    return is;
}
std::ostream &operator<<(std::ostream &os, i128 x) {
    if (x == 0) {
        os << '0';
    } else {
        if (x < 0) os << '-', x = -x;
        std::string s;
        for (; x; x /= 10) s.push_back('0' + x % 10);
        std::reverse(s.begin(), s.end());
        os << s;
    }
    return os;
}
i128 i128_gcd(i128 a, i128 b) {
    if (b == 0) return a;
    return i128_gcd(b, a % b);
}

template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

void solve() {
    i64 n;
    std::cin >> n;
    if ((n & -n) == n) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<std::vector<i64>> ans;
    ans.push_back({n});
    for (int i = 2; i <= 64; i++) {
        i64 x = std::pow(n, 1.0 / i);
        if (power((i128)x, i) > n) break;
        while (power((i128)x + 1, i) < n) x++;
        if (x == 1) {
            break;
        }
        i64 t = power(x, i);
        int j = 0;
        while (t < n && (j + 1) <= i) {
            t /= x;
            t *= x + 1;
            j++;
        }
        if (t != n) continue;
        std::vector<i64> tmp;
        for (int k = 0; k < i - j; k++) tmp.push_back(x);
        for (int k = 0; k < j; k++) tmp.push_back(x + 1);
        ans.push_back(tmp);
    }
    std::cout << ans.size() << "\n";
    for (auto v : ans) {
        std::cout << v.size() << " ";
        for (auto it : v) {
            std::cout << it << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    freopen("little.in", "r", stdin);
    freopen("little.out", "w", stdout);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
