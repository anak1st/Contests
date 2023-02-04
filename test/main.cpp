/**
 * @author: XiaFan
 * @date: 2023-02-04 00:21
 **/
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 10;
    // std::cin >> n;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    std::cout << __cplusplus << "\n";

    return 0;
}