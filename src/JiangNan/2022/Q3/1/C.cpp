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
    int x, c;
    node(int x_, int c_) : x(x_), c(c_) {}
    friend bool operator<(const node &a, const node &b) {
        return a.c > b.c;
    }
};


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        std::cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    std::vector<int> dep(n, -1);
    std::vector<int> b(n, -1);

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
    
    int k, p, s, t;
    std::cin >> k >> p >> s >> t;
    s--, t--;
    
    std::vector<int> power(n, -1);
    std::priority_queue<node> pq;
    pq.push(node(s, 0));
    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();

        int x = now.x, c = now.c;
        power[x] = c;
        
        if (b[dep[x]] == -1 || power[b[dep[x]]] > power[x]) {
            b[dep[x]] = x;
        }

        for (int i = 0; i < (int)adj[x].size(); i++) {
            int y = adj[x][i].first;
            int w = adj[x][i].second;
            if (power[y] == -1) {
                pq.push(node(y, c + w));
            }
        }
    }

    power.assign(n, -1);
    
    pq.push(node(s, 0));
    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();

        int x = now.x, c = now.c;
        power[x] = c;

        for (int i = 0; i < (int)adj[x].size(); i++) {
            int y = adj[x][i].first;
            int w = adj[x][i].second;
            if (power[y] == -1) {
                pq.push(node(y, c + w));
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