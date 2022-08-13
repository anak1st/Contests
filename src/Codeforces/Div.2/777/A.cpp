#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    if(n >= 3) {
        if(n % 3 == 1) {
            // last=1
            while(n >= 3) {
                n -= 3;
                std::cout << "12";
            }
        } else if(n % 3 == 2) {
            // last=2
            while(n >= 3) {
                n -= 3;
                std::cout << "21";
            }
        } else {
            // last=21
            while(n >= 3) {
                n -= 3;
                std::cout << "21";
            }
        }
    }
    if(n >= 1) {
        std::cout << n;
    }
    std::cout << '\n';
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