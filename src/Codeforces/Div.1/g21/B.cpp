/**
 * @author: XiaFan
 * @date: 06-30 23:31
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
        cin >> n;
        bool flag = false;
        int ans = 0;
        while (n--) {
            int a;
            cin >> a;
            if (a > 0) {
                flag = true;
            }
            if (a == 0 && flag) {
                flag = false;
                ans++;
            }
        }
        if (flag) {
            ans++;
        }
        cout << min(2, ans) << "\n";
    }

    return 0;
}