/**
 * @author: XiaFan
 * @date: 11-06 15:55
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

    T gen() {
        return distribution(engine);
    }
};

i64 f(i64 x, i64 l, i64 r) {
    if (x < l) {
        x = l;
    }
    if (x > r) {
        x = r;
    }
    return x;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int limit = 10000;
    Randomer<int> r(-limit, limit);
    
    int n, d;
    std::cin >> n >> d;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        // a[i] = r.gen();
    }

    auto get_sum = [&](i64 l, i64 r) -> i64 {
        std::vector<i64> b(a);
        for (int i = 0; i < n; i++) {
            b[i] = f(b[i], l, r);
        }

        i64 tmp = 0;
        for (int i = 0; i < n - 1; i++) {
            tmp += std::abs(b[i] - b[i + 1]);
        }
        return tmp;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, get_sum(a[i], a[i] + d));
        ans = std::max(ans, get_sum(a[i] - d, a[i]));
    }
    std::cout << ans << "\n";
    
    i64 real = 0;
    for (int i = -limit; i <= limit; i++) {
        real = std::max(ans, get_sum(i, i + d));
        real = std::max(ans, get_sum(i - d, i));
    }
    std::cout << std::boolalpha << (real == ans) << "\n";
    
    return 0;
}