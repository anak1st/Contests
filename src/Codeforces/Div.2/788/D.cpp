/**
 * @author: XiaFan
 * @date: 05-09 20:40
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        i64 n;
        cin >> n;
        i64 left = 1, right = 60000, ans = 1;
        while (left <= right) {
            i64 mid = (left + right) / 2;
            i64 a = mid / 3;
            i64 b = (mid - a) / 2;
            i64 c = mid - a - b;
            if ((a * b + b * c + c * a) * 2 >= n) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}