/**
 * @author: XiaFan
 * @date: 11-26 19:51
 **/
#include <bits/stdc++.h>

// Fenwick Tree
template <typename T>
class Fenwick {
private:
    int n;
    std::vector<T> a;

    int lowbit(int x) { return x & -x; }

public:
    Fenwick(int size) : n(size), a(n) {}

    Fenwick(const std::vector<T> &v) : n(int(v.size())), a(n) {
        for (int i = 0; i < n; i++) {
            modify(i, v[i]);
        }
    }

    void modify(int pos, T val) {
        for (int i = pos + 1; i <= n; i += lowbit(i)) {
            a[i - 1] += val;
        }
    }

    T sum(int pos) {
        T val = 0;
        for (int i = pos + 1; i >= 1; i -= lowbit(i)) {
            val += a[i - 1];
        }
        return val;
    }

    T sum(int left, int right) {
        if (left > 0) {
            return sum(right) - sum(left - 1);
        } else {
            return sum(right);
        }
    }
};

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto& i : a) {
        std::cin >> i;
    }

    i64 max = a[0], cnt = 0;
    std::vector<i64> res(n);
    std::vector<bool> is_max(n);
    for (int i = 1; i < n; i++) {
        if (max == a[i]) cnt++;
        res[i] = res[i - 1] + (cnt == 0);
        if (a[i] > max) {
            std::swap(max , a[i]);
            is_max[i] = true;
            cnt = 0;
            res[i] = i;
        }
    }
    a[0] = 1;
    i64 ans = 0;
    std::vector<bool> vis(n + 10);
    Fenwick<i64> F(n + 10);
    for (int i = 0; i < n; i++) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            F.modify(a[i], 1);
        }
        ans += F.sum(a[i] + 1, n + 5) + is_max[i];
        std::cout << ans + res[i] << (i == n - 1 ? "\n" : " ");
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