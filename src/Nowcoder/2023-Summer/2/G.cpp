/**
 * @author: XiaFan
 * @date: 2023-09-06 20:15
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

constexpr i64 Mod1 = 1e9 + 7, Mod2 = 1e9 + 9;
struct Hash {
    MintBase<Mod1> m1;
    MintBase<Mod2> m2;
    Hash() : m1(0), m2(0) {}
    Hash(i64 x, i64 y) : m1(x), m2(y) {}
    Hash(MintBase<Mod1> x, MintBase<Mod2> y) : m1(x), m2(y) {}
    std::pair<i64, i64> val() const {
        return {m1.val(), m2.val()};
    }
    friend Hash operator+(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.m1 + rhs.m1, lhs.m2 + rhs.m2);
    }
    friend Hash operator-(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.m1 - rhs.m1, lhs.m2 - rhs.m2);
    }
    friend Hash operator*(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.m1 * rhs.m1, lhs.m2 * rhs.m2);
    }
    friend bool operator==(const Hash &lhs, const Hash &rhs) {
        return lhs.m1 == rhs.m1 && lhs.m2 == rhs.m2;
    }
} Base(13331, 23333);

std::vector<Hash> PW{Hash(1, 1)};
void init(int n) {
    if (n + 1 <= (int)PW.size()) {
        return;
    }
    int m = (int)PW.size() - 1;
    PW.resize(n + 1);
    for (int i = m + 1; i <= n; ++i) {
        PW[i] = PW[i - 1] * Base;
    }
}
std::vector<Hash> get(std::string s) {
    int n = (int)s.size();
    std::vector<Hash> res(n + 1);
    for (int i = 0; i < n; ++i) {
        res[i + 1] = res[i] * Base + Hash(s[i], s[i]);
    }
    return res;
}

std::string a = "bdpqnuosxz";
std::string b = "qpdbunosxz";
 
void solve() {
    std::string s;
    std::cin >> s;
     
    int n = s.size();
     
    for (auto c : s) {
        if (a.find(c) == -1) {
            std::cout << "No\n";
            return;
        }
    }
     
    auto t = s;
    for (int i = n - 1; i >= 0; i--) {
        int x = a.find(s[i]);
        t += b[x];
    }
     
    std::vector<Hash> pw(n + 1);
    pw[0] = Hash(1, 1);
    for (int i = 0; i < n; i++) {
        pw[i + 1] = pw[i] * Base;
    }
     
    std::vector<Hash> h(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
        h[i + 1] = h[i] * Base + Hash(t[i], t[i]);
    }
     
    auto get = [&](int l, int r) {
        return h[r] - h[l] * pw[r - l];
    };
     
    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (get(l, i) == get(2 * n - i, 2 * n - l)) {
            l = i;
        }
    }
     
    if (l == n) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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