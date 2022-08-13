/**
 * @author: XiaFan
 * @date: 06-22 11:15
 **/
#include <algorithm>
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

using namespace std;
typedef long long i64;
const int inf = 1e9;

struct node {
    int x, dis;
    node(int x_, int dis_) : x(x_), dis(dis_) {}
    friend bool operator<(const node &lhs, const node &rhs) {
        return lhs.dis > rhs.dis;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 1000, m, s, t;
    while (cin >> m >> s >> t) {
        vector<vector<pair<int, int>>> e(n);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            e[a].push_back({b, c});
            e[b].push_back({a, c});
        }
        
        priority_queue<node> q;
        vector<int> vis(n, 0);
        for (int i = 0; i < s; i++) {
            int x;
            cin >> x;
            x--;
            q.push(node(x, 0));
            vis[x] = 1;
        }
        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;
            x--;
            vis[x] = 2;
        }

        while (!q.empty()) {
            node r = q.top();
            int now = r.x;
            int dis = r.dis;
            q.pop();
            if(vis[now] == 2) {
                cout << dis << "\n";
                break;
            }
            vis[now] = 1;
            int nn = e[now].size();
            for(int i = 0; i < nn; i++) {
                int next = e[now][i].first;
                int add = e[now][i].second;
                if(vis[next] == 1) {
                    continue;
                }
                q.push(node(next, dis + add));
                // cerr << now << " " << next << " " << dis + add << "\n";
            }
        }
    }

    return 0;
}