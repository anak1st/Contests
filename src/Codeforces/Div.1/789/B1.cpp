/**
 * @author: XiaFan
 * @date: 05-09 00:13
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n - 1; i += 2) {
            if (s[i] != s[i + 1]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}