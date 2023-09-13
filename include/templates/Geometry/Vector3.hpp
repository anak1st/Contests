#pragma once
#include "XCPC.h"


constexpr double eps = 1e-7;

int sign(double x) {
    return (x > eps) - (x < -eps);
}
bool equal(double x, double y) {
    return sign(x - y) == 0;
}

struct Vector3d {
    double x, y, z;

    Vector3d() : x(0), y(0), z(0) {}
    Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}
    friend bool operator==(const Vector3d &lhs, const Vector3d &rhs) {
        return equal(lhs.x, rhs.x) && equal(lhs.y, rhs.y);
    }
    double norm() const {
        return std::hypot(x, y, z);
    }
    friend Vector3d operator+(const Vector3d &lhs, const Vector3d &rhs) {
        return Vector3d(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }
    friend Vector3d operator-(const Vector3d &lhs, const Vector3d &rhs) {
        return Vector3d(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }
    friend double dot(const Vector3d &lhs, const Vector3d &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }
    friend Vector3d cross(const Vector3d &lhs, const Vector3d &rhs) {
        return Vector3d(lhs.y * rhs.z - lhs.z * rhs.y,
                        lhs.z * rhs.x - lhs.x * rhs.z,
                        lhs.x * rhs.y - lhs.y * rhs.x);
    }
};