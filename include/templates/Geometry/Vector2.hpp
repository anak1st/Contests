#pragma once
#include "XCPC.h"

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

double dot(const Vector2 &lhs, const Vector2 &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
double cross(const Vector2 &lhs, const Vector2 &rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}
i64 quadrant(const Vector2 &v) {
    if (v.x >= 0 && v.y >= 0) {
        return 0;
    }
    if (v.x < 0 && v.y >= 0) {
        return 1;
    }
    if (v.x < 0 && v.y < 0) {
        return 2;
    }
    return 3;
}
bool cmp(const Vector2 &lhs, const Vector2 &rhs) {
    auto q1 = quadrant(lhs);
    auto q2 = quadrant(rhs);
    if (q1 != q2) {
        return q1 < q2;
    }
    return cross(lhs, rhs) > 0;
}

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

struct Segment {
    // a is the start point, b is the end point
    Vector2 a, b;
    Segment(Vector2 a, Vector2 b) : a(a), b(b) {}

    double dis_to_point(Vector2 p) {
        auto v1 = b - a;
        auto v2 = p - a;
        double x = dot(v1.normalize(), v2);
        double h = std::sqrt(v2.norm2() - x * x);
        
        double alpha = angle(p - a, b - a);
        double betaa = angle(p - b, a - b);
        if (alpha > pi / 2 || betaa > pi / 2) {
            return std::min(point_dis(a, p), point_dis(b, p));
        }
        
        return h;
    }
};