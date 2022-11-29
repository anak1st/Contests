/**
 * @author: XiaFan
 * @date: 11-23 19:26
 **/
#include <bits/stdc++.h>

#include <ranges>

using i64 = long long;

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    for (auto it : v) os << it << " ";
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (auto& i : s) {
        std::cin >> i;
    }
    std::vector<int> deg_in(n), deg_out(n);
    std::vector<std::vector<int>> adj(n), parent(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                deg_in[i]++;
                deg_out[j]++;
                adj[j].push_back(i);
                parent[i].push_back(j);
            }
        }
    }
    std::queue<int> q;
    std::vector<std::set<int>> ans(n);
    for (int i = 0; i < n; i++) {
        if (deg_out[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // print("adj_x size:", adj[x].size());
        std::ranges::for_each(adj[x], [&](int y) {
            for (auto i : ans[y]) ans[x].insert(i);
            // print(x, y, ans[y]);
        });
        ans[x].insert(cnt++);
        for (auto y : parent[x]) {
            deg_out[y]--;
            if (deg_out[y] == 0) {
                q.push(y);
            }
        }
    }

    for (auto i : ans) {
        std::cout << i.size() << " ";
        for (auto j : i) std::cout << j + 1 << " ";
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}