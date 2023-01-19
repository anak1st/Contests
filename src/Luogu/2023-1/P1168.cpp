/**
 * @author: XiaFan
 * @date: 2023-01-17 13:16
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
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

void solve1() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::priority_queue<int, std::vector<int>, std::less<int>> q1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q2;
    for (int i = 0; i < n; i++) {
        if (q1.empty() || a[i] <= q1.top()) {
            q1.push(a[i]);
        } else {
            q2.push(a[i]);
        }
        if (q1.size() > q2.size() + 1) {
            q2.push(q1.top());
            q1.pop();
        } else if (q2.size() > q1.size()) {
            q1.push(q2.top());
            q2.pop();
        }
        if (i % 2 == 0) {
            std::cout << q1.top() << '\n';
        }
    }
}

void solve2() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    Fenwick<i64> f(n);
    auto b = a;
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    std::vector<int> c = a;
    for (int i = 0; i < n; i++) {
        c[i] = std::lower_bound(b.begin(), b.end(), c[i]) - b.begin();
    }
    for (int i = 0; i < n; i++) {
        f.add(c[i], 1);
        if (i % 2 == 0) {
            std::cout << b[f.kth(i / 2)] << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // solve1();
    solve2();

    return 0;
}