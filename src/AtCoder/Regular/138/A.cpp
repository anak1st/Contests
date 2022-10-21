/**
 * @author: XiaFan
 * @date: 2022-04-09 22:07:48
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for(int i = k - 1; i >= 1; i--) {
        a[i] = std::min(a[i], a[i + 1]);
    }
    for(int i = k + 2; i <= n; i++) {
        a[i] = std::max(a[i], a[i - 1]);
    }

    if(a[1] >= a[n]) {
        std::cout << -1 << '\n';
        return 0;
    }

    int ans = n + 1;
    for(int i = 1, j = k + 1; i <= k && j <= n; j++) {
        while(i + 1 <= k && a[i + 1] < a[j]) {
            i++;
        }
        // std::cerr << i << ' ' << j << '\n';
        if(a[i] < a[j]) {
            ans = std::min(ans, j - i);
        }
    }
    std::cout << ans << '\n';

    return 0;
}