#include <bits/stdc++.h>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b + c) {
        std::cout << "YES\n";
        if (a == 1) {
            std::cout << 0 << "\n";
        } else {
            std::cout << (b + c) * 2 + 1 << "\n";
        }
    } else {
        std::cout << "NO\n";
    }

    return 0;
}