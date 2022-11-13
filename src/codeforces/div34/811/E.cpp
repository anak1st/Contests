/**
 * @author: XiaFan
 * @date: 08-10 23:09
 **/
#include <bits/stdc++.h>
using i64 = long long;

int fun(int x) {
    return x + (x % 10);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    bool flag = false;
    for (auto &x : a) {
        std::cin >> x;
        if (x % 5 == 0) {
            x = fun(x);
            flag = true;
        } else {
            while (x % 10 != 2) {
                x = fun(x);
            }
        }
    }
    std::sort(a.begin(), a.end());
    
    if (flag) {
        if (std::count(a.begin(), a.end(), a.front()) == n) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
        return;
    }
    
    int b = a.front();
    bool ok = true;
    for (auto i : a) {
        if ((b - i) % 20 != 0) {
            ok = false;
        }
    }

    if (ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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