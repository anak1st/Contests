/**
 * @author: XiaFan
 * @date: 2023-01-18 13:00
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

i64 fun(i64 n, i64 x) {
    return n / x + x - 1;
}
i64 get_min(i64 n) {
    i64 L = sqrt(n) - sqrt(sqrt(n)) * 2;
    L = std::max(L, 1LL);
    i64 R = sqrt(n);
    R = std::max(R, 100LL);
    i64 ansx = L;
    for (i64 x = L; x <= R; x++) {
        if (fun(n, x) < fun(n, ansx)) {
            ansx = x;
        }
    }
    if (ansx == L) {
        return -1;
    }
    if (ansx == R) {
        return -2;
    }
    return ansx;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x;
    std::cin >> x;
    std::cout << get_min(x) << "\n";

    return 0;
}