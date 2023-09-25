/**
 * @author: XiaFan
 * @date: 2023-09-16 22:26
 */
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
T power(T a, int b) {
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
        // x %= P;
        if (x >= P) x -= P;
        if (x < 0) x += P;
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x)} {}
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
constexpr int P = 998244353;
using Mint = MintBase<P>;

constexpr int N = 10 + 26 + 26;
Mint dp[8][N];
Mint pr[8][N];
Mint nx[8][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::string t;
    std::vector<int> id(300);
    std::vector<int> mp(300);
    for (int i = 0; i < 10; i++) {
        t += char(i + '0');
        id[t.back()] = t.length() - 1;
        mp[t.back()] = 0b001;
    }
    for (int i = 0; i < 26; i++) {
        t += char(i + 'a');
        id[t.back()] = t.length() - 1;
        mp[t.back()] = 0b010;
    }
    for (int i = 0; i < 26; i++) {
        t += char(i + 'A');
        id[t.back()] = t.length() - 1;
        mp[t.back()] = 0b100;
    }

    const int N = 10 + 26 + 26;
    // std::vector<std::vector<Mint>> dp(8, std::vector<Mint>(N));

    if (s[0] == '?') {
        for (int k = 0; k < N; k++) {
            dp[mp[t[k]]][k] = 1;
        }
    } else if (islower(s[0])) {
        dp[0b010][id[s[0]]] = 1;
        dp[0b100][id[toupper(s[0])]] = 1;
    } else {
        dp[mp[s[0]]][id[s[0]]] = 1;
    }

    // std::vector<std::vector<Mint>> pr(8, std::vector<Mint>(N));
    // std::vector<std::vector<Mint>> nx(8, std::vector<Mint>(N));

    for (int i = 1; i < n; i++) {
        for (int l = 0; l < 8; l++) {
            if (s[i] == '?') {
                for (int j = 0; j < N; j++) {
                    pr[l | 0b001][0] += dp[l][j];
                    pr[l | 0b001][10] -= dp[l][j];

                    pr[l | 0b010][10] += dp[l][j];
                    pr[l | 0b010][10 + 26] -= dp[l][j];

                    pr[l | 0b100][10 + 26] += dp[l][j];
                    // pr[l | 0b100][10 + 26 + 26] -= dp[l][j];

                    pr[l | mp[t[j]]][j] -= dp[l][j];
                    if (j + 1 < N) pr[l | mp[t[j]]][j + 1] += dp[l][j];
                }
                for (int j = 0; j < N; j++) {
                    if (j) pr[l][j] += pr[l][j - 1];
                    dp[l][j] = pr[l][j];
                }

                for (int j = 0; j < N; j++) {
                    pr[l][j] = 0;
                }
            } else {
                if (islower(s[i])) {
                    for (int j = 0; j < N; j++) {
                        int K = id[s[i]];
                        if (j != K) {
                            nx[l | 0b010][K] += dp[l][j];
                        }
                        K = id[toupper(s[i])];
                        if (j != K) {
                            nx[l | 0b100][K] += dp[l][j];
                        }
                    }
                } else {
                    for (int j = 0; j < N; j++) {
                        int K = id[s[i]];
                        if (j != K) {
                            nx[l | mp[s[i]]][K] += dp[l][j];
                        }
                    }
                }

                for (int j = 0; j < N; j++) {
                    dp[l][j] = nx[l][j];
                }
                for (int j = 0; j < N; j++) {
                    nx[l][j] = 0;
                }
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     std::cerr << dp[0b111][i] << " ";
    // }

    Mint ans = std::accumulate(dp[0b111], dp[0b111] + N, Mint(0));
    std::cout << ans << "\n";

    return 0;
}