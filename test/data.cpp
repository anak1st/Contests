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

std::vector<i64> work(std::vector<i64> a, int x) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] = (a[i] + x) / 2;
    }
    return a;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Randomer<i64> R1(1, 3);

    int n = 10;
    std::vector<i64> a(n);
    std::iota(a.begin(), a.end(), 0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[j] << " \n"[j == n - 1];
        }
        a = work(a, 0);
    }

    std::cout << std::string(10, '-') << '\n';

    std::iota(a.begin(), a.end(), 0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[j] << " \n"[j == n - 1];
        }
        a = work(a, 1);
    }

    return 0;
}