/**
 * @author: XiaFan
 * @date: 06-23 17:12
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

struct node {
    int p, l, x;  // price, level, size
    vector<int> ni;
    vector<int> np;
    node(int _p, int _l, int _x) : p(_p), l(_l), x(_x), ni(x), np(x) {}
};
vector<node> e;
vector<bool> vis;
int n, m;

int dfs(int pos, int left, int right) {
    int res = e[pos].p;
    for (int i = 0; i < e[pos].x; i++) {
        int bakleft = left;
        int bakright = right;
        int npos = e[pos].ni[i];
        int nprice = e[pos].np[i];
        if(vis[npos]) continue;
        left = min(left, e[npos].l);
        right = max(right, e[npos].l);
        if (right - left <= m && nprice < res) {
            vis[npos] = true;
            res = min(res, nprice + dfs(npos, left, right));
            vis[npos] = false;
        }
        left = bakleft;
        right = bakright;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    vis.resize(n, false);
    for (int i = 0; i < n; i++) {
        int p, l, x;
        cin >> p >> l >> x;
        node nd(p, l, x);
        for (int j = 0; j < x; j++) {
            cin >> nd.ni[j] >> nd.np[j];
            nd.ni[j]--;
        }
        e.push_back(nd);
    }
    vis[0] = true;
    int res = dfs(0, e[0].l, e[0].l);
    cout << res;

    return 0;
}
