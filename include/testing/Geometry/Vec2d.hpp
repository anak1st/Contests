#pragma once

constexpr double eps = 1e-9;

int sign(double x) {
    return (x > eps) - (x < -eps);
}

struct Vec2d {
    double x, y;
    
    Vec2d() : x(0), y(0) {}
    Vec2d(double x) : x(x), y(x) {}
    Vec2d(double x, double y) : x(x), y(y) {}

    friend Vec2d operator+(const Vec2d &lhs, const Vec2d &rhs) {
        return Vec2d(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vec2d operator-(const Vec2d &lhs, const Vec2d &rhs) {
        return Vec2d(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    friend bool operator==(const Vec2d &lhs, const Vec2d &rhs) {
        return sign(lhs.x - rhs.x) == 0 && sign(lhs.y - rhs.y) == 0;
    }
    friend bool operator<(const Vec2d &lhs, const Vec2d &rhs) {
        return sign(lhs.x - rhs.x) < 0 || (sign(lhs.x - rhs.x) == 0 && sign(lhs.y - rhs.y) < 0);
    }
};
