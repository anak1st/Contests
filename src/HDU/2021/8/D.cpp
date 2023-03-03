/**
 * @author: XiaFan
 * @date: 2023-02-25 10:29
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
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x)} {}
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

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    s = " " + s;
    std::vector<Hash> P(n + 1), H(n + 1);
    P[0] = Hash(1, 1);
    for (int i = 1; i <= n; i++) {
        P[i] = P[i - 1] * Base;
        H[i] = H[i - 1] * Base + Hash(s[i], s[i]);
    }
    auto getHash = [&](int l, int r) {
        return H[r] - H[l - 1] * P[r - l + 1];
    };

    int q;
    std::cin >> q;
    std::vector<std::pair<i64, i64>> Q(q);
    std::map<std::pair<i64, i64>, int> ans, last;
    for (auto &it : Q) {
        std::string t;
        std::cin >> t;
        int m = t.size();
        t = " " + t;
        std::vector<Hash> TH(m + 1);
        for (int i = 1; i <= m; i++) {
            TH[i] = TH[i - 1] * Base + Hash(t[i], t[i]);
        }
        it = TH[m].val();
        ans[it] = 0;
        last[it] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30 && i + j <= n; j++) {
            auto h = getHash(i, i + j);
            if (ans.count(h.val())) {
                if (last[h.val()] < i) {
                    last[h.val()] = i + j;
                    ans[h.val()]++;
                }
            }
        }
    }

    for (auto &it : Q) {
        std::cout << ans[it] << "\n";
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