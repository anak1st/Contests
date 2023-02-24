/**
 * @author: XiaFan
 * @date: 09-04 15:39
 **/
#include <bits/stdc++.h>

using i64 = long long;

struct Gen {
    unsigned int seed;
    std::mt19937 engine;
    Gen() : seed(std::random_device()()), engine(seed) {}
};
template <typename T> struct Randomer {
    Gen G;
    std::uniform_int_distribution<T> distribution;
    Randomer(T min, T max) : distribution(min, max) {}
    T operator()() {
        return distribution(G.engine);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 10;
    std::cout << t << "\n";
    while (t--) {
        int z = 10;
        Randomer<int> r1(100, 1000);
        Randomer<int> r2(1, 1000);
        Randomer<int> r3(0, 1000);
        std::cout << r1() << " " << r3() << " " << r3() << "\n";
        std::cout << r2() << " " << r3() << " " << r3() << "\n";
        std::cout << z << "\n";
    }

    return 0;
}