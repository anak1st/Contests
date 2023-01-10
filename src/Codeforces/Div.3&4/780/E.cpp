#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, one = 0;
    std::cin >> n;
    std::vector<std::string> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        one += std::count(a[i].begin(), a[i].end(), '1');
    }
    int diagonal = 0;
    for(int k = 0; k < n; k++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            int i = (k + j) % n;
            cnt += (a[i][j] == '1');
        }
        diagonal = std::max(diagonal, cnt);
    }

    std::cout << one - diagonal + n - diagonal << '\n';
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