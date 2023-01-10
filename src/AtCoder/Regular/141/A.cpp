/**
 * @author: XiaFan
 * @date: 05-29 20:04
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 to_int(string s) {
    i64 res = 0;
    for (int i = 0; i < int(s.length()); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<string> ans;
    for (int len = 1; len * 2 <= n; len++) {
        if (n % len) {
            continue;
        }
        string t = s.substr(0, len);
        bool big = false;
        for (int i = len; i + len <= n; i += len) {
            string c = s.substr(i, len);
            // cerr << to_int(t) << " " << to_int(c) << "\n";
            if (to_int(t) < to_int(c)) {
                break;
            }
            if (to_int(t) > to_int(c)) {
                big = true;
                break;
            }
        }
        if (big) {
            t = to_string(to_int(t) - 1);
        }

        string t_ans;
        for (int i = 0; i < n / len; i++) {
            t_ans += t;
        }
        ans.push_back(t_ans);
    }
    ans.push_back(string(n - 1, '9'));

    sort(ans.begin(), ans.end(), [&](string a, string b) -> bool {
        return to_int(a) > to_int(b);
    });

    cout << ans[0] << "\n";
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