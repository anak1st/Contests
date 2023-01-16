/**
 * @author: XiaFan
 * @date: 2023-01-16 16:46
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr double eps = 1e-7;
int sign(double x) {
    return (x > eps) - (x < -eps);
}
bool equal(double x, double y) {
    return sign(x - y) == 0;
}
struct Vec2d {
    double x, y;
    Vec2d() : x(0), y(0) {}
    Vec2d(double x, double y) : x(x), y(y) {}
    friend Vec2d operator+(const Vec2d &lhs, const Vec2d &rhs) {
        return Vec2d(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vec2d operator-(const Vec2d &lhs, const Vec2d &rhs) {
        return Vec2d(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend bool operator==(const Vec2d &lhs, const Vec2d &rhs) {
        return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
    }
    friend bool operator<(const Vec2d &lhs, const Vec2d &rhs) {
        return sign(lhs.x - rhs.x) < 0 ||
              (sign(lhs.x - rhs.x) == 0 && sign(lhs.y - rhs.y) < 0);
    }
    double norm() const {
        return std::sqrt(x * x + y * y);
    }
};
double dot(const Vec2d &lhs, const Vec2d &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
double cross(const Vec2d &lhs, const Vec2d &rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

void solve() {
    Vec2d A, B, C;
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    Vec2d D, E, F;
    std::cin >> D.x >> D.y >> E.x >> E.y >> F.x >> F.y;
    Vec2d BA = A - B;
    Vec2d BC = C - B;
    Vec2d ED = D - E;
    Vec2d EF = F - E;
    if (equal(BA.norm(), BC.norm())) {
        std::cout << "NO\n";
        return;
    }
    if (!equal(BA.norm(), ED.norm())) {
        std::swap(ED, EF);
    }
    // std::cerr << "1 " << BA.norm() << " " << BC.norm() << "\n";
    // std::cerr << "2 " << ED.norm() << " " << EF.norm() << "\n";
    // std::cerr << "3 " << cross(BA, BC) << " " << cross(ED, EF) << "\n";
    if (!equal(cross(BA, BC), cross(ED, EF))) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}