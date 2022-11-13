/**
 * @author: XiaFan
 * @date: 06-11 14:42
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s1, s2;
    cin >> s1 >> s2;

    multiset<char> st1, st2;
    for(int i = 0; i < n; i++) {
        st1.insert(s1[i]);
    }
    for(int i = 0; i < m; i++) {
        st2.insert(s2[i]);
    }

    string ans;
    int k1 = 0, k2 = 0;
    while(!st1.empty() && !st2.empty()) {
        bool first = true;
        if(k1 == k) {
            first = false;
        }
        if(k2 < k && *st1.begin() > *st2.begin()) {
            first = false;
        }

        if(first) {
            ans.push_back(*st1.begin());
            st1.erase(st1.begin());
            k1++;
            k2 = 0;
        } else {
            ans.push_back(*st2.begin());
            st2.erase(st2.begin());
            k2++;
            k1 = 0;
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