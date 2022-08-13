/**
 * @author: XiaFan
 * @date: 05-05 10:37
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        c[a[i]]++;
        cnt = max(cnt, c[a[i]]);
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    vector<vector<int>> all(n);
    for (int i = 0; i < n; i++) {
        all[b[i]].push_back(b[(i + cnt) % n]);
    }
    for (int i = 0; i < n; i++) {
        cout << all[a[i]].back() + 1 << " ";
        all[a[i]].pop_back();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}