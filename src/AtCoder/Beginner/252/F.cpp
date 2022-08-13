/**
 * @author: XiaFan
 * @date: 05-26 14:20
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    i64 l;
    cin >> n >> l;
    i64 no = l;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        no -= a[i];
    }
    priority_queue<i64, vector<i64>, greater<i64>> q;
    for (int i = 0; i < n; i++) {
        q.push(a[i]);
    }
    if (no > 0) {
        q.push(no);
    }
    i64 ans = 0;
    while (q.size() > 1) {
        i64 x = q.top();
        q.pop();
        i64 y = q.top();
        q.pop();
        q.push(x + y);
        ans += x + y;
    }
    cout << ans << "\n";

    return 0;
}