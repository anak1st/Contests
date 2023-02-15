/**
 * @author: XiaFan
 * @date: 2023-02-14 20:01
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
    std::vector<int> a(n);

	// 以 i 结尾，差值为 j 的方案数
    std::vector dp(n + 1, std::vector<Mint>(n));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
    for (int t = 2; t <= n; t++) {
        std::vector tp(n + 1, std::vector<Mint>(n));
        for (int i = 1; i <= n; i++) {
			std::vector<Mint> sum(n);
			std::partial_sum(dp[i].begin(), dp[i].end(), sum.begin());
            for (int j = 1; j <= n; j++) {
                int d = std::abs(i - j);
                // if (t == 3)
				//     std::cerr << i << " " << d << " " << sum[d] << "\n";
                tp[j][d] += sum[d];
                for (int k = d + 1; k < n; k++) {
                    tp[j][k] += dp[i][k];
                }
            }
        }
        dp = tp;
    }

    auto get_ans = [&]() -> std::vector<Mint> {
        std::vector<Mint> ans(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j] += dp[i][j];
                // std::cout << dp[i][j] << " ";
            }
            // std::cout << "\n";
        }
        return ans;
    };
    auto ans = get_ans();
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}