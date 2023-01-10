/**
 * @author: XiaFan
 * @date: 05-31 22:56
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int calc(string s) {
    int n = s.length(), y = 0;
    for(int i = 0; i < n - 1; i++) {
        int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
        y += x;
    }
    return y;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c = count(s.begin(), s.end(), '1');
    if(c == 0 || c == n || k == 0) {
        cout << calc(s) << "\n";
        return;
    }

    int d1 = find(s.rbegin(), s.rend(), '1') - s.rbegin();
    if(d1 <= k) {
        k -= d1;
        swap(s[n - 1], s[n - 1 - d1]);
        c--;
    }

    if(c >= 1) {
        int d2 = find(s.begin(), s.end(), '1') - s.begin();
        if(d2 <= k) {
            k -= d2;
            swap(s[0], s[d2]);
        }
    }
    
    cout << calc(s) << "\n";
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