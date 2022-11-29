/**
 * @author: XiaFan
 * @date: 11-24 18:38
 **/
#include <bits/stdc++.h>
#include <bits/extc++.h>

using i64 = long long;

int hash(std::array<int, 2> p) {
    auto [x, y] = p;
    return x * 19 + y + 60;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::array<int, 2>> a(19);
    // clang-format off
                                      a[ 0] = { 2, 0}; a[ 1] = { 2, 1}; a[ 2] = { 2, 2};
                     a[ 3] = { 1,-1}; a[ 4] = { 1, 0}; a[ 5] = { 1, 1}; a[ 6] = { 1, 2};
    a[ 7] = { 0,-2}; a[ 8] = { 0,-1}; a[ 9] = { 0, 0}; a[10] = { 0, 1}; a[11] = { 0, 2};
    a[12] = {-1,-2}; a[13] = {-1,-1}; a[14] = {-1, 0}; a[15] = {-1, 1};
    a[16] = {-2,-2}; a[17] = {-2,-1}; a[18] = {-2, 0};

    std::vector<std::array<int, 2>> d = {
                 { 1, 0}, { 1, 1},
        { 0,-1},          { 0, 1},
        {-1,-1}, {-1, 0}
    };
    // clang-format on

    std::vector<int> b(19);
    for (int i = 0; i < 19; i++) std::cin >> b[i];
    std::vector<int> f(1 << 19, -1);
    f[0] = 0;
    std::vector<int> idx(1000, -1);
    for(int i=0; i<19; i++)
        idx[hash(a[i])]=i;

    auto id = [&](std::array<int, 2> pos) -> int {
        size_t i = std::find(a.begin(), a.end(), pos) - a.begin();
        if (i >= a.size()) i = -1;
        return i;
    };

    std::function<int(int)> dfs = [&](int x) -> int {
        if (f[x] != -1) return f[x];

        int res = 0;
        for (int i = 0; i < 19; i++) {
            if (x & (1 << i)) res = std::max(res, dfs(x - (1 << i)));
        }
        for (int i = 0; i < 19; i++) {
            if (!(x & (1 << i))) {
                continue;
            }
            for (auto [dx, dy] : d) {
                // int adj = id({a[i][0] + dx, a[i][1] + dy});
                // int jmp = id({a[i][0] + 2 * dx, a[i][1] + 2 * dy});
                int adj = idx[hash({a[i][0] + dx, a[i][1] + dy})];
                int jmp = idx[hash({a[i][0] + 2 * dx, a[i][1] + 2 * dy})];

                if (adj == -1 || jmp == -1 || !(x & (1 << adj)) || (x & (1 << jmp)))
                    continue;
                
                res = std::max(res, b[adj] + dfs(x - (1 << adj) - (1 << i) + (1 << jmp)));
                // print(res, i, adj, b[adj]);
            }
        }
        f[x] = res;
        return f[x];
    };

    int tt;
    std::cin >> tt;

    while (tt--) {
        std::string s;
        for (int i = 0; i < 5; i++) {
            std::string t;
            std::cin >> t;
            s += t;
        }
        int x = 0;
        for (int i = 18; i >= 0; i--) {
            x = (x << 1) + (s[i] == '#');
        }
        std::cout << dfs(x) << "\n";
    }

    return 0;
}