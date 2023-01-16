/**
 * @author: XiaFan
 * @date: 2023-01-15 11:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

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

constexpr int N = 1e5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 ans = 0;
    Fenwick<i64> fen1(N + 1), fen2(N + 1);
    for (int i = 0; i < n; i++) {
        int j = a[i];
        fen1.add(j, 1);
        fen2.add(j, fen1.sum(j - 1));
        ans += fen2.sum(j - 1);
    }
    std::cout << ans;

    return 0;
}