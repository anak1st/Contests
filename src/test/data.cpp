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

constexpr int P = 1e9 + 7;
char itoc(int x) {
    if (x < 10) {
        return '0' + x;
    } else if (x < 10 + 26) {
        return 'a' + x - 10;
    } else {
        return 'A' + x - 10 - 26;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // int t = 10;
    // std::cout << t << "\n";
    
    constexpr i64 Len = 1000000;
    Randomer<i64> R(0, 61);
    for (int i = 0; i < Len; i++) {
        std::cout << itoc(R());
    }

    return 0;
}