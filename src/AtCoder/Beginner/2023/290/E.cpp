/**
 * @author: XiaFan
 * @date: 2023-02-23 19:49
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        b[a[i]].push_back(i);
    }

    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1LL * i * (n - i + 1);
        sum -= std::min(i, n - i + 1);
    }
    sum /= 2;

    for (const auto &v : b) {
        if (v.empty()) continue;
        int s = v.size();
        int l = 0, r = s - 1;
        while (l < r) {
            if (v[l] > n - v[r] + 1) {
                sum -= 1LL * (n - v[r] + 1) * (r - l);
                r--;
            } else {
                sum -= 1LL * v[l] * (r - l);
                l++;
            }
        }
    }
    std::cout << sum;

    return 0;
}