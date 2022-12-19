/**
 * @author: XiaFan
 * @date: 12-17 18:37
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n = 3;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    do {
        for (auto x : a) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(a.begin(), a.end()));

    return 0;
}