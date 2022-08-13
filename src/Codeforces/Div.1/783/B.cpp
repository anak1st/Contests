/**
 * @author: XiaFan
 * @date: 04-22 23:03
 **/
#include <bits/stdc++.h>

typedef long long i64;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.rbegin(), a.rend());
    i64 need = n + a[0] * 2;
    for(int i = 1; i < n - 1; i++) {
        need += a[i];
    }
    // std::cout << p << ' ';
    if(need <= m) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}