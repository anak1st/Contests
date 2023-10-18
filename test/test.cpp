/**
 * @author: XiaFan
 * @date: 2023-10-09 22:30
 */
#include <bits/stdc++.h>

using i64 = long long;

union Fuck {
    float x;
    int y;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Fuck f;
    f.y = 0b0100100001110110101101011110;
    std::cout << std::hex << f.y << "\n";

    return 0;
}