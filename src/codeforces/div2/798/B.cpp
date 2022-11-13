/**
 * @author: XiaFan
 * @date: 06-11 15:04
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "-1\n";
        return;
    }

    vector<int> b(n + 1, 0);
    int p = n;
    if (a[n] == n) {
        b[n - 1] = n;
        p--;
    }

    set<int> num;
    for (int i = 1; i <= p; i++) {
        num.insert(i);
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] > 0) {
            continue;
        }
        auto it = num.begin();
        if (*it == a[i]) {
            it = num.upper_bound(a[i]);
        }
        assert(it != num.end());
        b[i] = *it;
        num.erase(it);
    }

    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
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