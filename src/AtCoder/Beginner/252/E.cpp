/**
 * @author: XiaFan
 * @date: 05-25 22:23
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct node {
    i64 len;
    int root;
    int index;
    node(i64 _len, int _root, int _index) : len(_len), root(_root), index(_index) {}
    friend bool operator>(const node& lhs, const node& rhs) {
        return lhs.len > rhs.len;
    }
};

struct edge {
    int index;
    int to;
    i64 len;
    edge(int _index, int _to, i64 _len) : index(_index), to(_to), len(_len) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<edge>> e(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        e[a].emplace_back(i + 1, b, c);
        e[b].emplace_back(i + 1, a, c);
    }

    vector<int> ans;
    vector<bool> visv(n);
    priority_queue<node, vector<node>, greater<node>> q;
    q.push(node(0, 0, -1));
    while (!q.empty()) {
        auto [len, root, index] = q.top();
        q.pop();
        if (visv[root]) {
            continue;
        }
        visv[root] = true;
        if (index > 0) {
            ans.push_back(index);
        }

        for (auto [next, v, l] : e[root]) {
            q.emplace(l + len, v, next);
        }
    }

    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}