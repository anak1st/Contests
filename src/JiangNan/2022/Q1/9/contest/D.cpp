/**
 * @author: XiaFan
 * @date: 05-08 19:51
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        int next = ((i + a[i]) % n + n) % n;
        st.insert(next);
    }
    if (int(st.size()) == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}