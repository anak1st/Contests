/**
 * @author: XiaFan
 * @date: 2023-01-26 07:35
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 1e7;
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();
    for (int i = 0; i <= 100; i++) {
        std::cerr << i << " " << std::boolalpha << is_prime(i) << "\n";
    }

    return 0;
}