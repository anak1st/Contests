/**
 * @author: XiaFan
 * @date: 2023-01-13 13:22
 **/
#include <bits/stdc++.h>
using i64 = long long;
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
    for (auto c : s) {
        x = 10 * x + (c - '0');
    }
    if (flag) {
        x = -x;
    }
    return is;
}
std::ostream &operator<<(std::ostream &os, i128 x) {
    if (x == 0) {
        os << '0';
    } else {
        if (x < 0) {
            os << '-';
            x = -x;
        }
        std::string s;
        for (; x; x /= 10) {
            s.push_back('0' + x % 10);
        }
        std::reverse(s.begin(), s.end());
        os << s;
    }
    return os;
}
i128 i128_gcd(i128 a, i128 b) {
    if (b == 0) {
        return a;
    } else {
        return i128_gcd(b, a % b);
    }
}

template <typename T> struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int size) : n(size), a(n) {}
    Fenwick(std::vector<T> &v) : n(v.size()), a(n) {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    /// @brief sum of [0, r]
    T sum(int r) {
        if (r < 0) {
            return 0;
        }
        T ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    /// @brief sum of [l, r]
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> b(n);
    std::iota(b.begin(), b.end(), 0);
    std::stable_sort(b.begin(), b.end(), [&](int i, int j) -> bool {
        return a[i] < a[j];
    });
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[b[i]] = i;
    }

    i128 ans = 0;
    Fenwick<i64> fen(n);
    for (int i = n - 1; i >= 0; i--) {
        int j = c[i];
        ans += i128(1) * fen.sum(j) * (i + 1);
        fen.add(j, n - i);
    }
    std::cout << ans;

    return 0;
}