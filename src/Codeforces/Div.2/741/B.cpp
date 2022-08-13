#include <bits/stdc++.h>
using i64 = long long;

bool prime(int x) {
    if(x <= 1) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;

    for(int i = 3; i * i <= x; i += 2) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::string num;
    std::cin >> num;

    // 2 3 5 7
    for(int i = 0; i < n; i++) {
        int x = num[i] - '0';
        if(!prime(x)) {
            std::cout << 1 << '\n';
            std::cout << x << '\n';
            return;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int x = (num[i] - '0') * 10 + (num[j] - '0');
            if(!prime(x)) {
                std::cout << 2 << '\n';
                std::cout << x << '\n';
                return;
            }
        }
    }
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