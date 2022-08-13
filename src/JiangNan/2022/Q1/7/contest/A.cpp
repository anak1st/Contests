/**
 * @author: XiaFan
 * @date: 04-24 19:31
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<double> b(n);
    for(int i = 0; i < n; i++) {
        double y = r;
        for(int j = 0; j < i; j++) {
            int x = abs(a[i] - a[j]);
            if(x <= 2 * r) {
                y = max(y, b[j] + sqrt(4 * r * r - x * x));
            }
        }
        b[i] = y;
    }
    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(10) << b[i] << ' ';
    }

    return 0;
}