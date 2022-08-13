/**
 * @author: XiaFan
 * @date: 06-11 20:00
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<bool> b(n, true);
    for(auto &i : a) {
        cin >> i;
        i--;
        b[i] = false;
    }

    vector<pair<double, double>> p(n);
    for(auto &[i, j] : p) {
        cin >> i >> j;
    }

    double r = 0;
    for(int i = 0; i < n; i++) {
        if(b[i]) {
            double tr = 1e12;
            auto [x1, y1] = p[i];
            for(auto j : a) {
                auto [x2, y2] = p[j];
                auto x = abs(x1 - x2);
                auto y = abs(y1 - y2);
                tr = min(tr, sqrt(x * x + y * y));
            }
            r = max(r, tr);
        }
    }
    cout << fixed << setprecision(10) << r;

    return 0;
}