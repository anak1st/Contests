#pragma once
#include <bits/stdc++.h>

using i64 = long long;
#include "Vector2.hpp"

struct Segment {
    // a is the start point, b is the end point
    Vector2<double> a, b;
    Segment(Vector2<double> a, Vector2<double> b) : a(a), b(b) {}

    /// Get the distance from a point to a segment
    double dis_to_point(Vector2<double> p) {
        auto v1 = b - a;
        auto v2 = p - a;
        double x = dot(v1 / v1.norm(), v2);
        double h = std::sqrt(v2.x * v2.x + v2.y * v2.y - x * x);
        
        double alpha = angle(p - a, b - a);
        double betaa = angle(p - b, a - b);
        if (alpha > pi / 2 || betaa > pi / 2) {
            return std::min(point_dis(a, p), point_dis(b, p));
        }
        
        return h;
    }
};