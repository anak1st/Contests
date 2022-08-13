/**
 * @author: XiaFan
 * @date: 04-24 11:02
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int c = 0;
    int left = n - 1, right = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            left = min(left, i + 1);
            right = max(right, i);
            c++;
        }
    }
    if(c <= 1) {
        cout << "0\n";
        return;
    }
    cout << max(1, right - left) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}