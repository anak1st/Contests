/**
 * @author: XiaFan
 * @date: 01-07 22:12
 **/
#include <bits/stdc++.h>
using i64 = long long;

template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template <int P>
struct StaticMint {
    int x;
    StaticMint() : x(0) {}
    StaticMint(int x) : x(mod(x)) {}
    StaticMint(i64 x) : x(mod(x % P)) {}
    using Mint = StaticMint<P>;
    // assume -P <= x < 2P
    int mod(int x) {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    int val() const {
        return x;
    }
    Mint operator-() const {
        return Mint(mod(P - x));
    }
    Mint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    friend bool operator==(const Mint &lhs, const Mint &rhs) {
        return lhs.x == rhs.x;
    }
    Mint &operator*=(const Mint &rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = mod(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = mod(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        return *this *= rhs.inv();
    }
    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
};

constexpr int Mod1 = 1e9 + 7, Mod2 = 1e9 + 9;
struct Hash {
    StaticMint<Mod1> x;
    StaticMint<Mod2> y;
    Hash() : x(0), y(0) {}
    Hash(int _x, int _y) : x(_x), y(_y) {}
    Hash(StaticMint<Mod1> _x, StaticMint<Mod2> _y) : x(_x), y(_y) {}
    friend Hash operator+(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Hash operator-(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend Hash operator*(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x * rhs.x, lhs.y * rhs.y);
    }
    friend bool operator==(const Hash &lhs, const Hash &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
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