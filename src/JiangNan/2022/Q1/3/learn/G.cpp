#include <algorithm>
#include <iostream>
#include <vector>

typedef long long i64;

struct score {
    i64 a, b;
};

bool judge(int n, int k, double mid, std::vector<score> &s) {
    // 100 * ai / bi >= x
    // 100 * ai - bi * x >= 0
    std::vector<double> c(n);
    for(int i = 0; i < n; i++) {
        c[i] = s[i].a - mid * s[i].b;
    }
    std::sort(c.rbegin(), c.rend());

    double cur = 0;
    for(int i = 0; i < (n - k); i++) {
        cur += c[i];
    }
    // std::cerr << cur << ':' << mid << '\n';
    return cur >= 0;
}

void solve(int n, int k) {
    std::vector<score> s(n);
    for(int i = 0; i < n; i++) {
        std::cin >> s[i].a;
    }
    for(int i = 0; i < n; i++) {
        std::cin >> s[i].b;
    }

    double left = 0, right = 1;
    while(right - left > 1e-6) {
        double mid = (left + right) / 2;
        if(judge(n, k, mid, s)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    int ans = left * 100 + 0.5;
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(1) {
        int n, k;
        std::cin >> n >> k;
        if(n == 0 && k == 0) {
            break;
        }
        solve(n, k);
    }

    return 0;
}