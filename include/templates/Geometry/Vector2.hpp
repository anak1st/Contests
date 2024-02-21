#pragma once
#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-7;

constexpr int sign(double x) { return (x > eps) - (x < -eps); }
constexpr bool equal(double x, double y) { return sign(x - y) == 0; }
const double pi = std::acos(-1);

template <typename T>
struct Vector2 {
    T x, y;
    bool is_convex;
    Vector2() : Vector2(0, 0) {}
    Vector2(double x, double y) : x(x), y(y), is_convex(false) {}
    friend bool operator==(const Vector2 &lhs, const Vector2 &rhs) {
        if constexpr (std::is_integral_v<T>) {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        } else {
            return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
        }
    }
    friend Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs) {
        return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs) {
        return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend Vector2 operator-(const Vector2 &lhs) { return Vector2(-lhs.x, -lhs.y); }
    friend Vector2 operator/(const Vector2 &lhs, double rhs) {
        return Vector2(lhs.x / rhs, lhs.y / rhs);
    }
    double norm() const { return std::hypot(x, y); }
    friend double dot(const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    friend double cross(const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }
    i64 quadrant() {
        if (x >= 0 && y >= 0) return 0;
        if (x < 0 && y >= 0) return 1;
        if (x < 0 && y < 0) return 2;
        return 3;
    }
};

/// sort by angle
template <typename T>
bool cmp(const Vector2<T> &lhs, const Vector2<T> &rhs) {
    auto q1 = lhs.quadrant();
    auto q2 = rhs.quadrant;
    if (q1 != q2) {
        return q1 < q2;
    }
    return cross(lhs, rhs) > 0;
}

template <typename T>
double point_dis(const Vector2<T> &lhs, const Vector2<T> &rhs) {
    return (lhs - rhs).norm();
}

template <typename T>
double point_disx(Vector2<T> a, Vector2<T> b) {
    return std::abs(a.x - b.x);
}

template <typename T>
double point_disy(Vector2<T> a, Vector2<T> b) {
    return std::abs(a.y - b.y);
}

/// get the angle between two vectors
template <typename T>
double angle(Vector2<T> a, Vector2<T> b) {
    return std::acos(dot(a, b) / (a.norm() * b.norm()));
}

/// rotate a point around the origin
template <typename T>
Vector2<T> rotate90(Vector2<T> p, Vector2<T> o = Vector2<T>(0, 0)) {
    Vector2<T> tmp = o;
    Vector2<T> v = p - o;
    tmp.x -= v.y;
    tmp.y += v.x;
    return tmp;
}