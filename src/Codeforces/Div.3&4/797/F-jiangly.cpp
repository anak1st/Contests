#include <bits/stdc++.h>
 
using i64 = long long;
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    i64 ans = 1;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        string t;
        for (int j = i; !vis[j]; j = a[j]) {
            vis[j] = true;
            t += s[j];
        }
        int m = t.length();

        vector<int> f(n + 1);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && t[i] != t[j]) {
                j = f[j];
            }
            if (t[i] == t[j]) {
                j++;
            }
            f[i + 1] = j;
        }
        if (m % (m - f[m]) == 0) {
            ans = lcm(ans, m - f[m]);
        } else {
            ans = lcm(ans, m);
        }
    }
    
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}