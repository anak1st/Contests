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
    
    int t = 10;
    std::cout << t << "\n";
    for (int i = 0; i < t; i++) {
        Randomer<i64> a(1, 2);
        for (int i = 0; i < 8; i++) {
            std::cout << a();
        }
        std::cout << " ";
        for (int i = 0; i < 8; i++) {
            std::cout << a();
        }
        std::cout << "\n";
    }

    return 0;
}