/**
 * @author: XiaFan
 * @date: 11-18 23:20
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    i64 tn = n;
    while (tn % 10 == 0) {
        tn /= 10;
    }
    i64 tm = 1;
    if (tn % 2 == 0) {
        int a = 0;
        while (tn % 2 == 0) {
            tn /= 2;
            a++;
        }
        while (tm * 5 <= m && a--) {
            tm *= 5;
        }
    }
    if (tn % 5 == 0) {
        int a = 0;
        while (tn % 5 == 0) {
            tn /= 5;
            a++;
        }
        while (tm * 2 <= m && a--) {
            tm *= 2;
        }
    }
    while (tm * 10 <= m) {
        tm *= 10;
    }
    tm = m / tm * tm;
    std::cout << n * tm << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}