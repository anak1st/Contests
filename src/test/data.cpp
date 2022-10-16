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
    
    int t = 100;
    std::cout << t << "\n";
    for (int i = 0; i < t; i++) {
        int n = 100;
        std::cout << n << "\n";
        Randomer<int> r1(0, 100);
        for (int j = 0; j < n; j++) {
            std::cout << r1() << " ";
        }
        std::cout << "\n";
    }

    return 0;
}