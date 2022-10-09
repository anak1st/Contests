/**
 * @author: XiaFan
 * @date: 09-30 19:56
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](int x) -> bool {
        std::vector<int> b(n);
        std::bitset<32> xx(x);

        for (int i = 0; i < n; i++) {
            int j = 30;
            std::bitset<32> aa(a[i]);
            while (j >= 0 && (aa[j] || !xx[j])) {
                j--;
            }
            if (j >= 0) {
                b[i] = (x & ((1 << (j + 1)) - 1)) - (a[i] & ((1 << j) - 1));
            }
        }

        std::sort(b.begin(), b.end());
        i64 res = std::accumulate(b.begin(), b.begin() + k, 0LL);
        return res <= m;
    };

    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int add = 1 << i;
        if (check(ans | add)) {
            ans |= add;
        }
    }
    std::cout << ans;
    
    return 0;
}