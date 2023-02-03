/**
 * @author: XiaFan
 * @date: 09-04 15:39
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

    Randomer<int> R(1, 50);
    std::cout << R() << " " << R() << std::endl;

    return 0;
}