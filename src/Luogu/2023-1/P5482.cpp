/**
 * @author: XiaFan
 * @date: 2023-01-15 00:40
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
    // sum of [0, r]
    T sum(int r) {
        T ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    // sum of [l, r]
    T sum_range(int l, int r) {
        if (l == 0) {
            return sum(r);
        } else {
            return sum(r) - sum(l - 1);
        }
    }
};

constexpr int N = 1e6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Fenwick<int> fen1(2 * N + 1), fen2(2 * N + 1);
    int all = 0;

    std::vector<std::array<int, 6>> v;
    while (n--) {
        std::string op;
        std::cin >> op;
        if (op == "Add") {
            // ax + b > c
            v.push_back({});
            auto &[a, b, c, k, d, g] = v.back();
            std::cin >> a >> b >> c;
            d = 0, g = 0;
            if (a > 0) {
                // x > (c - b) / a
                k = std::floor(1.0 * (c - b) / a);
                if (k < -N) {
                    g = 1;
                    all++;
                } else if (k > N) {
                    d = 1;
                } else {
                    fen1.add(N + k, 1);
                }
            } else if (a < 0) {
                // x < (c - b) / a
                k = std::ceil(1.0 * (c - b) / a);
                if (k < -N) {
                    d = 1;
                } else if (k > N) {
                    g = 1;
                    all++;
                } else {
                    fen2.add(N + k, 1);
                }
            } else {
                if (b > c) {
                    all++;
                    g = 1;
                } else {
                    d = 1;
                }
            }
        } else if (op == "Del") {
            int i;
            std::cin >> i;
            i--;
            auto &[a, b, c, k, d, g] = v[i];
            if (d) continue;
            d = 1;
            if (g) {
                all--;
            } else if (a > 0) {
                // x > (c - b) / a
                fen1.add(N + k, -1);
            } else if (a < 0) {
                // x < (c - b) / a
                fen2.add(N + k, -1);
            }
        } else {
            int x;
            std::cin >> x;
            int ans = all + fen1.sum(N + x - 1) + fen2.sum_range(N + x + 1, 2 * N);
            std::cout << ans << "\n";
        }
    }

    return 0;
}