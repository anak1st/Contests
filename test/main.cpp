/**
 * @author: XiaFan
 * @date: 2023-01-27 21:57
 **/
#include <bits/stdc++.h>
#include <vector>
#include <debug/vector>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << __cplusplus << "\n";
    std::vector<std::string> a;
    for (int i = 1; i <= 9; i++) {
        a.emplace_back(i, '0' + i);
    }
    std::cout << a.size() << "\n";

    return 0;
}