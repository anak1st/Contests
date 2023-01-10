/**
 * @author: XiaFan
 * @date: 05-04 21:21
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    int n;
    cin >> n;
    int left = 1, right = n * 2000 + n - 1;
    int maxw = right;
    while (left <= right) {
        int w = (left + right) / 2;
        cout << "? " << w << endl;
        int h;
        cin >> h;
        if (h == 1) {
            right = w - 1;
            maxw = w;
        } else {
            left = w + 1;
        }
    }

    int ans = maxw;
    for (int i = 1; i <= n; i++) {
        cout << "? " << maxw / i << endl;
        int h;
        cin >> h;
        if (h) {
            ans = min(ans, h * (maxw / i));
        }
    }
    cout << "! " << ans << endl;

    return 0;
}