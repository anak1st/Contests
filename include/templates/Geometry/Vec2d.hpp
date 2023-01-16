#pragma once
#include "XCPC.h"

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
    friend bool operator==(const Vec2d &lhs, const Vec2d &rhs) {
        return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
    }
    friend bool operator<(const Vec2d &lhs, const Vec2d &rhs) {
        Vec2d tmp = lhs - rhs;
        return sign(tmp.x) < 0 || (sign(tmp.x) == 0 && sign(tmp.y) < 0);
    }
    friend Vec2d operator+(const Vec2d &lhs, const Vec2d &rhs) {
        return Vec2d(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vec2d operator-(const Vec2d &lhs, const Vec2d &rhs) {
        return Vec2d(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    double norm() const {
        return std::sqrt(x * x + y * y);
    }
    Vec2d rotate(double radian, Vec2d p = Vec2d(0, 0)) {
        Vec2d tmp = p;
        Vec2d v = *this - p;
        tmp.x += v.x * std::cos(radian) - v.y * std::sin(radian);
        tmp.y += v.x * std::sin(radian) + v.y * std::cos(radian);
        return tmp;
    }
};
double dot(const Vec2d &lhs, const Vec2d &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
double cross(const Vec2d &lhs, const Vec2d &rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}
double dis(const Vec2d &lhs, const Vec2d &rhs) {
    return (lhs - rhs).norm();
}
