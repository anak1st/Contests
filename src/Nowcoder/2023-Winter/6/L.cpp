/**
 * @author: XiaFan
 * @date: 2023-02-03 15:25
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 P = 1e9 + 7;
template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <i64 Mod> struct MintBase {
    i64 v;
    i64 M() const {
        if constexpr (Mod <= 0) {
            return P;
        } else {
            return Mod;
        }
    }
    i64 norm(i64 x) const {
        x %= M();
        if (x < 0) {
            x += M();
        }
        return x;
    }
    MintBase() : v(0) {}
    MintBase(i64 x) : v(norm(x)) {}
    i64 val() const {
        return v;
    }
    MintBase operator-() const {
        return MintBase(norm(M() - v));
    }
    MintBase inv() const {
        assert(v != 0);
        return power(*this, M() - 2);
    }
    MintBase &operator+=(const MintBase &rhs) {
        v = norm(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = norm(v - rhs.v);
        return *this;
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = norm(v * rhs.v);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) {
        return *this *= rhs.inv();
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
    friend MintBase operator+(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res += rhs;
        return res;
    }
    friend MintBase operator-(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res -= rhs;
        return res;
    }
    friend MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a = MintBase(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
};
using Mint = MintBase<0>;

std::vector<Mint> fact, invfact;
void init(int size) {
    fact.resize(size + 1);
    invfact.resize(size + 1);
    fact[0] = 1;
    for (int i = 1; i <= size; i++) {
        fact[i] = fact[i - 1] * i;
    }
    invfact[size] = fact[size].inv();
    for (int i = size; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i;
    }
}
Mint A(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k];
}
Mint C(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[n - k] * invfact[k];
}

Mint fun(i64 x1, i64 y1, i64 x2, i64 y2) {
    return C(x2 - x1 + y2 - y1, x2 - x1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> bad;
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        bad.emplace_back(x, y);
    }

    init(n * 2);

    std::vector<Mint> two(n + 1);
    two[1] = 1;
    for (int i = 2; i <= n; i++) {
        two[i] = two[i - 1] * 2;
    }

    Mint ans = two[n];

    auto check = [&](const std::vector<std::pair<int, int>> &v) {
        int tm = v.size();
        for (int i = 0; i < tm - 1; i++) {
            int j = i + 1;
            if (v[i].first > v[j].first) {
                return false;
            }
            if (v[i].second > v[j].second) {
                return false;
            }
        }
        return true;
    };

    Mint sub = 0;
    int T = (1 << m) - 1;
    for (int t = 1; t <= T; t++) {
        std::vector<std::pair<int, int>> v;
        v.emplace_back(1, 1);
        for (int j = 0; j < m; j++) {
            if (t >> j & 1) {
                v.push_back(bad[j]);
            }
        }
        std::sort(v.begin(), v.end());
        int tm = v.size();
        if (!check(v)) continue;
        int dist = n + 1 - v.back().first - v.back().second + 1;
        Mint tmp = two[dist];
        for (int i = 0; i < tm - 1; i++) {
            int j = i + 1;
            tmp *= fun(v[i].first, v[i].second, v[j].first, v[j].second);
        }
        int flag = 1;
        if (tm % 2) {
            flag = -1;
        }
        // std::cerr << flag << " " << tmp << "\n";
        sub += flag * tmp;
    }
    // std::cerr << "final: " << ans << " " << sub << "\n";
    ans -= sub;
    std::cout << ans << "\n";

    return 0;
}