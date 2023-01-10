/**
 * @author: XiaFan
 * @date: 05-03 20:18
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

i64 len(i64 n) {
    return (n - 1) * (1 << n) + 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // 0 -> nullptr

    int t;
    cin >> t;
    while (t--) {
        i64 n;
        cin >> n;
        i64 left = 0, right = 32;
        i64 ans = 0;
        while (left <= right) {
            i64 mid = (left + right) / 2;
            if (len(mid) >= n) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}