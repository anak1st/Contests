/**
 * @author: XiaFan
 * @date: 11-14 22:03
 **/
#include <bits/stdc++.h>

using i64 = long long;

template<typename T> 
void print(const T& val) {
    std::cerr << val << "\n";
}

template<typename T, typename... Args> 
void print(const T& val, const Args&... args) {
    std::cerr << val << " ";
    print(args...);
}

template <typename T> 
class fenwick {
private:
    int n;
    std::vector<T> a;

    int lowbit(int x) {
        return x & -x;
    }

public:
    fenwick(int size) 
    : n(size), a(n) 
    {}

    fenwick(const std::vector<T> &v) 
    : n(int(v.size())), a(n) 
    {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::pair<i64, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a.begin(), a.end());

    std::vector<i64> ans(n);
    fenwick<i64> fw1(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        auto [x, id] = a[i];
        int cnt = fw1.sum(id);
        ans[id] += cnt * (x + 1);
        ans[id] += (i - cnt) * x - sum;
        sum += x;
        fw1.modify(id, 1);
        print("x:", x, "id:", id, "cnt:", cnt, "sum:", sum);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] > m - 2) {
            ans[i] = -1;
        }
        std::cout << ans[i] << "\n";
    }

    return 0;
}