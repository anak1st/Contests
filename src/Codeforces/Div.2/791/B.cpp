/**
 * @author: XiaFan
 * @date: 05-14 22:31
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    i64 same = 0;
    i64 sum = 0;
    for (i64 &i : a) {
        cin >> i;
        sum += i;
    }
    set<i64> v;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            i64 x;
            cin >> i >> x;
            i--;
            if (same && !v.count(i)) {
                a[i] = same;
                v.insert(i);
            }
            sum += (x - a[i]);
            a[i] = x;
        } else {
            i64 x;
            cin >> x;
            same = x;
            sum = same * n;
            v.clear();
        }
        cout << sum << "\n";
    }

    return 0;
}