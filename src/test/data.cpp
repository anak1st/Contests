/**
 * @author: XiaFan
 * @date: 09-04 15:39
 **/
#include <bits/stdc++.h>
#include "Debug.h"
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 t = 10;
    std::cout << t << "\n";
    while (t--) {
        i64 n = 10;
        std::cout << n << "\n";
        Randomer<int> R(1, n);
        for (int i = 0; i < n; i++) {
            std::cout << R() << " ";
        }
        std::cout << "\n";
    }

    return 0;
}