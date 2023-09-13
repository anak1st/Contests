/**
 * @author: XiaFan
 * @date: 2023-08-21 19:09
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e7;
std::vector<int> primes;
int minp[N + 1];  // minp[i] = min prime factor of i
int num[N + 1];   // num[i] = number of prime factors of i
void init() {
    for (int i = 2; i <= N; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
            num[i] = 1;
        }
        for (auto p : primes) {
            if (i * p > N) break;
            minp[i * p] = p;
            num[i * p] = num[i] + 1;
            if (i % p == 0) break;
        }
    }
}
bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    return minp[x] == x;
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

void solve() {
    i64 n;
    std::cin >> n;
    // auto facts = get_facts(n);

    std::vector<i64> a;
    i64 x = n;
    for (auto p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            a.push_back(p);
            while (x % p == 0) {
                x /= p;
            }
        }
    }
    if (x > 1) {
        a.push_back(x);
    }

    i64 xsum = 0;
    for (auto x : a) {
        xsum ^= x;
    }

    std::cout << xsum << "\n";
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    init();

    int t = 1;
    std::cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}