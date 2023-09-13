/**
 * @author: XiaFan
 * @date: 2023-09-11 23:12
 */
#include <bits/stdc++.h>

using i64 = long long;



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 14;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = 1LL << i;
    }

    int k = 8;
    auto op = [&](int i) -> int {
        int xsum = 0;
        for (int j = i; j < i + k; j++) {
            xsum ^= a[j];
        }
        std::reverse(a.begin() + i, a.begin() + i + k);
        return xsum;
    };

    auto print = [&](int x) {
        for (int i = 0; i < n; i++) {
            std::cout << (x >> i & 1) << " ";
        }
        std::cout << "\n";
    };
    
    std::vector<int> steep;
    auto dfs = [&](auto && dfs, int i, int xsum) -> void {
        if (i == 3) {
            if (__builtin_popcount(xsum) > n - 2) {
                print(xsum);
                for (int j : steep) {
                    std::cout << j << " ";
                }
                std::cout << "\n";
            }
            return;
        }

        for (int j = 0; j + k <= n; j++) {
            int z = op(j);
            steep.push_back(j);
            dfs(dfs, i + 1, xsum ^ z);
            steep.pop_back();
            op(j);
        }
    };

    dfs(dfs, 0, 0);

    return 0;
}