/**
 * @author: XiaFan
 * @date: 2023-01-20 13:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr double eps = 1e-7;
constexpr double pi = 3.141592653;

int sign(double x) {
    return (x > eps) - (x < -eps);
}
bool equal(double x, double y) {
    return sign(x - y) == 0;
}
// Vector for 2rank & double
struct Vector2d {
    double x, y;
    Vector2d() : x(0), y(0) {}
    Vector2d(double x, double y) : x(x), y(y) {}
    friend bool operator==(const Vector2d &lhs, const Vector2d &rhs) {
        return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
    }
    friend bool operator<(const Vector2d &lhs, const Vector2d &rhs) {
        Vector2d tmp = lhs - rhs;
        return sign(tmp.x) < 0 || (sign(tmp.x) == 0 && sign(tmp.y) < 0);
    }
    friend Vector2d operator+(const Vector2d &lhs, const Vector2d &rhs) {
        return Vector2d(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vector2d operator-(const Vector2d &lhs, const Vector2d &rhs) {
        return Vector2d(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    double norm() const {
        return std::sqrt(x * x + y * y);
    }
    Vector2d rotate(double radian, Vector2d p = Vector2d(0, 0)) {
        Vector2d tmp = p;
        Vector2d v = *this - p;
        tmp.x += v.x * std::cos(radian) - v.y * std::sin(radian);
        tmp.y += v.x * std::sin(radian) + v.y * std::cos(radian);
        return tmp;
    }
};
double dot(const Vector2d &lhs, const Vector2d &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
double cross(const Vector2d &lhs, const Vector2d &rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}
double dis(const Vector2d &lhs, const Vector2d &rhs) {
    return (lhs - rhs).norm();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 xa, ya, xb, yb;
    std::cin >> xa >> ya >> xb >> yb;
    i64 dx = std::abs(xb - xa), dy = std::abs(yb - ya);
    if ((dx % 2) != (dy % 2)) {
        std::cout << "No Answer!\n";
        return 0;
    }
    double xm = (xa + xb) / 2.0, ym = (ya + yb) / 2.0;
    Vector2d P(xm, ym);
    Vector2d A(xa, ya);
    // std::cout << P.x << " " << P.y << "\n";
    Vector2d C = A.rotate(pi / 2, P);
    std::cout << (i64)std::round(C.x) << " " << (i64)std::round(C.y) << "\n";

    return 0;
}