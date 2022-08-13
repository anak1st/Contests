/**
 * @author: XiaFan
 * @date: 05-08 19:32
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= x) {
            ans++;
        }
    }
    ans = (ans + 1) / 2;
    if (x > y) {
        ans = n;
    }
    cout << ans << "\n";

    return 0;
}