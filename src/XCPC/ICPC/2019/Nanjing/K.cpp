#include <bits/stdc++.h>


using f64 = long double;
using i64 = long long;

// constexpr f64 eps = 1e-6;
// int sign(f64 x) {
//     return (x > eps) - (x < -eps);
// }
// bool equal(f64 x, f64 y) {
//     return sign(x - y) == 0;
// }


struct P {
    i64 x, y;
    P() : x(0), y(0) {}
    P(i64 xx, i64 yy) : x(xx), y(yy) {}

    friend P operator+(const P &lhs, const P &rhs) {
        return P(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    friend P operator-(const P &lhs, const P &rhs) {
        return P(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    // friend P operator*(const P &lhs, double x) {
    //     return P(lhs.x * x, lhs.y * x);
    // }
    
    // friend P operator*(double x, const P &rhs) {
    //     return P(rhs.x * x, rhs.y * x);
    // }

    friend bool operator==(const P &lhs, const P &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    f64 norm() {
        return std::hypot(x, y);
    }
};

// f64 dot(const P &lhs, const P &rhs) {
//     return lhs.x * rhs.x + lhs.y * rhs.y;
// }
f64 cross(const P &lhs, const P &rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

// f64 S(P a, P b, P c) {
//     P ab = b - a;
//     P bc = c - b;
//     P ca = a - c;
//     f64 lab = ab.norm();
//     f64 lbc = bc.norm();
//     f64 lca = ca.norm();

//     // sqrt(d * (d - a) * (d - b) * (d - c))
//     f64 x = (lab + lbc + lca) / 2;

//     return std::sqrt(x * (x - lab) * (x - lbc) * (x - lca));
// }

f64 len(const P &a, const P &b) {
    return (a - b).norm();
}


int judge(const P &a, const P &b, const P &x) {
    auto ab = b - a;
    auto ax = x - a;

    if (cross(ab, ax)) {
        return -1;
    }
    if (ab.x * ax.x < 0 || ab.y * ax.y < 0) {
        return -1;
    }
    if (std::abs(ab.x) < std::abs(ax.x)) {
        return -1;
    }
    if (std::abs(ab.y) < std::abs(ax.y)) {
        return -1;
    }

    return 0;
}


void solve() {
    std::vector<P> p(4);

    for (int i = 0; i < 4; i++) {
        std::cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < 3; i++) {
        const P &a = p[i];
        const P &b = p[(i + 1) % 3];
        const P &c = p[(i + 2) % 3];
        const P &x = p[3];

        f64 ab = len(a, b);
        f64 ac = len(a, c);
        f64 bc = len(b, c);
        f64 ax = len(a, x);
        f64 bx = len(b, x);

        if (judge(a, b, x)) {
            continue;
        }
        // x 在 ab 上
        
        // 1. 找 bc
        if (x != b && ab <= bx * 2) {
            f64 yx = b.x + ab * (c - b).x / bx / 2;
            f64 yy = b.y + ab * (c - b).y / bx / 2;
            std::cout << std::fixed << std::setprecision(15);
            std::cout << yx << " " << yy << "\n";
            return;
        }

        // 2. 找 ac
        if (ab <= ax * 2) {
            f64 yx = a.x + ab * (c - a).x / ax / 2;
            f64 yy = a.y + ab * (c - a).y / ax / 2;
            std::cout << std::fixed << std::setprecision(15);
            std::cout << yx << " " << yy << "\n";
            return;
        }
    }

    std::cout << -1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}