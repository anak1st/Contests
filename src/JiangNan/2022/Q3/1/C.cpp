/**
 * @author: XiaFan
 * @date: 09-09 19:13
 **/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
typedef long long i64;

struct node {
    int x;
    i64 c;
    node(int x_, i64 c_) : x(x_), c(c_) {}
    friend bool operator<(const node &a, const node &b) {
        return a.c > b.c;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> adj(3 * n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        std::cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    std::vector<int> dep(n, -1);
    dep[0] = 0;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < (int)adj[x].size(); i++) {
            int y = adj[x][i].first;
            if (dep[y] == -1) {
                dep[y] = dep[x] + 1;
                q.push(y);
            }
        }
    }
    // int m = *std::max_element(dep.begin(), dep.end());
    
    int k, p, s, t;
    std::cin >> k >> p >> s >> t;
    s--, t--;

    for (int i = 0; i < n; i++) {
        adj[i].push_back({n + dep[i], 0});
        adj[2 * n + dep[i]].push_back({i, 0});
    }
    for (int i = 0; i < n; i++) {
        adj[n + i].push_back({2 * n + (i + k) % n, p});
        adj[2 * n + i].push_back({n + (i + k) % n, p});
    }
    
    std::vector<bool> vis(3 * n);
    std::vector<i64> power(3 * n, 1e9);
    power[s] = 0;
    std::priority_queue<node> pq;
    pq.push(node(s, 0));
    
    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();
        int x = now.x;
        i64 c = now.c;
        
        if (vis[x]) {
            continue;
        }
        vis[x] = true;
        
        if (x == t) {
            break;
        }

        for (int i = 0; i < (int)adj[x].size(); i++) {
            int y = adj[x][i].first;
            i64 w = adj[x][i].second;
            if (power[y] > c + w) {
                power[y] = c + w;
                pq.push(node(y, power[y]));
            }
        }
    }

    std::cout << power[t] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}