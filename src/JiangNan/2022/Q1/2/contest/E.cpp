#include <bits/stdc++.h>

void solve() {
    std::string a;
    std::cin >> a;

    int ans = 0;
    for(int i = 0; i <= 99; i++) {
        int x = i / 10, y = i % 10;

        int now = 0;
        for(auto j : a) {
            if(j - '0' == x) {
                std::swap(x, y);
                now++;
            }
        }
        if(x != y && now % 2 == 1) {
            now--;
        }
        ans = std::max(ans, now);
    }

    std::cout << (int)a.length() - ans << '\n';
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