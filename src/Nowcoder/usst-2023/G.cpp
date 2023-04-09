#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5;
int a[2 * N + 10];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        a[x]++;
    }
    i64 ans = 0;
    for (int i = 0; i <= N; i++) {
        int x = (1 << 17) - 1 - i;
        for (int j = x;; j = (j - 1) & x) {
            ans += 1LL * a[i] * a[j];
            if (!j) break;
        }
    }
    std::cout << ans;
}