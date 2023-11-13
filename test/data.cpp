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

    Randomer<i64> R1(1, 3);

    int t = 1;
    std::cout << t << "\n";
    while (t--) {
        std::cout << R1() << ' ' << R1() << "\n";
        std::cout << R1() << ' ' << R1() << "\n";
        std::cout << R1() << ' ' << R1() << "\n";
    }

    return 0;
}