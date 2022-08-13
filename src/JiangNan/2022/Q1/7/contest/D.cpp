/**
 * @author: XiaFan
 * @date: 04-24 19:59
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    /**
     *
     * 0
     * 1 0 1
     * 0 1 0 1
     * 1 0 1 0 1
     *
     */

    vector<i64> ans(2, 0);
    for(int i = 0; i < n; i++) {
        ans[0] += a[i] / 2;
        ans[1] += a[i] / 2;
        if(a[i] % 2) {
            ans[i % 2]++;
        }
    }
    cout << min(ans[0], ans[1]);

    return 0;
}