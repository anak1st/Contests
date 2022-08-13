#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    bool one = false;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i] == 1) {
            one = true;
        }
    }
    std::sort(a.begin(), a.end());
    if(!one) {
        std::cout << "YES\n";
        return;
    }

    for(int i = 1; i < n; i++) {
        if(a[i] - a[i - 1] == 1) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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