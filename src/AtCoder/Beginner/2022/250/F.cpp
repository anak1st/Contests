/**
 * @author: XiaFan
 * @date: 05-10 20:45
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128_t;

i64 triangle_s(pair<i64, i64> v1, pair<i64, i64> v2, pair<i64, i64> v3) {
    auto [x1, y1] = v1;
    auto [x2, y2] = v2;
    auto [x3, y3] = v3;
    i64 res = x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<i64, i64>> v(n);
    for (auto &[x, y] : v) {
        cin >> x >> y;
    }

    i64 a = 0;
    for (int i = 0; i < n; i++) {
        a += triangle_s({0, 0}, v[i], v[(i + 1) % n]);
    }
    i64 ans = a;
    i64 s = 0;
    for (int i = 0, j = 1; i < n; i++) {
        while (true) {
            ans = min(ans, abs(a - s));
            i64 add = 4 * triangle_s(v[i], v[j % n], v[(j + 1) % n]);
            if (s > a && s + add > a) {
                break;
            }
            j++;
            s += add;
        }
        s -= 4 * triangle_s(v[i], v[(i + 1) % n], v[j % n]);
    }

    cout << ans;

    return 0;
}