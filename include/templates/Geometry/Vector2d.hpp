#pragma once
#include "XCPC.h"

constexpr double eps = 1e-7;

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
        return tmp.x < 0 || (tmp.x == 0 && tmp.y < 0);
    }
    friend Vector2d operator+(const Vector2d &lhs, const Vector2d &rhs) {
        return Vector2d(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vector2d operator-(const Vector2d &lhs, const Vector2d &rhs) {
        return Vector2d(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    double norm() const {
        return std::hypot(x, y);
    }
    /// @brief rotate by radian around point p
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
double disx(const Vector2d &lhs, const Vector2d &rhs) {
    return std::abs(lhs.x - rhs.x);
}
double disy(const Vector2d &lhs, const Vector2d &rhs) {
    return std::abs(lhs.y - rhs.y);
}