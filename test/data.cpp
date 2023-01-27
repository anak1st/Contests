/**
 * @author: XiaFan
 * @date: 09-04 15:39
 **/
#include <bits/stdc++.h>
#include "Debug.h"
using i64 = long long;

constexpr i64 N = 1e3;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Randomer<int> R(-1, 1);

    int t = 100;
    std::cout << t << "\n";
    while (t--) {
        int n = 100;
        std::cout << n << "\n";
        for (int i = 0; i < n; i++) {
            std::cout << R() << " ";
        }
    }
    
    return 0;
}