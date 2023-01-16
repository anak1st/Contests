/**
 * @author: XiaFan
 * @date: 2023-01-16 13:29
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n >= m * 3 - 2) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> a(n);
    auto fun = [&]() {
        int res = 0;
        for (int i = 0; i + 2 < n; i++) {
            int j = 0;
            if (a[i]) j++;
            if (a[i + 1]) j++;
            if (a[i + 2]) j++;
            if (j >= 2) res++;
        }
        return res;
    };

    int l = 0, r = n - 1;
    // 00L....R00
    auto test = [&]() {
        if(std::max(r - l + 1, 0) >= m * 3 - 2) {
            std::cout << fun();
            exit(0);
        }
    };

    l += 2;
    if (m > 0) {
        a[0] = 1;
        m--;
        l++;
    }
    test();
    if (m > 0) {
        a[1] = 1;
        m--;
        l++;
    }
    test();
    
    r -= 2;
    if (m > 0) {
        a[n - 1] = 1;
        m--;
        r--;
    }
    test();
    if (m > 0) {
        a[n - 2] = 1;
        m--;
        r--;
    }
    test();

    for (int i = 2; i <= n - 3; i++) {
        if (m > 0) {
            a[i] = 1;
            m--;
            l++;
        } else {
            break;
        }
        test();
    }

    std::cout << fun();

    return 0;
}