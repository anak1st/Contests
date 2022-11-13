/**
 * @author: XiaFan
 * @date: 09-29 19:10
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> b = a;
    std::sort(b.begin(), b.end(), std::greater<i64>());
    while (b.back() == 0) {
        b.pop_back();
    }
    i64 c = 0;
    while (k > i64(b.size())) {
        i64 min = b.back();
        min -= c;
        i64 d = std::min(min, k / i64(b.size()));
        c += d;
        k -= b.size() * d;
        b.pop_back();
    }

    for (int i = 0; i < n; i++) {
        a[i] = std::max(a[i] - c, 0LL);
        if (k > 0 && a[i] > 0) {
            k--;
            a[i]--;
        }
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    
    return 0;
}