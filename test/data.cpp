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

    Randomer<int> R(100000, 200000);

    int t = 10;
    std::cout << t << "\n";
    while (t--) {
        std::cout << 1 << " " << R() << "\n";
    }
    
    return 0;
}