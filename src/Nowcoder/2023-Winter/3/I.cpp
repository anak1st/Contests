/**
 * @author: XiaFan
 * @date: 2023-01-20 16:54
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 1e6;
std::vector<int> primes;
int minp[N + 1]; // minp[i] = min prime factor of i
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
std::vector<int> get_facts(int x) {
    std::vector<int> facts;
    int t = x;
    while (t > 1) {
        if (facts.empty() || facts.back() != minp[t]) {
            facts.push_back(minp[t]);
        }
        t /= minp[t];
    }
    return facts;
}
bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    return minp[x] == x;
}

void solve() {
    i64 x;
    std::cin >> x;
    if (x == 1) {
        std::cout << 2 << "\n";
    } else if (x == 3) {
        std::cout << 4 << "\n";
    } else if (x == 7) {
        std::cout << 8 << "\n";
    } else if (x % 2 == 0) {
        if (is_prime(x - 3)) {
            std::cout << 2 * (x - 3) << "\n";
        } else {
            std::cout << (x - 1) * (x - 1) << "\n";
        }
    } else if (x % 2 == 1) {
        for (i64 i = 2; i <= x; i++) {
            i64 a = i, b = x - 1 - i;
            if (a >= b) {
                break;
            }
            if (is_prime(a) && is_prime(b)) {
                std::cout << a * b << "\n";
                return;
            }
        }
        std::cout << -1 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}