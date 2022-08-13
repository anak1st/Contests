/**
 * @author: XiaFan
 * @date: 05-26 18:22
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int choose(vector<int> &a, int avoid, int &sum) {
    int p = max_element(a.begin(), a.end()) - a.begin();
    if (a[p] * 2 == sum + 1 && p != avoid) {
        a[p]--;
        sum--;
        return p;
    }
    if (a[p] * 2 >= sum + 1) {
        return -1;
    }

    for (int i = 0; i <= 9; i++) {
        if (a[i] > 0 && i != avoid) {
            a[i]--;
            sum--;
            return i;
        }
    }
    return -1;
}

void solve() {
    vector<int> a(10);
    int sum = 0;
    for (int i = 0; i <= 9; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum == a[0]) {
        if (sum == 1) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    string s;
    int n = sum, avoid = 0;
    for (int i = 0; i < n; i++) {
        avoid = choose(a, avoid, sum);
        if (avoid == -1) {
            cout << -1 << "\n";
            return;
        }
        s += ('0' + avoid);
    }
    cout << s << "\n";
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