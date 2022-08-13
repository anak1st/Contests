/**
 * @author: XiaFan
 * @date: 04-24 19:13
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 1e9 + 10;

    vector<int> b(n + 2), c(n + 2);
    b[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i - 1] < a[i]) {
            b[i] = b[i - 1] + 1;
        } else {
            b[i] = 1;
        }
    }
    c[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] < a[i + 1]) {
            c[i] = c[i + 1] + 1;
        } else {
            c[i] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int t = b[i - 1] + 1 + c[i + 1];
        if(a[i + 1] - a[i - 1] < 2) {
            t = max(b[i - 1], c[i + 1]) + 1;
        }
        ans = max(ans, t);
    }
    cout << ans << '\n';

    return 0;
}