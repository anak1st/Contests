/**
 * @author: XiaFan
 * @date: 05-04 19:36
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> cnt(n + 1);
    int i = 0, j = 0;
    while (j < n) {
        if (i < n && a[i] == b[j]) {
            i++, j++;
        } else if (j > 0 && b[j] == b[j - 1] && cnt[b[j]] > 0) {
            cnt[b[j]]--;
            j++;
        } else if (i < n) {
            cnt[a[i]]++;
            i++;
        } else {
            break;
        }
    }
    if (i == n && j == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  // 0 -> nullptr

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}