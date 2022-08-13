/**
 * @author: XiaFan
 * @date: 2022-04-10 19:39:30
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

i64 ans = 0;
i64 gcd(i64 a, i64 b) {
    if(b == 0) {
        return a;
    }
    ans += a / b;
    return gcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 a, b;
    std::cin >> a >> b;
    gcd(a, b);
    std::cout << ans << '\n';

    return 0;
}