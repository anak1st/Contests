/**
 * @author: XiaFan
 * @date: 05-30 15:42
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    vector<int> error;
    for (auto [x, c] : mp) {
        if (c * 2 > n) {
            cout << "NO\n";
            return;
        } else if (c * 2 == n) {
            error.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    for (int x : error) {
        if (x != a.front() && x != a.back()) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    int mid = n / 2;
    for (int i = 0; i < mid; i++) {
        cout << a[i] << " " << a[mid + i] << " ";
    }
    cout << "\n";
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