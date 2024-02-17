/**
 * @author: XiaFan
 * @date: 2024-01-21 14:01
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-7;

struct Vector2 {
    i64 x, y;
    bool is_convex;
    Vector2() : Vector2(0, 0) {}
    Vector2(i64 x, i64 y) : x(x), y(y), is_convex(false) {}
    friend bool operator==(const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
    friend Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs) {
        return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs) {
        return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend Vector2 operator-(const Vector2 &lhs) { return Vector2(-lhs.x, -lhs.y); }
};
double dot(const Vector2 &lhs, const Vector2 &rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
double cross(const Vector2 &lhs, const Vector2 &rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }
i64 quadrant(const Vector2 &v) {
    if (v.x >= 0 && v.y >= 0) return 0;
    if (v.x < 0 && v.y >= 0) return 1;
    if (v.x < 0 && v.y < 0) return 2;
    return 3;
}
bool cmp(const Vector2 &lhs, const Vector2 &rhs) {
    auto q1 = quadrant(lhs);
    auto q2 = quadrant(rhs);
    if (q1 != q2) return q1 < q2;
    return cross(lhs, rhs) > 0;
}

void Convex_Andrew(std::vector<Vector2> &p) {
    std::sort(p.begin(), p.end(), [](const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
    });
    std::vector<int> res;
    for (int i = 0; i < p.size(); i++) {
        while (res.size() >= 2 && cross(p[i] - p[res[res.size() - 2]], p[res[res.size() - 1]] - p[res[res.size() - 2]]) <= 0) {
            res.pop_back();
        }
        res.push_back(i);
    }
    int t = res.size();
    for (int i = p.size() - 2; i >= 0; i--) {
        while (res.size() > t && cross(p[i] - p[res[res.size() - 2]], p[res[res.size() - 1]] - p[res[res.size() - 2]]) <= 0) {
            res.pop_back();
        }
        res.push_back(i);
    }
    res.pop_back();
    for (int i = 0; i < res.size(); i++) p[res[i]].is_convex = true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Vector2> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].x >> p[i].y;
    }

    // std::stable_sort(p.begin(), p.end(), cmp);
    // for (int i = 0; i < n; i++) {
    //     std::cerr << i << ": " <<  p[i].x << " " << p[i].y << "\n";
    // }

    Convex_Andrew(p);
    int ans = 1;

    for (int i = 0; i < p.size(); i++) {
        if (p[i].is_convex) {
            continue;
        }

        std::vector<Vector2> p_copy;
        for (int j = 0; j < p.size(); j++) {
            if (j == i) continue;
            auto v = p[j] - p[i];
            v.is_convex = p[j].is_convex;
            p_copy.push_back(v);
        }

        std::stable_sort(p_copy.begin(), p_copy.end(), cmp);

        for (int j = 0; j < p_copy.size(); j++) {
            int k = (j + 1) % p_copy.size();
            if (p_copy[j].is_convex && p_copy[k].is_convex) {
                ans++;
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}