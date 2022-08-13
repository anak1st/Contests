#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

using i64 = long long;

template <typename T> struct edge {
    int a, b;
    T c;
    edge() : a(0), b(0), c(0) {}
    edge(int a_, int b_, T c_) : a(a_), b(b_), c(c_) {}
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};

template <typename T> struct point {
    T x, y;
    point() : x(0), y(0) {}
    point(T x_, T y_) : x(x_), y(y_) {}
};

template <typename T> double dis(point<T> a, point<T> b) {
    double x = abs(a.x - b.x);
    double y = abs(a.y - b.y);
    return sqrt(x * x + y * y);
}
