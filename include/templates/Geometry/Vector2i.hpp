#pragma once
#include "XCPC.h"

// Vector for 2rank & intger
struct Vector2i {
    i64 x, y;
    Vector2i() : x(0), y(0) {}
    Vector2i(double x, double y) : x(x), y(y) {}
    friend bool operator==(const Vector2i &lhs, const Vector2i &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
    friend bool operator<(const Vector2i &lhs, const Vector2i &rhs) {
        Vector2i tmp = lhs - rhs;
        return tmp.x < 0 || (tmp.x == 0 && tmp.y < 0);
    }
    friend Vector2i operator+(const Vector2i &lhs, const Vector2i &rhs) {
        return Vector2i(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Vector2i operator-(const Vector2i &lhs, const Vector2i &rhs) {
        return Vector2i(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    Vector2i rotate90(Vector2i p = Vector2i(0, 0)) {
        Vector2i tmp = p;
        Vector2i v = *this - p;
        tmp.x -= v.y;
        tmp.y += v.x;
        return tmp;
    }
};
i64 dis2(const Vector2i &lhs, const Vector2i &rhs) {
    Vector2i tmp = lhs - rhs;
    return tmp.x * tmp.x + tmp.y * tmp.y;
}
i64 disx(const Vector2i &lhs, const Vector2i &rhs) {
    return std::abs(lhs.x - rhs.x);
}
i64 disy(const Vector2i &lhs, const Vector2i &rhs) {
    return std::abs(lhs.y - rhs.y);
}