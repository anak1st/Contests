/**
 * @author: XiaFan
 * @date: 05-30 15:38
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (j > a[i]) {
                j = 0;
                k++;
            } else {
                j = max(j, a[i]);
            }
        }
        cout << k << "\n";
    }

    return 0;
}