#include <bits/stdc++.h>

using i64 = long long;

struct vector2d {
    double x, y;
    vector2d(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    friend std::ostream &operator<<(std::ostream &os, vector2d &v) {
        os << "(x:" << v.x << ",y:" << v.y << ")";
        return os;
    }

    double norm() {
        return std::sqrt(x * x + y * y);
    }

    friend bool operator==(const vector2d &lhs, const vector2d &rhs) {
        return (lhs - rhs).norm() < 1e-8;
    }

    friend vector2d operator+(const vector2d &lhs, const vector2d &rhs) {
        return vector2d(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend vector2d operator-(const vector2d &lhs, const vector2d &rhs) {
        return vector2d(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    friend double operator*(const vector2d &lhs, const vector2d &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    friend double operator^(const vector2d &lhs, const vector2d &rhs) {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector2d point[3];
    for(int i = 0; i < 3; i++) {
        std::cin >> point[i].x >> point[i].y;
    }
    int p = -2;
    for(int i = 0; i < 3; i++) {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;
        vector2d v1 = point[i] - point[j];
        vector2d v2 = point[i] - point[k];
        if((v1 * v2) < 1e-8) {
            p = i;
        }
    }
    int a = p;
    int b = (p + 1) % 3;
    int c = (p + 2) % 3;
    vector2d ans = point[b] + point[c] - point[a];
    std::cout << ans.x << " " << ans.y << "\n";

    return 0;
}
