/**
 * @author: XiaFan
 * @date: 2023-08-25 20:00
 */
#include <bits/stdc++.h>

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
    friend double dot(const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    friend double cross(const Vector2 &lhs, const Vector2 &rhs) {
        return lhs.x * rhs.y - lhs.y * rhs.x;
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

struct Polygon {
    std::vector<Vector2> p;
    Polygon(const std::vector<Vector2> &_p) : p(_p) {}

    bool get_in(Vector2 x) {
        int n = p.size();
        int cnt[3] = {};
        for (int i = 0; i < n; i++) {
            Vector2 a = p[i], b = p[(i + 1) % n];
            Vector2 v1 = b - a, v2 = x - a;
            cnt[1 + sign(cross(v1, v2))] += 1;
        }
        return cnt[0] == n || cnt[2] == n;
    }
};

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    i64 r;
    std::cin >> r;
    std::vector<Vector2> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i].x >> b[i].y;
    }

    int cnt = 0;

    for (auto &v : a) {
        bool ok = true;

        for (int i = 0; i < m - 1; i++) {
            Vector2 v1 = b[i];
            Vector2 v2 = b[i + 1];
            Vector2 vd = v2 - v1;
            Vector2 v3 = v1 + Vector2(vd.x, 0);
            Vector2 v4 = v1 + Vector2(0, vd.y);

            Polygon p({v1, v3, v2, v4});

            if (p.get_in(v)) {
                ok = false;
                //std::cerr << "get in!\n";
                break;
            }

            Segment s1(v1, v3);
            Segment s2(v1, v4);
            Segment s3(v3, v2);
            Segment s4(v4, v2);

            double dis = 1e18;
            dis = std::min(dis, s1.dis_to_point(v));
            dis = std::min(dis, s2.dis_to_point(v));
            dis = std::min(dis, s3.dis_to_point(v));
            dis = std::min(dis, s4.dis_to_point(v));

            if (dis < r) {
                ok = false;
                //std::cerr << "dis!\n";
                break;
            }
        }

        if (ok) {
            cnt++;
        }
    }
    
    if (cnt > 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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