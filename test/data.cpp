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

    int t = 1;
    std::cout << t << "\n";
    while (t--) {
        int n = 2e5, k = 2e5;
        std::cout << n << " " << k << "\n";
        std::string s(n, 'a');
        std::cout << s << "\n";
    }

    return 0;
}