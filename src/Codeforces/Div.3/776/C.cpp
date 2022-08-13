#include <bits/stdc++.h>

#define ALL(NAME) NAME.begin(), NAME.end()

struct Point {
    int x;
    int w;
    int id;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<Point> p(m);
        for(int i = 0; i < m; i++) {
            std::cin >> p[i].x >> p[i].w;
            p[i].id = i + 1;
        }

        std::sort(ALL(p), [](Point a, Point b) {
            return a.w < b.w;
        });

        while((int)p.size() > 2 * n) {
            p.pop_back();
        }

        int sum = 0;
        for(auto it : p) {
            sum += it.w;
        }

        std::sort(ALL(p), [](Point a, Point b) {
            return a.x < b.x;
        });

        std::cout << sum << '\n';
        for(int i = 0, j = p.size() - 1; i < j; i++, j--) {
            std::cout << p[i].id << ' ' << p[j].id << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}