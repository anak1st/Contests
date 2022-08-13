#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }

    bool fun = true;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != a[i + 1]) {
            fun = false;
            break;
        }
    }
    if(fun) {
        std::cout << -1 << '\n';
        return;
    }

    if(a[0] == mx && a[0] > a[1]) {
        std::cout << 1 << '\n';
        return;
    }

    if(a[n - 1] == mx && a[n - 1] > a[n - 2]) {
        std::cout << n << '\n';
        return;
    }

    for(int i = 1; i < n - 1; i++) {
        if(a[i] == mx) {
            if(a[i] > a[i + 1] || a[i] > a[i - 1]) {
                std::cout << i + 1 << '\n';
                return;
            }
        }
    }
    std::cout << -2 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}