/**
 * @author: XiaFan
 * @date: 09-04 15:39
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T>
class Randomer {
private:
    unsigned int seed;
    std::mt19937 engine;
    std::uniform_int_distribution<T> distribution;

public:
    Randomer(T min, T max)
    : seed(std::random_device()()), engine(seed), distribution(min, max) {}

    T operator()() { return distribution(engine); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cout << t << "\n";
    while (t--) {
        int n = 100;
        std::cout << n << "\n";
        Randomer<i64> R(1E5, 1E6);
        for (int i = 0; i < n; i++) {
            int x = R();
            int y = x + R();
            std::cout << x << " " << y << "\n";
        }
    }

    return 0;
}