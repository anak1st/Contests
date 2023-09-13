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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Randomer<i64> R1(9e3, 1e4);
    Randomer<i64> R2(9e6, 1e14);
    i64 t = 1e4;
    std::cout << t << "\n";
    while (t--) {
        i64 n = 1e14 - 2;
        std::cout << n << "\n";
    }

    return 0;
}