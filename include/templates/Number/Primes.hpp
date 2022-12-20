#pragma once

#include <vector>

namespace pre {

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

}  // namespace pre
