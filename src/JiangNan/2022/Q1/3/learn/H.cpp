#include <algorithm>
#include <iostream>
#include <vector>

typedef long long i64;

struct cow {
    i64 weight;
    i64 strength;
    i64 risk;

    inline void calc_risk(i64 sum) {
        risk = sum - weight - strength;
    }
    inline bool operator<(const cow ano) const {
        return risk < ano.risk;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<cow> c(n);
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> c[i].weight >> c[i].strength;
        sum += c[i].weight;
    }

    for(int i = 0; i < n; i++) {
        c[i].calc_risk(sum);
    }
    std::sort(c.begin(), c.end());

    i64 cur = 0, ans = -10000000000;
    for(int i = 0; i < n; i++) {
        c[i].calc_risk(sum - cur);
        cur += c[i].weight;
        ans = std::max(ans, c[i].risk);
    }

    std::cout << ans << '\n';

    return 0;
}