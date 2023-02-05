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

    Randomer<int> R1(1, 1000);
    Randomer<int> R2(1, 60);
    int t = R1();
    std::cout << t << "\n";
    while (t--) {
        int n = R2(), m = R2();
        std::cout << n << " " << m << "\n";
        Randomer<int> R3(std::max(1, n / 2), n);
        for (int i = 1; i <= m; i++) {
            std::cout << R3() << " \n"[i == m];
        }
    }

    return 0;
}