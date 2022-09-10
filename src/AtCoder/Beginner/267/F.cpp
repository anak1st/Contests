/**
 * @author: XiaFan
 * @date: 09-07 19:26
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    auto bfs = [&](int s) {
        std::vector<int> dis(n, -1);
        std::queue<int> q;
        q.push(s);
        dis[s] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto y : adj[x]) {
                if (dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
        return std::max_element(dis.begin(), dis.end()) - dis.begin();
    };
    
    int v1 = bfs(0);
    int v2 = bfs(v1);
    // tree_d = distance(v1, v2)
    
    int q;
    std::cin >> q;
    std::vector<std::vector<std::pair<int, int>>> queries(n);
    for (int i = 0; i < q; i++) {
        int x, k;
        std::cin >> x >> k;
        x--;
        queries[x].push_back({k, i});
    }

    std::vector<int> v_stack;
    std::vector<int> ans(q, -1);
    std::function<void(int, int)> dfs = [&](int x, int parent) {
        for (auto [k, i] : queries[x]) {
            if (int(v_stack.size()) >= k) {
                ans[i] = v_stack[v_stack.size() - k] + 1;
            }
        }
        v_stack.push_back(x);
        for (auto y : adj[x]) {
            if (y != parent) {
                dfs(y, x);
            }
        }
        v_stack.pop_back();
    };
    
    dfs(v1, -1);
    dfs(v2, -1);
    
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }
    
    return 0;
}