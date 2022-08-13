#include <bits/stdc++.h>

int slog(int x, int a) {
    // longa(x)
    int re = 0;
    while(x) {
        if(x % a != 0) {
            return re;
        } else {
            x /= a;
            re++;
        }
    }
    return re;
}

inline bool good(int x, int d) {
    return (x % d == 0 && x % (d * d) != 0);
}

void solve() {
    int x, t;
    std::cin >> x >> t;
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