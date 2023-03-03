/**
 * @author: XiaFan
 * @date: 07-16 17:36
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    set<string> st;
    for (auto &it : s) {
        cin >> it;
        st.insert(it);
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int len = s[i].length();
        for (int j = 1; j <= len - 1; j++) {
            string a = s[i].substr(0, j);
            string b = s[i].substr(j);
            // cout << a << " " << b << "\n";
            if (st.count(a) && st.count(b)) {
                ans[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << "\n";
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