#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    i64 k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if(n == 1) {
        if(a[0] == k) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
        return;
    }

    std::sort(a.begin(), a.end());

    for(int i = 0, j = 1; i < n - 1 && j < n;) {
        if(a[j] - a[i] == k) {
            std::cout << "YES\n";
            return;
        } else if(a[j] - a[i] - k > 0) {
            i++;
        } else {
            j++;
        }
    }
    std::cout << "NO\n";
    return;
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