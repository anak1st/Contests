#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for(int i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;
        for(int j = 0; j < m; j++) {
            v[i][j] = input[j] - '0';
        }
    }

    if(v[0][0]) {
        std::cout << "-1\n";
        return;
    }

    std::vector<std::array<int, 4>> ans;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(!v[i][j]) {
                continue;
            }
            if(j > 0) {
                //     j-1 j
                // i   0   1
                ans.push_back({i, j - 1, i, j});
            } else {
                //     j
                // i-1 0
                // i   1
                ans.push_back({i - 1, j, i, j});
            }
        }
    }

    std::cout << ans.size() << '\n';
    for(auto [x1, y1, x2, y2] : ans) {
        std::cout << x1 + 1 << ' ' << y1 + 1 << ' ';
        std::cout << x2 + 1 << ' ' << y2 + 1 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}