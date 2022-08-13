/**
 * @author: XiaFan
 * @date: 06-30 23:26
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        i64 x;
        cin >> n >> x;
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            i64 a;
            cin >> a;
            ans = max(ans, a | x);
        }
        cout << ans << '\n';
    }
    

    return 0;
}