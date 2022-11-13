/**
 * @author: XiaFan
 * @date: 05-24 19:17
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#include <bits/stdc++.h>

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ones;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones.push_back(i);
        }
    }

    int m = ones.size();
    if (m == n || m % 2 != 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<array<int, 2>> ans;
    for (int i = 0; i < m; i++) {
        for (int j = ones[i]; (j + 1) % n != ones[(i + 1) % m]; j++) {
            ans.push_back({j % n, (j + 1) % n});
        }
    }
    for (int i = 1; i < m; i++) {
        ans.push_back({(ones[0] - 1 + n) % n, ones[i]});
        cout << (ones[0] - 1 + n) % n + 1 << " " << ones[i] << "\n";
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