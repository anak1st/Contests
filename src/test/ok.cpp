/**
 * @author: XiaFan
 * @date: 12-03 11:23
 **/
#include <bits/stdc++.h>
#include <bits/extc++.h>
#include "testing/Splay.hpp"
// #include "xf.hpp"

#ifndef DEBUG_XF
#define printIn(...)
#endif

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Splay<int> S;

    for (int i = 0; i < 100; i++) {
        S.insert(i * 2 + 1);
    }

    auto it = S.find_by_order(50);
    if (it == S.end()) {
        std::cout << "Not Found!";
    } else {
        int val = *it;
        std::cout << *it << "\n";
        std::cout << S.order_of_key(val) << "\n";
    }
    
    return 0;
}