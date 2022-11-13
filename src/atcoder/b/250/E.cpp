/**
 * @author: XiaFan
 * @date: 05-10 20:23
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    map<int, int> pa, pb;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!pa.count(a[i])) {
            pa[a[i]] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (!pb.count(b[i])) {
            pb[b[i]] = i;
        }
    }
    vector<int> fa(n + 1), fb(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = max(fa[i - 1], (pb.count(a[i]) ? pb[a[i]] : n + 1));
        fb[i] = max(fb[i - 1], (pa.count(b[i]) ? pa[b[i]] : n + 1));
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (fa[x] <= y && fb[y] <= x) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}