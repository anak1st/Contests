/**
 * @author: XiaFan
 * @date: 2023-01-28 21:47
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> struct Randomer {
    unsigned int seed;
    std::mt19937 engine;
    std::uniform_int_distribution<T> distribution;
    Randomer(T min, T max)
        : seed(std::random_device()()), engine(seed), distribution(min, max) {}
    T operator()() {
        return distribution(engine);
    }
};

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

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    init();

    Randomer<i64> R2(1, 1e10);
    i64 t = 1e4;
    std::cout << t << std::endl;
    
    while (t--) {
        i64 n;
        do {
            n = R2();
        } while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0);

        std::cout << n << std::endl;
    }

    return 0;
}