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
    std::cout << t << "\n";
    while (t--) {
        int n = 6;
        std::cout << n << "\n";
        std::vector<int> a(n);
        std::iota(a.begin(), a.end(), 1);
        std::shuffle(a.begin(), a.end(), std::mt19937(std::random_device()()));
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}