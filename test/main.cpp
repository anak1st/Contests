/**
 * @author: XiaFan
 * @date: 2023-09-24 23:15
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
template <int P>
struct MintBase {
    int v;
    int norm(int x) const {
        if (x >= P) x -= P;
        if (x < 0) x += P;
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x % P)} {}
    int val() const { return v; }
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
        v = norm(1LL * v * rhs.v % P);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) { 
        return *this *= rhs.inv(); 
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
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
};
constexpr int P = 998244353;
using Mint = MintBase<P>;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> xsum(n + 1);
    for (int i = 0; i < n; ++i) {
        xsum[i + 1] = xsum[i] ^ a[i];
    }

    Mint ans = 0;
    for (int z = 0; z < 30; z++) {
        Mint sum[2];
        Mint num[2];
        for (int i = 0; i <= n; i++) {
            int bit = xsum[i] >> z & 1;
            
            ans += (i * num[!bit] - sum[!bit]) * (1LL << z);

            num[bit] += 1;
            sum[bit] += i;
        }
    }
    std::cout << ans << '\n';

    return 0;
}