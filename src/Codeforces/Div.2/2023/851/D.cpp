/**
 * @author: XiaFan
 * @date: 2023-02-10 00:06
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <i64 P> struct MintBase {
    i64 v;
    i64 norm(i64 x) const {
        x %= P;
        if (x < 0) {
            x += P;
        }
        return x;
    }
    MintBase() : v(0) {}
    MintBase(i64 x) : v(norm(x)) {}
    i64 val() const {
        return v;
    }
    MintBase operator-() const {
        return MintBase(norm(P - v));
    }
    MintBase inv() const {
        assert(v != 0);
        return power(*this, P - 2);
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
constexpr i64 P = 1e9 + 7;
using Mint = MintBase<P>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> x[i];
    }
    Mint ans = 0;

    std::vector<Mint> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2;
    }

    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        for (int j = i + 1; j <= n; j++) {
            while (l >= 1 && x[i] - x[l] <= x[j] - x[i]) {
                l--;
            }
            while (r <= n && x[r] - x[j] < x[j] - x[i]) {
                r++;
            }
            ans += pw[l] * pw[n - r + 1];
        }
    }
    
    std::cout << ans;

    return 0;
}