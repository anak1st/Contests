#include <algorithm>
#include <iostream>
#include <vector>

typedef long long i64;

struct score {
    int no;
    i64 v, w;
    double c;
    inline bool operator<(const score &ano) const {
        return c > ano.c;
    }
    inline void make(double x) {
        c = v - x * w;
    }
};

bool judge(int n, int k, double x, std::vector<score> &s) {
    // 100 * ai / bi >= x
    // 100 * ai - bi * x >= 0
    for(int i = 0; i < n; i++) {
        s[i].make(x);
    }
    std::sort(s.begin(), s.end());

    double cur = 0;
    for(int i = 0; i < k; i++) {
        cur += s[i].c;
    }
    // std::cerr << cur << ':' << mid << '\n';
    return cur >= 0;
}

void solve(int n, int k) {
    std::vector<score> s(n);
    for(int i = 0; i < n; i++) {
        s[i].no = i + 1;
        std::cin >> s[i].v >> s[i].w;
    }

    double left = 0, right = 1e9;
    while(right - left > 1e-6) {
        double mid = (left + right) / 2;
        if(judge(n, k, mid, s)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    // int ans = left * 100 + 0.5;
    // std::cout << ans << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << s[i].no << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    solve(n, k);

    return 0;
}