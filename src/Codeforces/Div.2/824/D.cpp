/**
 * @author: XiaFan
 * @date: 10-10 19:54
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    
    std::vector a(n, std::vector<int>(k));
    for (auto &i : a) {
        for (auto &j : i) {
            std::cin >> j;
        }
    }

    std::map<std::vector<int>, int> mp;

    auto fun = [&](const std::vector<int> &a, 
                   const std::vector<int> &b) -> std::vector<int>
    {
        std::vector<int> res(k);
        for (int i = 0; i < k; i++) {
            if (a[i] == b[i]) {
                res[i] = a[i];
            } else {
                res[i] = 3 - a[i] - b[i];
            }
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mp[fun(a[i], a[j])]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = mp[a[i]];
        if (x > 1) {
            ans += x * (x - 1) / 2;
        }
    }
    std::cout << ans;
    
    return 0;
}