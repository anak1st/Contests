/**
 * @author: XiaFan
 * @date: 06-07 18:48
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for(auto& [x, a, d, t] : a) {
        cin >> x >> a >> d >> t;
    }

    return 0;
}