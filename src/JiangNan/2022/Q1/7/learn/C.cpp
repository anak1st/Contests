/**
 * @author: XiaFan
 * @date: 04-18 10:18
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x;
    while(std::cin >> x) {
        i64 ans = 0;
        for(int i = 0; 3 * i <= x; i++) {
            // 2 ... 2 1(0)
            ans += (x - i * 3) / 2 + 1;
        }
        std::cout << ans << "\n";
    }

    return 0;
}