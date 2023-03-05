/**
 * @author: XiaFan
 * @date: 2023-03-04 23:19
 **/
#include <bits/stdc++.h>
using i64 = long long;

// 0-1 knapsack problem
// a[i] = (w, v) means that we can choose one item with weight w and value v
int KP(int t, const std::vector<std::pair<int, int>> &a) {
    int n = a.size();
    std::vector<int> f(t + 1);
    for (auto [w, v] : a) {
        for (int i = t; i >= w; i--) {
            f[i] = std::max(f[i], f[i - w] + v);
        }
    }
    return f[t];
}

// bounded knapsack problem
// a[i] = (k, w) means that we can choose k items with weight w
int BKP(int t, const std::vector<std::tuple<int, int, int>> &a) {
    int n = a.size();
    std::vector<int> f(t + 1);
    f[0] = 1;
    std::vector<std::pair<int, int>> b;
    for (auto [k, w, v] : a) {
        int x = 0;
        while (k) {
            int y = std::min(k, 1 << x);
            b.emplace_back(y * w, y * v);
            k -= y;
            x++;
        }
    }
    return KP(t, b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;
    std::vector<std::tuple<int, int, int>> a(n);
    for (auto &[k, w, v] : a) {
        std::cin >> v >> w >> k;
    }
    std::cout << BKP(t, a);

    return 0;
}