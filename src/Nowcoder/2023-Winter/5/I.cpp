/**
 * @author: XiaFan
 * @date: 2023-02-01 14:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<i64> f;
    f.push_back(0);
    f.push_back(1);
    while (f.back() < 1e15) {
        f.push_back(f.back() * 2);
    }
    i64 n, m;
    std::cin >> n >> m;
    if (n >= f.size() || m < f[n]) {
        std::cout << -1;
        return 0;
    }

    std::vector<i64> a(n);
    i64 cnt = 0;
    for (int i = 0; i < n; i++) {
        a[i] = (m - cnt) / f[n - i];
        cnt += a[i] * f[n - i];
    }

    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        i64 num = sum + a[i];
        std::cout << num << ' ';
        sum += num;
    }

    return 0;
}