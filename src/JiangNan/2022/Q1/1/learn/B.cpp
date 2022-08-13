#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using i64 = long long;

inline int pow2(int x) {
    return (1 << x);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while(true) {
        int n, m;
        std::cin >> m >> n;
        if(n == 0 && m == 0) break;

        int i = 0, ans = 0;
        while(true) {
            int temp = pow2(i);
            if(m * temp * 2 > n) break;

            ans += temp;
            i++;
        }

        int a = m * pow2(i);
        if(a <= n) {
            int b = std::min(a + pow2(i) - 1, n);
            ans += (b - a + 1);
        }

        std::cout << ans << '\n';
    }

    return 0;
}