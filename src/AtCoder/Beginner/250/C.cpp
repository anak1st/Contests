/**
 * @author: XiaFan
 * @date: 05-09 22:19
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        b[a[i]] = i;
    }
    for (int j = 1; j <= q; j++) {
        int x;
        cin >> x;
        int c, d;
        if (b[x] == n) {
            c = b[x] - 1;
            d = b[x];
        } else {
            c = b[x];
            d = b[x] + 1;
        }
        swap(b[a[c]], b[a[d]]);
        swap(a[c], a[d]);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}