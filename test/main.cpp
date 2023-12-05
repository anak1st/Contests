#include <bits/stdc++.h>

using i64 = long long;

struct Point {
    int x = 0, y = 0;
};

Point operator+(Point a, Point b) {
    return {a.x + b.x, a.y + b.y};
}
Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

bool operator<(Point a, Point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<Point> p(n + 1);
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i];
        if (s[i] == 'U') {
            p[i + 1].y += 1;
        } else if (s[i] == 'D') {
            p[i + 1].y -= 1;
        } else if (s[i] == 'L') {
            p[i + 1].x -= 1;
        } else {
            p[i + 1].x += 1;
        }
    }
    
    std::map<Point, std::vector<int>> pos;
    for (int i = 0; i <= n; i++) {
        pos[p[i]].push_back(i);
    }
    
    auto get = [&](Point p, int l, int r) {
        if (!pos.contains(p)) {
            return false;
        }
        const auto &vec = pos[p];
        auto it = std::lower_bound(vec.begin(), vec.end(), l);
        return it != vec.end() && *it <= r;
    };
    
    while (q--) {
        int x, y, l, r;
        std::cin >> x >> y >> l >> r;
        l--;
        if (get(Point{x, y}, 0, l) || get(Point{x, y}, r, n) || get(p[l] + p[r] - Point{x, y}, l, r)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}