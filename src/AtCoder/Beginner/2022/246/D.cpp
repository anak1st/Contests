/**
 * @author: XiaFan
 * @date: 2022-04-13 14:18:26
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

i64 fun(i64 a, i64 b) {
    i64 res = 0;
    res += a * a * a;
    res += a * a * b;
    res += a * b * b;
    res += b * b * b;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;
    i64 mn = 0;
    i64 mx = 1e6;
    i64 ans = 1e18;

    for(int i = mn; i <= mx; i++) {
        i64 left = mn, right = mx, cur = ans;
        while(left <= right) {
            i64 mid = (left + right) / 2;
            i64 res = fun(i, mid);
            if(res >= n) {
                right = mid - 1;
                cur = res;
            } else {
                left = mid + 1;
            }
        }
        ans = std::min(ans, cur);
    }
    std::cout << ans << "\n";

    return 0;
}