/**
 * @author: XiaFan
 * @date: 11-16 22:12
 **/
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    for (auto it : v) {
        os << it << " ";
    }
    return os;
}

template <typename T>
void print(const T& val) {
    std::cerr << val << "\n";
}

template <typename T, typename... Args>
void print(const T& val, const Args&... args) {
    std::cerr << val << " ";
    print(args...);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<std::vector<int>>> adj(
        2, std::vector<std::vector<int>>(n));
    for (int i = 0; i < m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--, y--;
        adj[z][x].push_back(y);
        adj[z][y].push_back(x);
    }
    std::vector<bool> s(n, false);
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        x--;
        s[x] = true;
    }

    std::vector<std::vector<int>> d(2, std::vector<int>(n, -1));
    d[1][0] = 0;
    std::queue<std::pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        auto [x, z] = q.front();
        q.pop();
        // print("from", x + 1, z);
        int td = d[z][x];
        for (auto y : adj[z][x]) {
            if (d[z][y] == -1) {
                d[z][y] = td + 1;
                q.push({y, z});
                // print("to", y + 1, d[z][y]);
            }
        }
        if (s[x]) {
            z = !z;
            for (auto y : adj[z][x]) {
                if (d[z][y] == -1) {
                    d[z][y] = td + 1;
                    q.push({y, z});
                    // print("to", y + 1, d[z][y]);
                }
            }
        }
    }

    int ans = -1;
    if (d[0][n - 1] >= 0) {
        ans = d[0][n - 1];
        if (d[1][n - 1] >= 0) {
            ans = std::min(ans, d[1][n - 1]);
        }
    } else if (d[1][n - 1] >= 0) {
        ans = d[1][n - 1];
    }
    std::cout << ans;

    return 0;
}