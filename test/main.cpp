/**
 * @author: XiaFan
 * @date: 2023-11-13 19:48
 */
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x = 6144;
    int y = (x >> 12);
    int z = (x & 0b1111'1111'1111);
    
    std::cout << y << "\n" << z << "\n";
    if (z >= 0b111'1111'1111) {
        z -= (1 << 12);
        y += 1;
    }
    std::cout << x << " = " << y << " * 2^12 " << z << "\n";
    std::cout << y << "\n" << z << "\n";

    return 0;
}