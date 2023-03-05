#pragma once
#include "XCPC.h"

// const double pi = std::acos(-1.0);
constexpr double pi = std::numbers::pi;

// The Law of Cosines
double cosine_law(double a, double b, double c) {
    return std::acos((a * a + b * b - c * c) / (2 * a * b));
}

struct Circle {
    double x, y, r;
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}

    double area() const {
        return r * r * pi;
    }
    double area(double theta) const {
        return r * r * theta / 2;
    }
};

double distance(const Circle &lhs, const Circle &rhs) {
    double dx = lhs.x - rhs.x;
    double dy = lhs.y - rhs.y;
    return std::hypot(dx, dy);
}

double overlap(const Circle &lhs, const Circle &rhs) {
    double d = distance(lhs, rhs);
    if (d >= lhs.r + rhs.r) return 0;
    if (d <= std::abs(lhs.r - rhs.r)) {
        double r = std::min(lhs.r, rhs.r);
        return r * r * pi;
    }
    double alph = cosine_law(lhs.r, d, rhs.r);
    double beta = cosine_law(rhs.r, d, lhs.r);
    double high = lhs.r * std::sin(alph);
    double s = lhs.area(alph * 2) + rhs.area(beta * 2) - d * high;
    return s;
}