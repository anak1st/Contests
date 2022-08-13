#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    if(n % 2 == 0) {
        std::cout << n + 12 << ' ' << 12;
    } else {
        std::cout << n + 15 << ' ' << 15;
    }

    return 0;
}