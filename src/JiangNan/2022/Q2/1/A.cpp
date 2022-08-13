/**
 * @author: XiaFan
 * @date: 06-22 09:43
 **/
#include <algorithm>
#include <cmath>
#include <functional>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> edge(n);
        vector<int> cnt(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edge[u].push_back(v);
            cnt[v]++;
        }

        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                q.push(i);
            }
        }

        bool ok = true;
        while (!q.empty()) {
            int r = q.top();
            q.pop();
            int nn = edge[r].size();
            ans.push_back(r);
            for (int i = 0; i < nn; i++) {
                int v = edge[r][i];
                cnt[v]--;
                if (cnt[v] == 0) {
                    q.push(v);
                }
            }
            if (ok) {
                cout << r + 1;
                ok = false;
            } else {
                cout << " " << r + 1;
            }
        }
        cout << "\n";
    }

    return 0;
}