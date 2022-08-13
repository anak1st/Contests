/**
 * @author: XiaFan
 * @date: 05-07 18:44
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<vector<int>> b(n);
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == i) {
                root = i;
            } else {
                b[a[i]].push_back(i);
            }
        }
        queue<int> q;
        vector<vector<int>> ans;
        q.push(root);
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            vector<int> path;
            path.push_back(r);
            while (!b[r].empty()) {
                path.push_back(b[r][0]);
                for (int i = 1; i < (int)b[r].size(); i++) {
                    q.push(b[r][i]);
                }
                r = b[r][0];
            }
            ans.push_back(path);
        }
        int m = ans.size();
        cout << m << "\n";
        for (int i = 0; i < m; i++) {
            int len = ans[i].size();
            cout << len << "\n";
            for (int j = 0; j < len; j++) {
                cout << ans[i][j] + 1 << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}