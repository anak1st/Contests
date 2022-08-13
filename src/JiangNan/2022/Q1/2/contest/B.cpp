#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int &it : a) {
        std::cin >> it;
    }
    std::sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; i++) {
        if(a[i + 1] - a[i] > 1) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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