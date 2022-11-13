/**
 * @author: XiaFan
 * @date: 09-04 15:39
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> class Randomer {
private:
    unsigned int seed;
    std::mt19937 engine;
    std::uniform_int_distribution<T> distribution;

public:
    Randomer(T min, T max)
    : seed(std::random_device()()), 
      engine(seed), distribution(min, max) 
    {}

    T operator()() {
        return distribution(engine);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n = 10000;
    std::cout << n << "\n";

    Randomer R(1, n);
    std::cout << R() << " " << 10 << "\n";

    Randomer R1(1, n * 2), R2(n * 3, n * 4);
    for (int i = 0; i < 10; i++) {
        std::cout << R1() << " " << R2() << " \n";
    }

    return 0;
}