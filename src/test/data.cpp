/**
 * @author: XiaFan
 * @date: 09-04 15:39
 **/
#include <bits/stdc++.h>
#include "Debug.h"
using i64 = long long;

constexpr i64 N = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 t = 10000;
    std::cout << t << "\n";
    Randomer<i64> Rand(1, N);
    while (t--) {
        i64 n = Rand();
        i64 L = Rand();
        i64 R = L + Rand();
        std::cout << n << " " << L << " " << R << "\n";
    }

    return 0;
}