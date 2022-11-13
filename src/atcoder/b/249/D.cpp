/**
 * @author: XiaFan
 * @date: 05-12 20:48
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> v;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += v[a[i]];
        for (int j = i - 1; j >= 0; j--) {
            v[a[i] * a[j]]++;
            if (a[i] % a[j] == 0) {
                v[a[i] / a[j]]++;
            } else if (a[j] % a[i] == 0) {
                v[a[j] / a[i]]++;
            }
        }
    }

    cout << ans * 2;

    return 0;
}