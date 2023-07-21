/**
 * @author: XiaFan
 * @date: 2023-07-09 17:22
 */
#include <bits/stdc++.h>

using i64 = long long;
template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}
template <i64 P>
struct MintBase {
    i64 v;
    i64 norm(i64 x) const {
        x %= P;
        if (x < 0) x += P;
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x)} {}
    i64 val() const { return v; }
    MintBase operator-() const { return MintBase(norm(P - v)); }
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
    MintBase &operator/=(const MintBase &rhs) { return *this *= rhs.inv(); }
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
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
};
constexpr i64 P = 998244353;
using Mint = MintBase<P>;

Mint fun(int x) {
    return 1 - Mint(1) / (1 << std::__lg(x + 1));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    // for (int i = 1; i <= 10; i++) {
    //     std::cout << i << ' ' << fun(i) << '\n';
    // }

    // double p = 1;
    // std::map<double, int> cnt;
    // for (int i = N; i < N + M; i++) {
    //     p *= fun(i);
    //     cnt[fun(i)]++;
    // }
    

    // for (auto [k, v] : cnt) {
    //     std::cout << k << ' ' << v << '\n';
    // }

    // std::cout << p << '\n';
    // std::cout << "---\n";

    i64 x = 2;
    i64 y = 2;
    while (y < N) {
        x = x * 2;
        y += x;
    }
    std::map<double, int> cnt2;
    Mint ans = 1;
    int n = N;
    while (y < N + M) {
        ans *= power(fun(n), y - n + 1);
        // std::cout << fun(n) << ' ' << y - n + 1 << '\n';
        n = y + 1;

        x = x * 2;
        y += x;
    }

    y = N + M - 1;
    ans *= power(fun(n), y - n + 1);
    // std::cout << fun(n) << ' ' << y - n + 1 << '\n';
    std::cout << ans << '\n';

    return 0;
}