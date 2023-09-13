/**
 * @author: XiaFan
 * @date: 09-04 15:39
 **/
#include <bits/stdc++.h>

using i64 = long long;

struct Gen {
    unsigned int seed;
    std::mt19937 engine;
    Gen() : seed{std::random_device{}()}, engine(seed) {}
};
template <typename T>
struct Randomer {
    Gen G;
    std::uniform_int_distribution<T> distribution;
    Randomer(T min, T max) : distribution(min, max) {}
    T operator()() { return distribution(G.engine); }
};


int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int t = 5;
    std::cout << t << std::endl;
    
    while (t--) {
        int n = 1000, m = 10;
        Randomer<int> r(1, 1e9);
        std::cout << n << " " << m << std::endl;
        std::cout << r() << std::endl;

        std::set<std::pair<int, int>> sn;
        for (int i = 0; i < n; i++) {
            int u, v;
            do {
                u = r();
                v = r();
            } while (sn.count({u, v}));
            sn.insert({u, v});
            std::cout << u << " " << v << std::endl;
        }

        std::set<std::pair<int, int>> sm;

        for (int i = 0; i < m; i++) {
            int u, v;
            do {
                u = r();
                v = r();
            } while (sm.count({u, v}));
            sm.insert({u, v});
            std::cout << u << " " << v << std::endl;
        }
    }

    return 0;
}