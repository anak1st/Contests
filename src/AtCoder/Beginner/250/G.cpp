/**
 * @author: XiaFan
 * @date: 05-11 20:20
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<i64, vector<i64>, greater<i64>> q;
    q.push(a[0]);
    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        if (!q.empty() && a[i] > q.top()) {
            ans += a[i] - q.top();
            q.pop();
            q.push(a[i]);
        }
        q.push(a[i]);
    }
    cout << ans << "\n";

    return 0;
}