/**
 * @author: XiaFan
 * @date: 2023-02-24 23:14
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 1e7;
std::vector<int> primes;
int minp[N + 1]; // minp[i] = min prime factor of i
int num[N + 1]; // num[i] = number of prime factors of i
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
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        ans ^= num[x];
    }
    if (ans) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
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