/**
 * @author: XiaFan
 * @date: 05-25 21:30
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 10 * n;

    for (char num = '0'; num <= '9'; num++) {
        vector<bool> vis(n, true);
        int count = 0, ok = 0;
        for (int i = 0; true; i = (i + 1) % 10) {
            for (int j = 0; j < n; j++) {
                if (vis[j] && s[j][i] == num) {
                    vis[j] = false;
                    ok++;
                    break;
                }
            }
            if (ok == n) {
                break;
            }
            count++;
        }
        ans = min(ans, count);
    }

    cout << ans;

    return 0;
}