/**
 * @author: XiaFan
 * @date: 2023-02-03 14:41
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::map<int, std::vector<int>> mp;

    auto push = [&](int x, int id) {
        int sq = sqrt(x);
        for (int i = 1; i <= sq; i++) {
            if (x % i == 0) {
                mp[i].push_back(id);
                if (x / i != i) {
                    mp[x / i].push_back(id);
                }
            }
        }
    };

    auto get = [&](int x) -> int {
        int y = a[x];
        // for (auto i : mp[y]) {
        //     std::cerr << i << " ";
        // }
        // std::cerr << "\n";
        int count = mp[y].end() - std::upper_bound(mp[y].begin(), mp[y].end(), x);
        return count;
    };

    for (int i = 1; i <= n; i++) {
        push(a[i], i);
    }

    while (q--) {
        int op, x;
        std::cin >> op >> x;
        if (op == 1) {
            push(x, a.size());
            a.push_back(x);
        } else {
            std::cout << get(x) << "\n";
        }
    }

    return 0;
}