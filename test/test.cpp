/**
 * @author: XiaFan
 * @date: 2024-03-12 20:26
 */
#include <bits/stdc++.h>

using i64 = long long;

namespace std {
template<typename... _Args>
void print(std::format_string<_Args...> __fmt, _Args&&... __args) {
    std::cout << std::vformat(__fmt.get(), std::make_format_args(__args...));
}
template<typename... _Args>
void println(std::format_string<_Args...> __fmt, _Args&&... __args) {
    std::cout << std::vformat(__fmt.get(), std::make_format_args(__args...)) << "\n";
}
} // namespace std

void solve() {
    int n, limit;
    std::cin >> n >> limit;
    std::vector<std::pair<int, int>> a(n);
    for (auto& [x, y] : a) {
        std::cin >> x >> y;
    }
    std::ranges::sort(a, 
                      [](auto& x, auto& y) { return x.second < y.second; });

    std::vector<int> order_of_first(n);
    std::iota(order_of_first.begin(), order_of_first.end(), 0);
    std::ranges::sort(order_of_first, 
                      [&](auto& x, auto& y) { return a[x].first < a[y].first; });

    for (int i = 0; i < n; i++) {
        std::println("a[{}]: ({}, {})", i, a[i].first, a[i].second);
    }

    std::vector<i64> prefix_sum_secound(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum_secound[i + 1] = a[i].second;
    }

    auto check_len = [&](int len) -> bool {
        i64 sum_first = 0;
        std::set<int> pos;
        for (int i = 0; i < len; i++) {
            sum_first += a[order_of_first[i]].first;
            pos.insert(order_of_first[i]);
        }
        for (int i = len; i <= n; i++) {
            auto min_pos = *pos.begin();
            auto max_pos = *pos.rbegin();
            i64 sum_secound = prefix_sum_secound[max_pos + 1] - prefix_sum_secound[min_pos];
            std::println("sum_first: {}, sum_secound: {}", sum_first, sum_secound);
            for (auto x : pos) {
                std::print("{} ", x);
            }
            std::println("");
            if (sum_first + sum_secound <= limit) {
                return true;
            }
            if (i == n) {
                break;
            }
            
            sum_first -= a[order_of_first[i - len]].first;
            pos.erase(order_of_first[i - len]);
            sum_first += a[order_of_first[i]].first;
            pos.insert(order_of_first[i]);
        }

        return false;
    };


    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check_len(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    std::println("{}", ans);
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}