#include <bits/stdc++.h>

using i64 = long long;

int fun(std::string s) {
    int max = *std::max_element(s.begin(), s.end()) - '0';
    int min = *std::min_element(s.begin(), s.end()) - '0';
    return max - min;
}

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    std::string L = std::to_string(l);
    std::string R = std::to_string(r);
    int n = L.length();
    int m = R.length();
    if (n != m) {
        std::cout << std::string(n, '9') << "\n";
        return;
    }

    int p = -1;
    for (int i = 0; i < n; i++) {
        if (L[i] != R[i]) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        std::cout << l << "\n";
        return;
    }

    std::string S = L.substr(0, p);
    L = L.substr(p);
    R = R.substr(p);

    std::string ans = L;
    for (int i = L[0] - '0'; i <= R[0] - '0'; i++) {
        for (int j = 0; j <= 9; j++) {
            std::string T = std::to_string(i) + std::string(L.length() - 1, j + '0');
            // std::cerr << T << "\n";
            if (L <= T && T <= R && fun(S + T) < fun(S + ans)) {
                ans = T;
            }
        }
    }

    std::cout << S + ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}