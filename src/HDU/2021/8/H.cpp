/**
 * @author: XiaFan
 * @date: 2023-02-24 22:15
 **/
#include <bits/stdc++.h>
using i64 = long long;

const double pi = std::acos(-1.0);

// The Law of Cosines
double cosine_law(double a, double b, double c) {
    return std::acos((a * a + b * b - c * c) / (2 * a * b));
}

struct circle {
    double x, y, r;
    
    double area() const {
        return r * r * pi;
    }

    double area(double theta) const {
        return r * r * theta / 2;
    }
};

double dis(const circle &lhs, const circle &rhs) {
    double dx = lhs.x - rhs.x;
    double dy = lhs.y - rhs.y;
    return std::hypot(dx, dy);
}

double overlap(const circle &lhs, const circle &rhs) {
    double d = dis(lhs, rhs);
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

void solve() {
    circle a, b;
    std::cin >> a.r >> a.x >> a.y;
    std::cin >> b.r >> b.x >> b.y;
    double z;
    std::cin >> z;

    std::cout << std::fixed << std::setprecision(6);

    a.r = std::sqrt(a.r * a.r - (z / 2) * (z / 2)) - (z / 2);
    if (b.r * b.r - (z / 2) * (z / 2) <= 0) {
        std::cout << 0.0 << "\n";
        return;
    }
    b.r = std::sqrt(b.r * b.r - (z / 2) * (z / 2)) - (z / 2);

    std::cout << overlap(a, b) / a.area() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}