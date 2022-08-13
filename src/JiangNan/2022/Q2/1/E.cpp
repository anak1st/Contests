/**
 * @author: XiaFan
 * @date: 06-22 13:46
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

struct edge {
    int a, b, c;
    edge(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {}
};

bool BellmanFord(int n, const std::vector<edge> &e) {
    std::vector<int> dis(n, inf);
    dis[0] = 0;
    int m = e.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int a = e[j].a;
            int b = e[j].b;
            int c = e[j].c;
            dis[a] = std::min(dis[a], dis[b] + c);
        }
    }
    for (int j = 0; j < m; j++) {
        int a = e[j].a;
        int b = e[j].b;
        int c = e[j].c;
        if (dis[a] > dis[b] + c) {
            return true;
        }
    }
    return false;
}
void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    std::vector<edge> e;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        e.push_back(edge(a, b, c));
        e.push_back(edge(b, a, c));
    }
    for (int i = 0; i < w; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        e.push_back(edge(a, b, -c));
    }
    bool flag = BellmanFord(n, e);
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}