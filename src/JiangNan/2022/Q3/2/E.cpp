/**
 * @author: XiaFan
 * @date: 09-16 19:12
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    i64 a = 1;
    for (int i = n; i > n - 5; i--) {
        a *= i;
    }
    a = a / 120 * a;
    std::cout << a;
    
    return 0;
}