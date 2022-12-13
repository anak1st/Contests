#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1E7;

namespace Primes {
constexpr int N = 1e7;
std::vector<int> primes;
int minp[N + 1];  // minp[i] = min prime factor of i
void init() {
    for (int i = 2; i <= N; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) break;
            minp[i * p] = p;
            if (i % p == 0) break;
        }
    }
}
}  // namespace Primes

void solve() {
    int x, y;
    std::cin >> x >> y;

    int d = y - x;
    if (d == 1) {
        std::cout << -1 << "\n";
        return;
    }

    auto fun = [&](int p) -> int {
        int a = (x + p - 1) / p;
        int da = a * p - x;
        int b = (y + p - 1) / p;
        int db = b * p - y;
        return std::max(da, db);
    };

    int ans = 1E9;
    while (d > 1) {
        int p = Primes::minp[d];
        d /= p;
        ans = std::min(ans, fun(p));
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Primes::init();

    int T;
    std::cin >> T;
    while (T--) solve();

    return 0;
}
