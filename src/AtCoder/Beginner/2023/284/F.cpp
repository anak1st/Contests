/**
 * @author: XiaFan
 * @date: 2023-01-07 22:12
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int P = 1e9 + 7;
template <typename T> T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <int Mod> struct MintBase {
    int _x;
    int M() const {
        if (Mod <= 0) return P;
        else return Mod;
    }
    // assume -M <= __x < 2 M
    int mod(int x) const {
        if (x < 0) x += M();
        if (x >= P) x -= M();
        return x;
    }
    MintBase() : _x(0) {}
    MintBase(int x) : _x(mod(x)) {}
    MintBase(i64 x) : _x(mod(x % M())) {}
    int val() const { return _x; }
    MintBase operator-() const { return MintBase(mod(M() - _x)); }
    MintBase inv() const {
        assert(_x != 0);
        return power(*this, M() - 2);
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs._x == rhs._x;
    }
    MintBase &operator*=(const MintBase &rhs) {
        _x = 1LL * _x * rhs._x % M();
        return *this;
    }
    MintBase &operator+=(const MintBase &rhs) {
        _x = mod(_x + rhs._x);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        _x = mod(_x - rhs._x);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) { return *this *= rhs.inv(); }
    friend MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
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
    friend MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 v;
        is >> v;
        a = MintBase(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
};
// using Mint = MintBase<0>;
constexpr int Mod1 = 1e9 + 7, Mod2 = 1e9 + 9;
struct Hash {
    MintBase<Mod1> _x;
    MintBase<Mod2> _y;
    Hash() : _x(0), _y(0) {}
    Hash(int x, int y) : _x(x), _y(y) {}
    Hash(MintBase<Mod1> x, MintBase<Mod2> y) : _x(x), _y(y) {}
    std::pair<int, int> val() const { return {_x.val(), _y.val()}; }
    friend Hash operator+(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs._x + rhs._x, lhs._y + rhs._y);
    }
    friend Hash operator-(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs._x - rhs._x, lhs._y - rhs._y);
    }
    friend Hash operator*(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs._x * rhs._x, lhs._y * rhs._y);
    }
    friend bool operator==(const Hash &lhs, const Hash &rhs) {
        return lhs._x == rhs._x && lhs._y == rhs._y;
    }
};
Hash base(13331, 23333);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    n *= 2;
    std::string s;
    std::cin >> s;
    s = " " + s;
    std::vector<Hash> pw(n + 2), pref(n + 2), suff(n + 2);
    pw[0] = Hash(1, 1);
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * base;
        pref[i] = pref[i - 1] * base + Hash(s[i], s[i]);
    }
    for (int i = n; i >= 1; i--) {
        suff[i] = suff[i + 1] * base + Hash(s[i], s[i]);
    }
    for (int i = 0; i <= n / 2; i++) {
        Hash h1 = pref[i] * pw[n / 2 - i] + (pref[n] - pref[i + n / 2] * pw[n / 2 - i]);
        Hash h2 = suff[i + 1] - suff[i + 1 + n / 2] * pw[n / 2];
        if (h1 == h2) {
            std::string ans = s.substr(i + 1, n / 2);
            std::reverse(ans.begin(), ans.end());
            std::cout << ans << "\n" << i << "\n";
            return 0;
        }
    }

    std::cout << -1 << "\n";

    return 0;
}