#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
int dist(point a, point b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<point> a(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> a[i].x >> a[i].y;
    }

    for(int i = 0; i < n; i++) {
        bool cur = true;
        for(int j = 0; j < n; j++) {
            if(dist(a[i], a[j]) > k) {
                cur = false;
                break;
            }
        }
        if(cur) {
            std::cout << 1 << "\n";
            return;
        }
    }
    std::cout << -1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}