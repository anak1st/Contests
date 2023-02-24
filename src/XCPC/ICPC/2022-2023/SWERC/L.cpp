/**
 * @author: XiaFan
 * @date: 2023-02-19 19:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    i64 x = std::count(s.begin(), s.end(), '+');
    i64 y = std::count(s.begin(), s.end(), '-');
    i64 q;
    std::cin >> q;
    while (q--) {
        i64 a, b;
        std::cin >> a >> b;
        if (a == b) {
            if (x == y) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            double k = 1.0 * (x - y) / (b - a);
            if (k * b != round(k * b)) {
                std::cout << "NO\n";
                continue;
            } else {
                i64 kb = k * b;
                if (-y <= kb && kb <= x) {
                    std::cout << "YES\n";
                } else {
                    std::cout << "NO\n";
                }
            }
        }
    }

    return 0;
}