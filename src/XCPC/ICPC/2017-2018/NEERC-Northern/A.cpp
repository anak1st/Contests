/**
 * @author: XiaFan
 * @date: 01-09 18:05
 **/
#include <bits/stdc++.h>
using i64 = long long;

//         0  1  2  3  4  5  6  7  8  9
int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    freopen("auxiliary.in","r",stdin);
    freopen("auxiliary.out","w",stdout);

    int n;
    std::cin >> n;
    int _7 = n / 3;
    n %= 3;
    int ans = 7 * _7;
    if (n == 1) {
        ans = ans - 7;
        n += 3;
    }
    if (n == 2) {
        ans += 1;
        n -= 2;
    }
    if (n == 4) {
        ans += 4;
        n -= 4;
    }
    assert(n == 0);
    std::cout << ans;

    return 0;
}