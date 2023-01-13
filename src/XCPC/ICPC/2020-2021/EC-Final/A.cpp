/**
 * @author: XiaFan
 * @date: 2023-01-10 11:00
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int P = 998244353;
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
    MintBase &operator++() { return *this += 1; }
    MintBase &operator--() { return *this -= 1; }
    MintBase operator++(int) {
        MintBase res = *this;
        *this += 1;
        return res;
    }
    MintBase operator--(int) {
        MintBase res = *this;
        *this -= 1;
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
using Mint = MintBase<0>;

constexpr int N = 62;
int ctoi(char x) {
    if (x >= 'a' && x <= 'z') {
        return x - 'a';
    } else if (x >= 'A' && x <= 'Z') {
        return x - 'A' + 26;
    } else {
        return x - '0' + 26 * 2;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string t;
    std::cin >> t;
    int n = t.length();
    std::vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = ctoi(t[i - 1]);
        assert(s[i] >= 0 && s[i] < N);
    }

    /// ABCDCD
    std::vector<Mint> dp1(n + 1);                 // dp[i], after i, number of s[i]
    std::vector<Mint> sum1(N);                    // dynamic number of D
    std::vector dp2(n + 1, std::vector<Mint>(N)); // dp[i][D] after i, number of s[i]_D
    std::vector sum2(N, std::vector<Mint>(N));    // dynamic number of CD
    auto dp3 = dp2;               // dp[i][C], after i, number of s[i]_C_s[i]
    auto sum3 = sum2;             // dynamic number of DCD
    auto dp4 = dp2;               // dp[i][D], after i, number of s[i]_D_s[i]_D
    std::vector<int> last(N, -1); // last position of char i

    for (int i = n; i >= 1; i--) {
        int now = s[i]; // char
        for (int ch = 0; ch < N; ch++) {
            if (now == ch) continue;
            int next = last[ch]; // last char ch's position
            if (next == -1) continue;
            dp2[i][ch] = sum2[now][ch] + dp1[next];
            dp3[i][ch] = sum3[now][ch] + dp2[next][now];
            dp4[i][ch] = dp3[next][now];
        }

        sum1[now]++;
        dp1[i] = sum1[now];
        for (int ch = 0; ch < N; ch++) {
            if (now == ch) continue;
            sum2[now][ch] = dp2[i][ch];
            sum3[now][ch] = dp3[i][ch];
        }
        last[now] = i;
    }

    Mint ans = 0;
    Mint res = 0; // cnt of XX
    std::vector<i64> cnt(N);
    auto C2 = [](i64 x) -> i64 { return 1LL * x * (x - 1) / 2; };
    for (int i = 1; i <= n; i++) {
        int now = s[i]; // char
        for (int ch = 0; ch < N; ch++) {
            if (ch == now || i < 3) continue;
            // ? ? [now] [ch] [now] [ch]
            int num = i - 1;
            i64 illegal = 1LL * cnt[now] * (num - cnt[now]) 
                        + 1LL * cnt[ch ] * (num - cnt[ch ]) 
                        - 1LL * cnt[now] * cnt[ch];
            Mint pre = C2(num) - res - illegal;
            Mint suf = dp4[i][ch];
            ans += pre * suf;
        }
        res += cnt[now];
        cnt[now]++;
    }

    std::cout << ans << "\n";

    return 0;
}