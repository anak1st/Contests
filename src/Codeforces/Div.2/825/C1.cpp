/**
 * @author: XiaFan
 * @date: 10-12 19:48
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - a[j] < i - j) {
            j = i;
        }
        int add = std::min({i + 1, a[i], a[j] + i - j});
        //std::cout << add << " ";
        sum += add;
    }
    //std::cout << "\n";
    std::cout << sum << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}