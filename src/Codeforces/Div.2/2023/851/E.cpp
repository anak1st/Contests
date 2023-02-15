/**
 * @author: XiaFan
 * @date: 2023-02-10 11:17
 **/
#include <bits/stdc++.h>
using i64 = long long;

// Fenwick Tree
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
        T ans = T{};
        for (int i = r + 1; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    /// @brief sum of [l, r]
    // T sum(int l, int r) {
    //     if (l == 0) {
    //         return sum(r);
    //     }
    //     return sum(r) - sum(l - 1);
    // }
    // int kth(T k) {
    //     int x = 0;
    //     for (int i = 1 << std::__lg(n); i; i /= 2) {
    //         if (x + i <= n && k >= a[x + i - 1]) {
    //             x += i;
    //             k -= a[x - 1];
    //         }
    //     }
    //     return x;
    // }
};

constexpr int inf = 1e9;

struct Max {
    i64 v;
    Max(i64 val = -inf) : v(val) {}
    Max &operator+=(const Max &rhs) {
        v = std::max(v, rhs.v);
        return *this;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> s(n + 1);
    std::partial_sum(a.begin(), a.end(), s.begin() + 1);
    auto v = s;
    std::sort(v.begin(), v.end());

    Fenwick<Max> fen(n + 1);
    std::vector<i64> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        int x = std::lower_bound(v.begin(), v.end(), s[i]) - v.begin();
        if (i == 0) {
            dp[i] = 0;
        } else {
            // find the largest dp[j] - j such that s[j] < s[i]
            dp[i] = std::max(dp[i - 1], i + fen.sum(x).v);
        }
        fen.add(x, dp[i] - i);
    }

    std::cout << dp[n];

    return 0;
}