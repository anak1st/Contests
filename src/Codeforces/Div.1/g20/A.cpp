/**
 * @author: XiaFan
 * @date: 04-24 10:39
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x += a - 1;
    }
    if(x % 2 == 1) {
        cout << "errorgorn\n";
    } else {
        cout << "maomao90\n";
    }
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