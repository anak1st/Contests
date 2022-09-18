/**
 * @author: XiaFan
 * @date: 09-16 20:21
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        p[x] = i;
    }

    std::vector<int> c(n);
    // c = b - a
    // b = c + a
    for (int i = 0; i < n; i++) {
        int j = p[i];
        if (i == 0) {
            c[j] = l - a[j];
        } else {
            c[j] = std::max(c[p[i - 1]] + 1, l - a[j]);
            if (c[j] > r - a[j]) {
                std::cout << "-1";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << c[i] + a[i] << " ";
    }
    
    return 0;
}