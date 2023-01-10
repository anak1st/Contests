#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
        a[i] = k - a[i];
    }
    
    std::vector<bool> f(k);
    int siz = 0;
    for (int i = 0, j = 0; i < k; i++) {
        while (!f[i]) {
            f[a[j]] = true;
            j++;
            siz++;
        }
        if (siz > n * m - 3) {
            std::cout << "TIDAK\n";
            return;
        }
        // f[i] = false;
        siz--;
    }
    std::cout << "YA\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
