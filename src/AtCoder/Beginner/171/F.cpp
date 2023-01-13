/**
 * @author: XiaFan
 * @date: 2023-01-08 20:32
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
    int v;
    int M() const {
        if (Mod <= 0) return P;
        else return Mod;
    }
    // assume -M <= __x < 2 M
    int mod(int x) const {
        if (x >= P) x -= M();
        else if (x < 0) x += M();
        return x;
    }
    MintBase() : v(0) {}
    MintBase(int x) : v(mod(x)) {}
    MintBase(i64 x) : v(mod(x % M())) {}
    int val() const { return v; }
    MintBase operator-() const { return MintBase(mod(M() - v)); }
    MintBase inv() const {
        assert(v != 0);
        return power(*this, M() - 2);
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = 1LL * v * rhs.v % M();
        return *this;
    }
    MintBase &operator+=(const MintBase &rhs) {
        v = mod(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = mod(v - rhs.v);
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
        i64 x;
        is >> x;
        a = MintBase(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
};
constexpr int Mod = 1e9 + 7;
using Mint = MintBase<Mod>;
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	init(2e6);
	int k;
	std::cin >> k;
	std::string s;
	std::cin >> s;
	int n = s.size();
	Mint ans = 0;
	for (int i = n; i <= n + k; i++) {
		ans += C(i - 1, n - 1) * power(Mint(25), i - n) * power(Mint(26), n + k - i);
	}
	std::cout << ans;

	return 0;
}