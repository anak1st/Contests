/**
 * @author: XiaFan
 * @date: 04-22 23:46
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 1e18;
    for(int i = 0; i < n; i++) {
        i64 c = 0;
        b[i] = 0;
        for(int j = i - 1; j >= 0; j--) {
            i64 need = ceil(1.0 * (b[j + 1] + 1) / a[j]);
            b[j] = need * a[j];
            c += need;
        }
        for(int j = i + 1; j < n; j++) {
            i64 need = ceil(1.0 * (b[j - 1] + 1) / a[j]);
            b[j] = need * a[j];
            c += need;
        }
        ans = min(ans, c);
    }
    cout << ans << '\n';

    return 0;
}