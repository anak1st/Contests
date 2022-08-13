#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    i64 C;
    std::cin >> n >> C;
    std::vector<i64> a(C + 1);
    for(int i = 1; i <= n; i++) {
        i64 c, d, h;
        std::cin >> c >> d >> h;
        a[c] = std::max(a[c], d * h);
    }

    for(int i = 1; i <= C; i++) {
        for(int j = 2; i * j <= C; j++) {
            a[i * j] = std::max(a[i * j], a[i] * j);
        }
    }

    for(int i = 1; i <= C; i++) {
        a[i] = std::max(a[i - 1], a[i]);
    }

    int m;
    std::cin >> m;
    while(m--) {
        i64 D, H;
        std::cin >> D >> H;

        i64 pos = std::upper_bound(a.begin(), a.end(), D * H) - a.begin();
        if(pos > C) {
            pos = -1;
        }
        std::cout << pos << ' ';
    }

    return 0;
}