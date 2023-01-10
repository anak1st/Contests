/**
 * @author: XiaFan
 * @date: 11-08 19:02
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (a[n - 2] > a[n - 1]) {
        int num = n + (a[n - 1] - k) / (a[n - 2] - a[n - 1]) + 1;
        std::cout << "Python 3." << num << " will be faster than C++";
    } else {
        std::cout << "Python will never be faster than C++";
    }
    
    return 0;
}