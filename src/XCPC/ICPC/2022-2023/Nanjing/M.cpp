/**
 * @author: XiaFan
 * @date: 2023-10-24 20:31
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-7;

int sign(double x) {
    return (x > eps) - (x < -eps);
}
bool equal(double x, double y) {
    return sign(x - y) == 0;
}
const double pi = std::acos(-1);


struct Vector2 {
    double x, y;
    Vector2() : x(0), y(0) {}
    Vector2(double x, double y) : x(x), y(y) {}
    friend bool operator==(const Vector2 &lhs, const Vector2 &rhs) {
        return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
    }
    friend Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs) {
        return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs) {
        return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend Vector2 operator-(const Vector2 &lhs) {
        return Vector2(-lhs.x, -lhs.y);
    }
    friend Vector2 operator/(const Vector2 &lhs, double rhs) {
        return Vector2(lhs.x / rhs, lhs.y / rhs);
    }
    friend double dot(const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    friend double cross(const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }
    double norm() const {
        return std::hypot(x, y);
    }
    double norm2() const {
        return x * x + y * y;
    }
    Vector2 normalize() const {
        return *this / norm();
    }
    Vector2 rotate90(Vector2 p = Vector2(0, 0)) {
        Vector2 tmp = p;
        Vector2 v = *this - p;
        tmp.x -= v.y;
        tmp.y += v.x;
        return tmp;
    }
};

double point_dis(const Vector2 &lhs, const Vector2 &rhs) {
    return (lhs - rhs).norm();
}
double point_dis2(const Vector2 &lhs, const Vector2 &rhs) {
    return (lhs - rhs).norm2();
}
double point_disx(const Vector2 &lhs, const Vector2 &rhs) {
    return std::abs(lhs.x - rhs.x);
}
double point_disy(const Vector2 &lhs, const Vector2 &rhs) {
    return std::abs(lhs.y - rhs.y);
}
double angle(Vector2 a, Vector2 b) {
    return std::acos(dot(a, b) / (a.norm() * b.norm()));
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        std::cin >> x >> y;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[(i + 1) % n];
        auto [x3, y3] = a[(i + 2) % n];

        Vector2 v12 = Vector2(x2, y2) - Vector2(x1, y1);
        Vector2 v23 = Vector2(x3, y3) - Vector2(x2, y2);
        if (cross(v12, v23) <= 0) {
            continue;
        }

        while (x2 < x3 && y2 == y3) {
            i++;
            auto next = a[(i + 2) % n];
            x3 = next.first;
            y3 = next.second;
        }
        
        if (y2 < y1 && y2 < y3) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}