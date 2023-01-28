/**
 * @author: XiaFan
 * @date: 2023-01-28 16:29
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 5;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    std::adjacent_difference(a.begin(), a.end(), a.begin());
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    std::partial_sum(a.begin(), a.end(), a.begin());
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}