/**
 * @author: XiaFan
 * @date: 2023-11-12 13:52
 */
#include <bits/stdc++.h>

using i64 = long long;

struct Vector2 {
    i64 x, y;
    Vector2() : x(0), y(0) {}
    Vector2(i64 x, i64 y) : x(x), y(y) {}
    friend Vector2 operator-(const Vector2 &lhs) {
        return Vector2(-lhs.x, -lhs.y);
    }
};

i64 dot(const Vector2 &lhs, const Vector2 &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
i64 cross(const Vector2 &lhs, const Vector2 &rhs) {
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
i64 cmp(const Vector2 &lhs, const Vector2 &rhs) {
    auto q1 = quadrant(lhs);
    auto q2 = quadrant(rhs);
    if (q1 != q2) {
        return q1 < q2;
    }
    return cross(lhs, rhs) > 0;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Vector2> a(n);
    for (auto &[x, y] : a) {
        std::cin >> x >> y;
    }

    std::sort(a.begin(), a.end(), cmp);

    // std::cerr << "debug\n";
    // for (int i = 0; i < n; i++) {
    //     std::cerr << cross(a[i], a[(i + 1) % n]) << "\n";
    // }
    // for (auto &[x, y] : a) {
    //     std::cerr << x << " " << y << "\n";
    // }

    if (cross(a[0], a[n - 1]) >= 0) {
        std::cout << 0 << "\n";
        return;
    }

    auto b = a;
    b.insert(b.end(), a.begin(), a.end());

    int ans = n;
    for (int i = 0, j = 1; i < n; i++) {
        while (j + 1 < 2 * n && cross(-b[i], b[j + 1]) <= 0) {
            j++;
        }
        
        // std::cerr << "ans: " << i << " " << j << "\n";
        ans = std::min(ans, (j - i + n) % n);
    }

    std::cout << ans << "\n";
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